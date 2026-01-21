// БАЗА

// #include<iostream>
// #include <cmath>
// #include <iterator>
// #include <ctime>
// using namespace std;
// int x = 196;
// int y = 52;
// char gradient[] = {'@','#','8','&','o',':','*','-','.'};
// char** matrix[];
// void square(int t_x, int t_y, int size, int l_x, int l_y){
//     for(int i=y;i>0;i--){
//         for(int j=0;j<x;j++){
//             if(j>=t_x and j<=(t_x+size) and i>=t_y and i<=(t_y+size)){
//                 int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2))/(((int)sizeof(gradient)/2));
//                 if (index > (int)sizeof(gradient)-1){
//                     index=(int)sizeof(gradient)-1;
//                 }
//                 cout<<gradient[index];
//                 // cout<<index<<" ";
//             }else{
//                 cout<<" "; 
//             } 
//          } 
//         cout<<endl; 
//     }
// }

// void circle(int t_x, int t_y, int size, int l_x, int l_y){
//     for(int i=y;i>0;i--){
//         for(int j=0;j<x;j++){
//             if(pow(size,2)>=pow((j-t_x),2)+pow((i-t_y),2)){
//                 int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2))/(((int)sizeof(gradient)/2));
//                 if (index > (int)sizeof(gradient)-1){
//                     index=(int)sizeof(gradient)-1;
//                 }
//                 cout<<gradient[index];
//                 // cout<<index<<" ";
//             }else{
//                 cout<<" "; 
//             } 
//          } 
//         cout<<endl; 
//     }
// }

// int main(){
//     circle(y/2,y/2,y/2, y/2,y/2);
//     return 0;
// }
    
// ДОБАВЛЕНИЕ БУФЕРА

// #include<iostream>
// #include <cmath>
// #include <iterator>
// using namespace std;
// int x = 196;
// int y = 52;
// char gradient[] = {'@','#','8','&','o',':','*','-','.'};
// int gradient_size = sizeof(gradient);
// char** buffer = nullptr;
// void init_buffer() {
//     buffer = new char* [y];
//     for (int i = 0; i < y; i++) {
//         buffer[i] = new char[x];
//         for (int j = 0; j < x; j++) {
//             buffer[i][j] = ' ';
//         }
//     }
// }
// void print_buffer() {
//     for (int i = 0; i < y; i++) {
//         for (int j = 0; j < x; j++) {
//             cout << buffer[i][j];
//         }
//         cout << endl;
//     }
// }
// void release_buffer() {
//     for (int i = 0; i < y; i++) {
//         delete[] buffer[i];
//     }
//     delete[] buffer;
// }
// void square(int t_x, int t_y, int size, int l_x, int l_y){
//     for(int i=t_y+size-1;i>=t_y;i--){
//         for(int j=t_x;j<t_x+size;j++){
//             int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2))/((gradient_size/2));
//             if (index > gradient_size-1) index=gradient_size-1;
            
//             // cout<<index<<" ";
            
//             buffer[i][j]=gradient[index];
//          } 
//     }
// }
// void circle(int t_x, int t_y, int size, int l_x, int l_y){
//     int radius=size/2;
//     int center_x=t_x+radius;
//     int center_y=t_y+radius;
    
//     for(int i=t_y; i<t_y+size; i++){
//         for(int j=t_x; j<t_x+size; j++){
//             int dx=j-center_x;
//             int dy=i-center_y;
//             if(dx*dx+dy*dy<=radius*radius){
//                 int index=sqrt(pow((j-l_x),2)+pow((i-l_y),2))/(gradient_size/2);
//                 if (index > gradient_size-1) index=gradient_size-1;
//                 buffer[i][j] = gradient[index];
//             }
//         } 
//     }
// }
// int main(){
//     init_buffer();
//     square(10,0,5, 0,0);
//     square(0,0,5, 0,0);
//     circle(20,20,15, 25,25);
//     print_buffer();
//     release_buffer();
//     return 0;
// }
    


// #include<iostream>
// #include <cmath>
// #include <iterator>
// #include <clocale>
// #include <cwchar>

// using namespace std;

// int x = 196;
// int y = 52;
// wchar_t gradient[] = {L'█', L'▓', L'▒', L'░'};
// int gradient_size = sizeof(gradient)/sizeof(wchar_t);
// wchar_t** buffer = nullptr;

// void init_buffer() {
//     buffer = new wchar_t* [y];
//     for (int i = 0; i < y; i++) {
//         buffer[i] = new wchar_t[x];
//         for (int j = 0; j < x; j++) {
//             buffer[i][j] = L' ';
//         }
//     }
// }
// void print_buffer() {
//     for (int i = 0; i < y; i++) {
//         for (int j = 0; j < x; j++) {
//             wcout << buffer[i][j];
//         }
//         wcout << endl;
//     }
// }
// void release_buffer() {
//     for (int i = 0; i < y; i++) {
//         delete[] buffer[i];
//     }
//     delete[] buffer;
// }
// void square(int t_x, int t_y, int size, int l_x, int l_y){
//     for(int i=t_y;i<=t_y+size-1;i++){
//         for(int j=t_x;j<t_x+size;j++){
//             int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2))/gradient_size;
//             if (index > gradient_size-1) index=gradient_size-1;
            
