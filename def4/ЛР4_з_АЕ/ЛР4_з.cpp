#include <iostream>
#include <locale>
#include <ctime>    

using namespace std;

int main() {
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* mass = new int[size];
    for (int i = 0; i < size; i++) {
        mass[i] = rand() % 10;
    }
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
    int* chastota = new int[size];
    for (int i = 0; i < size; i++) {
        chastota[mass[i]]++;
    }
    int maxchastota = 0;
    for (int i = 0; i < 100; i++) {
        if (chastota[i] > maxchastota) {
            maxchastota = chastota[i];
        }
    }
    if (maxchastota == 1) {
        cout << "таких чисел нет";
    }
    else {
        cout << "Числа, которые встречаются максимальное количество раз (" << maxchastota << "): ";
        for (int i = 0; i < 100; i++) {
            if (chastota[i] == maxchastota) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    delete[] mass;
    system("pause");
}