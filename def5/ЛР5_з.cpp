#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
float average_value(int size, int mass) {
    float sum = 0;
    for (int i = 0; i != size; i++) {
        sum += mass[i];
    }
    return(sum / size);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int size_1, size_2;
    cout << "Введите размерность массива 1: ";
    cin >> size_1;
    cout << "Введите размерность массива 2: ";
    cin >> size_2;
    int sum_1 = 0, sum_2 = 0;
    int* mass_1 = new int [size_1];
    int* mass_2 = new int [size_2];
    srand(time(0));
    cout << "Массив 1: ";
    for (int i = 0; i < size_1; i++) {
        mass_1[i] = rand() % 10 - 5;
        cout << setw(3) << mass_1[i];
    }
    cout << endl << "Среднее значение по массиву 1: " << average_value(size_1, mass_1) << endl;
    cout << "Массив 2: ";
    for (int j = 0; j < size_2; j++) {
        mass_2[j] = rand() % 10 - 5;
        cout << setw(3) << mass_2[j];
    }
    cout << endl << "Среднее значение по массиву 2: " << average_value(size_2, mass_2) << endl;
    delete[] mass_1;
    delete[] mass_2;
}