//             // cout<<index<<" ";
            
//             buffer[i][j]=gradient[index];
//          } 
//     }
// }
// void circle(int t_x, int t_y, int size, int l_x, int l_y){
//     int radius=size/2;
//     int center_x=t_x+radius;
//     int center_y=t_y+radius;
    
//     for(int i=t_y; i<=t_y+size-1; i++){
//         for(int j=t_x; j<=t_x+size; j++){
//             int dx=j-center_x;
//             int dy=i-center_y;
//             if(dx*dx+dy*dy<=radius*radius){
//                 int index=sqrt(pow((j-l_x),2)+pow((i-l_y),2))/gradient_size;
//                 if (index > gradient_size-1) index=gradient_size-1;
//                 buffer[i][j] = gradient[index];
//             }
//         } 
//     }
// }
// int main(){
//     setlocale(LC_ALL, "");
//     init_buffer();
//     circle(0,0,y, y/2,y/2);
//     print_buffer();
//     release_buffer();
//     return 0;
// }


#include<iostream>
#include <cmath>
#include <iterator>
#include <clocale>
#include <cwchar>

using namespace std;

int x = 196;
int y = 52;
int z = y;
int l_x = 0;
int l_y = 0;
int l_z = 0;

wchar_t gradient[] = {L'█', L'▓', L'▒', L'░'};
int gradient_size = sizeof(gradient)/sizeof(wchar_t);
wchar_t*** buffer = nullptr;

void init_buffer() {
    buffer = new wchar_t**[y];
    for (int i = 0; i < y; i++) {
        buffer[i] = new wchar_t*[x];
        for (int j = 0; j < x; j++) {
            buffer[i][j] = new wchar_t[z];
            for (int l = 0; l < z; l++) {
                if(i==0){
                    int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/gradient_size;
                    if (index > gradient_size-1) index=gradient_size-1;
                    buffer[i][j][l] = gradient[index];
                }else{
                    buffer[i][j][l] = L' ';
                }
            }
        }
    }
}
void print_buffer(int mode = 0) {
    // mode: 0 - вид сверху, 1 - вид справа, 2 - вид спереди
    
    if (mode == 0) { // Вид сверху (XZ плоскость)
        // Берем первый слой по Y (i=0)
        for (int l = z-1; l >= 0; l--) {
            for (int j = 0; j < x; j++) {
                wcout << buffer[0][j][l];
            }
            wcout << endl;
        }
    }
    else if (mode == 1) { // Вид справа (YZ плоскость)
        // Берем последний слой по X (x-1)
        for (int i = y-1; i >= 0; i--) {
            for (int l = z-1; l >= 0; l--) {
                wcout << buffer[i][x-1][l];
            }
            wcout << endl;
        }
    }
    else if (mode == 2) { // Вид спереди (XY плоскость)
        // Берем последний слой по Z (z-1)
        for (int i = y-1; i >= 0; i--) {
            for (int j = 0; j < x; j++) {
                wcout << buffer[i][j][z-1];
            }
            wcout << endl;
        }
    }
}
void release_buffer() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            delete[] buffer[i][j];
        }
        delete[] buffer[i];
    }
    delete[] buffer;
}
// void square(int t_x, int t_y, int size){
//     for(int i=t_y;i<=t_y+size-1;i++){
//         for(int j=t_x;j<t_x+size;j++){
//             int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2))/gradient_size;
//             if (index > gradient_size-1) index=gradient_size-1;
            
//             // cout<<index<<" ";
            
//             buffer[i][j]=gradient[index];
//          } 
//     }
// }
// void circle(int t_x, int t_y, int size){
//     int radius=size/2;
//     int center_x=t_x+radius;
//     int center_y=t_y+radius;
    
//     for(int i=t_y; i<=t_y+size-1; i++){
//         for(int j=t_x; j<=t_x+size; j++){
//             int dx=j-center_x;
//             int dy=i-center_y;
//             if(dx*dx+dy*dy<=radius*radius){
//                 int index=sqrt(pow((j-l_x),2)+pow((i-l_y),2))/gradient_size;
//                 if (index > gradient_size-1) index=gradient_size-1;
//                 buffer[i][j] = gradient[index];
//             }
//         } 
//     }
// }
int main(){
    setlocale(LC_ALL, "");
    init_buffer();
    
    wcout << L"Вид сверху:" << endl;
    print_buffer(0);
    
    wcout << L"\nВид справа:" << endl;
    print_buffer(1);
    
    wcout << L"\nВид спереди:" << endl;
    print_buffer(2);
    
    release_buffer();
    return 0;
}