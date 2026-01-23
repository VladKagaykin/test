// БАЗА

// #include<iostream>
// #include <cmath>
// #include <iterator>
// #include <ctime>
// using namespace std;
// int x = 196;
// int y = 52;
// char gradient[] = {'@','#','8','&','o',':','*','-','.'};
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
//     circle(y/2,y/2,y/2, 0,0);
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
    
// ЛОКАЛЬ

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

// ТРИ ДЭ

// #include<iostream>
// #include <cmath>
// #include <iterator>
// #include <clocale>
// #include <cwchar>

// using namespace std;

// int x = 196;
// int y = 52;
// int z = y;
// int l_x = y/2+10;
// int l_y = y;
// int l_z = y/2+10;

// wchar_t gradient[] = {L'█',L'▓',L'▒',L'░',L'#',L'=',L'+',L'*',L'~',L'-',L'.'};
// int gradient_size = sizeof(gradient)/sizeof(wchar_t);
// wchar_t*** buffer = nullptr;

// void init_buffer() {
//     buffer = new wchar_t**[y];
//     for (int i = 0; i < y; i++) {
//         buffer[i] = new wchar_t*[x];
//         for (int j = 0; j < x; j++) {
//             buffer[i][j] = new wchar_t[z];
//             for (int l = 0; l < z; l++) {
//                 if(i==0){
//                     int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/gradient_size;
//                     if (index > gradient_size-1) index=gradient_size-1;
//                     buffer[i][j][l] = gradient[index];
//                 }else{
//                     buffer[i][j][l] = L' ';
//                 }
//             }
//         }
//     }
// }
// void print_buffer(int mode = 0) {
//     // mode: 0 - вид сверху, 1 - вид справа, 2 - вид спереди
    
//     if (mode == 0) { // Вид сверху (XZ плоскость)
//         // Для каждой точки (j,l) ищем ближайший к камере непустой символ по оси Y
//         // Камера сверху, поэтому ищем от самого верхнего (y=y-1) до самого нижнего (y=0)
//         for (int l = z-1; l >= 0; l--) {
//             for (int j = 0; j < x; j++) {
//                 wchar_t pixel = L' ';
//                 // Ищем от верхнего (y-1) до нижнего (0)
//                 for (int i = y-1; i >= 0; i--) {
//                     if (buffer[i][j][l] != L' ') {
//                         pixel = buffer[i][j][l];
//                         break; // Берем первый непустой символ (ближайший к камере сверху)
//                     }
//                 }
//                 wcout << pixel;
//             }
//             wcout << endl;
//         }
//     }
//     else if (mode == 1) { // Вид справа (YZ плоскость)
//         // Для каждой точки (i,l) ищем ближайший к камере непустой символ по оси X
//         for (int i = y-1; i >= 0; i--) {
//             // Отзеркаливаем по горизонтали: выводим l от 0 до z-1 (вместо z-1 до 0)
//             for (int l = 0; l < z; l++) {
//                 wchar_t pixel = L' ';
//                 // Ищем от ближайшего к камере (x=0) до дальнего (x=x-1)
//                 // Но для вида справа нам нужны объекты с большими X (правые)
//                 for (int j = x-1; j >= 0; j--) {
//                     if (buffer[i][j][l] != L' ') {
//                         pixel = buffer[i][j][l];
//                         break; // Берем первый непустой символ (ближайший к камере справа)
//                     }
//                 }
//                 wcout << pixel;
//             }
//             wcout << endl;
//         }
//     }
//     else if (mode == 2) { // Вид спереди (XY плоскость)
//         // Для каждой точки (i,j) ищем ближайший к камере непустой символ по оси Z
//         for (int i = y-1; i >= 0; i--) {
//             for (int j = 0; j < x; j++) {
//                 wchar_t pixel = L' ';
//                 // Ищем от ближайшего к камере (z=0) до дальнего (z=z-1)
//                 for (int l = 0; l < z; l++) {
//                     if (buffer[i][j][l] != L' ') {
//                         pixel = buffer[i][j][l];
//                         break; // Берем первый непустой символ (ближайший к камере)
//                     }
//                 }
//                 wcout << pixel;
//             }
//             wcout << endl;
//         }
//     }
// }
// void release_buffer() {
//     for (int i = 0; i < y; i++) {
//         for (int j = 0; j < x; j++) {
//             delete[] buffer[i][j];
//         }
//         delete[] buffer[i];
//     }
//     delete[] buffer;
// }
// void square(int t_x, int t_y, int t_z, int size){
//     for(int i=t_y;i<=t_y+size-1;i++){
//         for(int j=t_x;j<t_x+size;j++){
//             for (int l = t_z; l < t_z+size; l++) {
//                 int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/gradient_size;
//                 if (index > gradient_size-1) index=gradient_size-1;
//                 buffer[i][j][l] = gradient[index];
//             }
//         } 
//     }
//     int center_x = t_x + size/2;
//     int center_y = t_y + size/2;
//     int center_z = t_z + size/2;
//     int dx = center_x - l_x;
//     int dy = center_y - l_y;
//     int dz = center_z - l_z;

