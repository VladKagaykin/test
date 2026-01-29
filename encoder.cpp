#include <opencv2/opencv.hpp>
#include<iostream>
#include<string>
#include <clocale>
#include <cwchar>
#include <sstream>

using namespace cv;
using namespace std;

int window_image(string load_image){
    Mat image = imread(load_image);
    int original_width = image.cols;
    int original_height = image.rows;
    for(int i=0;i<=original_height;i++){
        for(int j=0;j<=original_height;j++){
            Vec3b pixel = image.at<Vec3b>(i, j);
            cout<<pixel<<" ";
        }
        cout<<endl;
    }
    if (image.empty())
    {
        cout << "Unable to read image" << std::endl;
        return -1;
    }
    namedWindow("Image", WINDOW_NORMAL);
    imshow("Image", image);
    return 0;
}

string convert_hex(wstring text) {
    stringstream ss;
    ss << hex << setfill('0'); 
    for (unsigned char c : text) {
        ss << static_cast<int>(c) << " ";
    }
    return ss.str();
}

int main(){
    setlocale(LC_ALL, "");
    cout<<convert_hex(L"test █")<<endl;
    return 0;
}