#include <iostream>

using namespace std;

int factorial(int n){
    int f =1;
    for(int i=1;i<=n;i++){
        f *= i;
    }
    return f;
}

bool is_prime(int num){
    bool p=0;
    for(int i=2;i<=9;i++){
        if (num % i ==0 ){
            p=1;
        } 
    }
    return p;
}

int gcd(int a, int b) {
    if (a < 1 || a > 1000000000 || b < 1 || b > 1000000000) {
        // Вместо исключения возвращаем -1 как признак ошибки
        return -1;
    }
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Вспомогательная функция для вычисления модуля числа
int abs_int(int x) {
    return (x < 0) ? -x : x;
}

// Функция вычисления наименьшего общего кратного
int lcm(int a, int b) {
    // Специальный случай: оба числа равны 0
    if (a == 0 && b == 0) {
        return 0;
    }
    
    // Вычисляем НОД с помощью алгоритма Евклида
    int abs_a = abs_int(a);
    int abs_b = abs_int(b);
    
    int temp_a = abs_a;
    int temp_b = abs_b;
    while (temp_b != 0) {
        int temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    int gcd_value = temp_a;
    
    // Проверка деления на ноль
    if (gcd_value == 0) {
        return 0;
    }
    
    // Проверка на переполнение перед умножением
    // Проверяем, не будет ли переполнения при умножении
    if (abs_a > 2147483647 / abs_b) { // 2147483647 = INT_MAX
        // В случае возможного переполнения возвращаем -1
        return -1;
    }
    
    // Вычисляем НОК по формуле: |a * b| / НОД(|a|, |b|)
    int result = (abs_a / gcd_value) * abs_b;
    return result;
}

int main() {
    factorial(5);
    is_prime(17);
    return 0;
}