//     if (dy != 0) {
//         float t = -l_y / (float)dy;
//         int shadow_x = l_x + t * dx;
//         int shadow_z = l_z + t * dz;
        
//         int offset_x = shadow_x - center_x;
//         int offset_z = shadow_z - center_z;
        
//         for(int i=t_y;i<=t_y+size-1;i++){
//             for(int j=t_x;j<t_x+size;j++){
//                 for (int l = t_z; l < t_z+size; l++) {
//                     float t_point = (0 - l_y) / (float)(i - l_y);
//                     int shadow_point_x = l_x + t_point * (j - l_x);
//                     int shadow_point_z = l_z + t_point * (l - l_z);
                    
//                     if (shadow_point_x >= 0 && shadow_point_x < x && 
//                         shadow_point_z >= 0 && shadow_point_z < z) {
//                         buffer[0][shadow_point_x][shadow_point_z] = 'S';
//                     }
//                 }
//             } 
//         }
//     }
// }

// void circle(int t_x, int t_y, int t_z, int size){
//     int radius=size/2;
//     int center_x=t_x+radius;
//     int center_y=t_y+radius;
//     int center_z=t_z+radius;
    
//     for(int i=t_y; i<=t_y+size-1; i++){
//         for(int j=t_x; j<=t_x+size-1; j++){
//             for (int l = t_z; l <= t_z+size-1; l++) {
//                 int dx=j-center_x;
//                 int dy=i-center_y;
//                 int dz=l-center_z;
//                 if(dx*dx+dy*dy+dz*dz<=radius*radius){
//                     int index=sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/gradient_size;
//                     if (index > gradient_size-1) index=gradient_size-1;
//                     buffer[i][j][l] = gradient[index];
//                 }
//             }
//         } 
//     }
    
//     for(int i=t_y; i<=t_y+size-1; i++){
//         for(int j=t_x; j<=t_x+size-1; j++){
//             for (int l = t_z; l <= t_z+size-1; l++) {
//                 int dx=j-center_x;
//                 int dy=i-center_y;
//                 int dz=l-center_z;
//                 if(dx*dx+dy*dy+dz*dz<=radius*radius){
//                     if (i != l_y) {  
//                         float t = (0 - l_y) / (float)(i - l_y);
//                         int shadow_x = l_x + t * (j - l_x);
//                         int shadow_z = l_z + t * (l - l_z);
                        
//                         if (shadow_x >= 0 && shadow_x < x && 
//                             shadow_z >= 0 && shadow_z < z) {
//                             buffer[0][shadow_x][shadow_z] = 'S';
//                         }
//                     }
//                 }
//             }
//         } 
//     }
// }

// int main(){
//     setlocale(LC_ALL, "");
//     init_buffer();
//     square(0,10,0,10);
//     square(0,0,0,5);
//     circle(20,15,20,12); 
    
//     wcout << L"Вид сверху:" << endl;
//     print_buffer(0);
    
//     wcout << L"\nВид справа:" << endl;
//     print_buffer(1);
    
//     wcout << L"\nВид спереди:" << endl;
//     print_buffer(2);
    
//     release_buffer();
//     return 0;
// }

// УПРОЩЕНИЕ

#include<iostream>
#include <cmath>
#include <iterator>
#include <clocale>
#include <cwchar>

using namespace std;

int x = 196;
int y = 54;
int z = y;
int l_x = 25;
int l_y = y;
int l_z = 25;

wchar_t gradient[] = {L'█',L'▓',L'▒',L'░',L'#',L'=',L'+',L'*',L'~',L'-',L'.'};
int gradient_size = sizeof(gradient)/sizeof(wchar_t);
int shader = sqrt(pow(x,2)+pow(z,2))/gradient_size;
wchar_t*** buffer = nullptr;

