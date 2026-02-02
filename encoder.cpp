#include <opencv2/opencv.hpp>
#include<iostream>
#include<string>
#include <clocale>
#include <cwchar>
#include <iomanip>

using namespace cv;
using namespace std;

int window_image(string load_image) {
    Mat image = imread(load_image);
    if (image.empty()) {
        cout << "Unable to read image: " << load_image << endl;
        return -1;
    }

    int original_width = image.cols;
    int original_height = image.rows;

    for (int i = 0; i < original_height; i++) {
        for (int j = 0; j < original_width; j++) {
            Vec3b pixel = image.at<Vec3b>(i, j);

            cout << hex 
                << (int)pixel[2]   // R
                << (int)pixel[1]   // G
                << (int)pixel[0]   // B
                << " ";
        }
        cout << dec << endl; 
    }
    if(original_height>300 and original_width>300){
        namedWindow("Image", WINDOW_NORMAL);
        imshow("Image", image);
        return 0;
    }else{
        Mat resized_image;
        resize(image, resized_image, cv::Size(300, 300));
        imshow("Resized Image", resized_image);
        return 0;
    }
}

string text_to_hex(const string& text) {
    string result;
    for (unsigned char c : text) {
        char buffer[10];
        sprintf(buffer, "%02x", c);  
        result += buffer;
    }
    return result;
}

void encode_text_to_image(string image_path, string text) {
    Mat image = imread(image_path);
    if (image.empty()) {
        cout << "Unable to read image: " << image_path << endl;
        return;
    }

    string hex_text = text_to_hex(text);
    int original_width = image.cols;
    int original_height = image.rows;
    int total_pixels = image.rows * image.cols;
    int max_text_length = total_pixels * 3;
    
    if (hex_text.length() > max_text_length) {
        cout << "Text too long for this image!" << endl;
        return;
    }

    int idx = 0;
    for (int i = 0; i < original_height && idx < hex_text.length(); i++) {
        for (int j = 0; j < original_width && idx < hex_text.length(); j++) {
            Vec3b& pixel = image.at<Vec3b>(i, j);
            if (idx < hex_text.length()) pixel[2] = hex_text[idx++];
            if (idx < hex_text.length()) pixel[1] = hex_text[idx++];
            if (idx < hex_text.length()) pixel[0] = hex_text[idx++];
        }
    }
    imwrite(image_path, image);
    cout << image_path << " " << hex_text << endl;
}

string read_image(string load_image) {
    Mat image = imread(load_image);
    if (image.empty()) return "";

    string text = "";

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            text += (char)pixel[2]; // R
            text += (char)pixel[1]; // G
            text += (char)pixel[0]; // B
        }
    }
    return text;
}


int main(){
    setlocale(LC_ALL, "");
    // window_image("penza_low.png");
    // waitKey(0);
    // cout<<text_to_hex("test▓")<<endl;
    encode_text_to_image("penza_low_test.png","don`t talk to strangers");
    // window_image("penza_low_test.png");
    // waitKey(0);
    cout<<read_image("penza_low_test.png");
    return 0;
}