#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
#include<clocale>
#include<cwchar>
#include<iomanip>

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
            cout<< hex
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
    int original_width = image.cols;
    int original_height = image.rows;
    int total_pixels = original_width * original_height;
    int max_text_length = total_pixels * 3;
    if ((int)text.length() > max_text_length) {
        cout << "Text too long for this image!" << endl;
        return;
    }
    int idx = 0;
    for (int i = 0; i < original_height && idx < (int)text.length(); i++) {
        for (int j = 0; j < original_width && idx < (int)text.length(); j++) {
            Vec3b& pixel = image.at<Vec3b>(i, j);
            
            if (idx < (int)text.length()) pixel[2] = text[idx++];
            if (idx < (int)text.length()) pixel[1] = text[idx++];
            if (idx < (int)text.length()) pixel[0] = text[idx++];
        }
    }
    imwrite(image_path, image);
}

string read_image(string load_image) {
    Mat image = imread(load_image);
    if (image.empty()) return "";
    string text = "";
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            
            text += (char)pixel[2]; 
            text += (char)pixel[1]; 
            text += (char)pixel[0]; 
        }
    }
    return text;
}

void create_void_image(string encode_text, string img_name, int height, int width){
    Mat img(height, width, CV_8UC4, Scalar(0, 0, 0, 0));
    imwrite(img_name, img);
    encode_text_to_image(img_name,encode_text);
}

int main(){
    // string text;
    // getline(cin,text);
    // setlocale(LC_ALL, "");
    // create_void_image(text,"programm.png",64,64);
    window_image("penza_low.png");
    cout<<read_image("penza_low.png")<<endl;
    waitKey(0);
    return 0;
}