void init_buffer() {
    buffer = new wchar_t**[y];
    for (int i = 0; i < y; i++) {
        buffer[i] = new wchar_t*[x];
        for (int j = 0; j < x; j++) {
            buffer[i][j] = new wchar_t[z];
            for (int l = 0; l < z; l++) {
                if(i==0){
                    int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/shader;
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
    // mode:0-вид сверху, 1-вид справа, 2-вид спереди
    
    if (mode == 0) { // XZ
        for (int l = z-1; l >= 0; l--) {
            for (int j = 0; j < x; j++) {
                wchar_t pixel = L' ';
                for (int i = y-1; i >= 0; i--) {
                    if (buffer[i][j][l] != L' ') {
                        pixel = buffer[i][j][l];
                        break;
                    }
                }
                wcout << pixel;
            }
            wcout << endl;
        }
    }
    else if (mode == 1) { // YZ
        for (int i = y-1; i >= 0; i--) {
            for (int l = 0; l < z; l++) {
                wchar_t pixel = L' ';
                for (int j = x-1; j >= 0; j--) {
                    if (buffer[i][j][l] != L' ') {
                        pixel = buffer[i][j][l];
                        break;
                    }
                }
                wcout << pixel;
            }
            wcout << endl;
        }
    }
    else if (mode == 2) { // XY
        for (int i = y-1; i >= 0; i--) {
            for (int j = 0; j < x; j++) {
                wchar_t pixel = L' ';
                for (int l = 0; l < z; l++) {
                    if (buffer[i][j][l] != L' ') {
                        pixel = buffer[i][j][l];
                        break;
                    }
                }
                wcout << pixel;
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
void square(int t_x, int t_y, int t_z, int size){
    for(int i=t_y;i<=t_y+size-1;i++){
        if(i>y or i<0) continue;
        for(int j=t_x;j<t_x+size;j++){
            if(j>x or j<0) continue;
            for (int l = t_z; l < t_z+size; l++) {
                if(l>z or l<0) continue;
                int index = sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/shader;
                if (index > gradient_size-1) index=gradient_size-1;
                buffer[i][j][l] = gradient[index];
            }
        } 
    }
    int center_x = t_x + size/2;
    int center_y = t_y + size/2;
    int center_z = t_z + size/2;
    int dx = center_x - l_x;
    int dy = center_y - l_y;
    int dz = center_z - l_z;

    if (dy != 0) {
        float t = -l_y / (float)dy;
        int shadow_x = l_x + t * dx;
        int shadow_z = l_z + t * dz;
        
        int offset_x = shadow_x - center_x;
        int offset_z = shadow_z - center_z;
        
        for(int i=t_y;i<=t_y+size-1;i++){
            for(int j=t_x;j<t_x+size;j++){
                for (int l = t_z; l < t_z+size; l++) {
                    float t_point = (0 - l_y) / (float)(i - l_y);
                    int shadow_point_x = l_x + t_point * (j - l_x);
                    int shadow_point_z = l_z + t_point * (l - l_z);
                    
                    if (shadow_point_x >= 0 && shadow_point_x < x && 
                        shadow_point_z >= 0 && shadow_point_z < z) {
                        buffer[0][shadow_point_x][shadow_point_z] = gradient[gradient_size-1];
                    }
                }
            } 
        }
    }
}

void circle(int t_x, int t_y, int t_z, int size){
    int radius=size/2;
    int center_x=t_x+radius;
    int center_y=t_y+radius;
    int center_z=t_z+radius;
    
    for(int i=t_y; i<=t_y+size-1; i++){
        for(int j=t_x; j<=t_x+size-1; j++){
            for (int l = t_z; l <= t_z+size-1; l++) {
                int dx=j-center_x;
                int dy=i-center_y;
                int dz=l-center_z;
                if(dx*dx+dy*dy+dz*dz<=radius*radius){
                    int index=sqrt(pow((j-l_x),2)+pow((i-l_y),2)+pow((l-l_z),2))/shader;
                    if (index > gradient_size-1) index=gradient_size-1;
                    buffer[i][j][l] = gradient[index];
                }
            }
        } 
    }
    
    for(int i=t_y; i<=t_y+size-1; i++){
        for(int j=t_x; j<=t_x+size-1; j++){
            for (int l = t_z; l <= t_z+size-1; l++) {
                int dx=j-center_x;
                int dy=i-center_y;
                int dz=l-center_z;
                if(dx*dx+dy*dy+dz*dz<=radius*radius){
                    if (i != l_y) {  
                        float t = (0 - l_y) / (float)(i - l_y);
                        int shadow_x = l_x + t * (j - l_x);
                        int shadow_z = l_z + t * (l - l_z);
                        
                        if (shadow_x >= 0 && shadow_x < x && 
                            shadow_z >= 0 && shadow_z < z) {
                            buffer[0][shadow_x][shadow_z] = gradient[gradient_size-1];
                        }
                    }
                }
            }
        } 
    }
}

int main(){
    setlocale(LC_ALL, "");
    init_buffer();
    square(-1,10,0,10);
    square(0,0,0,5);
    circle(20,15,20,12); 
    
    wcout << L"Вид сверху:" << endl;
    print_buffer(0);
    
    wcout << L"\nВид справа:" << endl;
    print_buffer(1);
    
    wcout << L"\nВид спереди:" << endl;
    print_buffer(2);
    
    release_buffer();
    return 0;
}