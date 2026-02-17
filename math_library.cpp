#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
namespace fs = filesystem;
using namespace fs;
using namespace cv;

char getNextChar(char current, char target, float progress) {
    if (current == target) {
        return target;
    }
    
    if (current == ' ' || target == ' ') {
        if (progress >= 0.5f) {
            return target;
        } else {
            return current;
        }
    }
    
    if (current < target) {
        int range = target - current;
        int step = static_cast<int>(progress * range);
        return current + step;
    } else {
        int range = current - target;
        int step = static_cast<int>(progress * range);
        return current - step;
    }
}

void createTextTransitionVideo(const string& startText, const string& endText, int scalePercent, int fps = 30, int durationSeconds = 5) {
    string tempDir = "temp_frames";
    if (!exists(tempDir)) {
        create_directory(tempDir);
    } else {
        for (const auto& entry : directory_iterator(tempDir)) {
            remove(entry.path());
        }
    }
    
    int baseWidth = 1920;
    int baseHeight = 1080;
    
    int frameWidth = baseWidth * scalePercent / 100;
    int frameHeight = baseHeight * scalePercent / 100;
    
    if (frameWidth % 2 != 0) frameWidth--;
    if (frameHeight % 2 != 0) frameHeight--;
    
    double baseFontScale = 2.0;
    double fontScale = baseFontScale * max(scalePercent, 50) / 100.0;
    
    if (fontScale < 0.8) fontScale = 0.8;
    
    int totalFrames = fps * durationSeconds;
    
    Scalar textColor(255, 255, 255);
    Scalar bgColor(0, 0, 0);
    int fontFace = FONT_HERSHEY_SIMPLEX;
    int thickness = 3;
    
    size_t maxLength = max(startText.length(), endText.length());
    
    string startPadded = startText;
    string endPadded = endText;
    startPadded.resize(maxLength, ' ');
    endPadded.resize(maxLength, ' ');
    
    for (int frameNum = 0; frameNum < totalFrames; frameNum++) {
        Mat frame(frameHeight, frameWidth, CV_8UC3, bgColor);
        
        float progress = static_cast<float>(frameNum) / (totalFrames - 1);
        
        string intermediateText;
        
        for (size_t i = 0; i < maxLength; i++) {
            char startChar = startPadded[i];
            char endChar = endPadded[i];
            
            float letterProgress = 0.0f;
            
            if (progress < 0.2f) {
                letterProgress = 0.0f;
            } else if (progress > 0.8f) {
                letterProgress = 1.0f;
            } else {
                float wavePos = (progress - 0.2f) / 0.6f;
                float letterDelay = static_cast<float>(i) / maxLength * 0.7f;
                
                if (wavePos < letterDelay) {
                    letterProgress = 0.0f;
                } else if (wavePos > letterDelay + 0.3f) {
                    letterProgress = 1.0f;
                } else {
                    letterProgress = (wavePos - letterDelay) / 0.3f;
                }
            }
            
            char intermediateChar = getNextChar(startChar, endChar, letterProgress);
            intermediateText += intermediateChar;
        }
        
        size_t lastNonSpace = intermediateText.find_last_not_of(' ');
        if (lastNonSpace != string::npos) {
            intermediateText = intermediateText.substr(0, lastNonSpace + 1);
        }
        
        int baseline = 0;
        Size textSize = getTextSize(intermediateText, fontFace, fontScale, thickness, &baseline);
        
        Point textOrg(
            (frame.cols - textSize.width) / 2,
            (frame.rows + textSize.height) / 2
        );
        
        putText(frame, intermediateText, textOrg, fontFace, fontScale, textColor, thickness);
        
        string progressText = to_string(static_cast<int>(progress * 100)) + "%";
        putText(frame, progressText, Point(frameWidth - 100, 40), 
                   fontFace, fontScale * 0.5, Scalar(150, 150, 150), 1);
        
        string frameInfo = "Кадр: " + to_string(frameNum + 1) + "/" + to_string(totalFrames);
        putText(frame, frameInfo, Point(20, 40), 
                   fontFace, fontScale * 0.4, Scalar(100, 100, 100), 1);
        
        string framePath = tempDir + "/frame_" + to_string(frameNum).insert(0, 6 - to_string(frameNum).length(), '0') + ".png";
        imwrite(framePath, frame);
        
    }

    cout << "Все кадры созданы. Создаем видео..." << endl;
    
    string outputVideo = "text_transition_" + to_string(scalePercent) + "percent.mp4";
    
    string ffmpegCommand = "ffmpeg -y -framerate " + to_string(fps) + 
                                " -i " + tempDir + "/frame_%06d.png" +
                                " -c:v libx264 -pix_fmt yuv420p " +
                                outputVideo;
    cout << "Выполняем команду: " << ffmpegCommand << endl;
    
    int result = system(ffmpegCommand.c_str());
    
    if (result == 0) {
        cout << "Видео успешно создано: " << outputVideo << endl;
        
        for (const auto& entry : directory_iterator(tempDir)) {
            remove(entry.path());
        }
        remove(tempDir);
        
        cout << "\nХотите воспроизвести видео? (y/n): ";
        char playChoice;
        cin >> playChoice;
        if (playChoice == 'y' || playChoice == 'Y') {
            string playCommand = "xdg-open " + outputVideo;
            system(playCommand.c_str());
        }
        
    } else {
        cerr << "Ошибка при создании видео!" << endl;
        cerr << "Убедитесь, что ffmpeg установлен и доступен." << endl;
        cerr << "Код ошибки: " << result << endl;
    }
}

int main() {
    string startText, endText;
    int scalePercent;
    int durationSeconds;
    
    cout << "=== Создание видео с перебором букв ===" << endl;
    cout << "Введите начальный текст: ";
    getline(cin, startText);
    
    cout << "Введите конечный текст: ";
    getline(cin, endText);
    
    cout << "Введите масштаб в процентах (рекомендуется 50-200): ";
    cin >> scalePercent;
    
    cout << "Введите длительность видео в секундах (по умолчанию 5): ";
    cin >> durationSeconds;
    
    // Очищаем буфер ввода
    cin.ignore();
    
    // Проверяем ввод
    if (startText.empty() || endText.empty()) {
        cerr << "Ошибка: тексты не могут быть пустыми!" << endl;
        return 1;
    }
    
    if (scalePercent < 10 || scalePercent > 500) {
        cout << "Предупреждение: масштаб " << scalePercent << "% может быть неоптимальным." << endl;
        cout << "Продолжить? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            return 0;
        }
    }
    
    if (durationSeconds < 1 || durationSeconds > 60) {
        durationSeconds = 5;
        cout << "Длительность установлена на " << durationSeconds << " секунд по умолчанию." << endl;
    }
    
    // Инициализация генератора случайных чисел (может пригодиться для эффектов)
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Создаем видео
    createTextTransitionVideo(startText, endText, scalePercent, 30, durationSeconds);
    
    return 0;
}