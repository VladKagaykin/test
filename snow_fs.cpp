#include<iostream>
#include <cmath>
#include <iterator>

using namespace std;

char snowflakes[] = {' ','.',',','-','+','#'};
const int snowflake_size = sizeof(snowflakes)/sizeof(char);
int x = 70;
int y = 13;

int** buffer = nullptr;
int** dynamic_snow = nullptr;
void init_buffer() {
    buffer = new int* [y];
    dynamic_snow = new int* [y];
    for (int i = 0; i < y; i++) {
        buffer[i] = new int[x];
        dynamic_snow[i] = new int[x];
        for (int j = 0; j < x; j++) {
            buffer[i][j] = 1;
            dynamic_snow[i][j] = 0;
        }
    }
}

void print_buffer() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cout << snowflakes[buffer[i][j]];
        }
        cout << endl;
    }
}

void release_buffer() {
    for (int i = 0; i < y; i++) {
        delete[] buffer[i];
        delete[] dynamic_snow[i];
    }
    delete[] buffer;
    delete[] dynamic_snow;
}

int main(){
    init_buffer();
    print_buffer();
    release_buffer();
    return 0;
}
