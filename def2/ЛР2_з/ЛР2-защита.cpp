#include <iostream>
#include <locale>
using namespace std;
int main() {
    float x, y, z;
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Введите координаты точки X Y Z: ";
    cin >> x >> y >> z;

    if (sqrt(pow(x - 3, 2) + pow(y - 3, 2) + pow(z - 3, 2)) <= 2) {
        if (sqrt(pow(x - y, 2) + pow(y - z, 2) + pow(z - x, 2)) <= 0.5) {
            cout << "Точка находится в зоне 3";
        }
        else {
            cout << "Точка находится в зоне 2";
        }
    }
    else {
        cout << "Точка находится в зоне 1";
    }
}