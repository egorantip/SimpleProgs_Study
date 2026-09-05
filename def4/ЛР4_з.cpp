#include <iostream>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    unsigned int n;
    cout << "Введите размер массива n: ";
    cin >> n;
    int M = 10;
    int* mas = new int[n];
    // Заполняем массив случайными числами
    for (int x = 0; x < n; x++) {
        mas[x] = rand() % 11;
    }
    int m = mas[0];
    int m_count = 0;
    // Выводим массив на экран
    cout << "Исходный массив: \n";
    for (int x = 0; x < n; x++) {
        cout << mas[x] << " "; 
    }
    cout << endl;
    // Считаем частоту элементов
    int* chast = new int[M]();
    for (int i = 0; i < n; i++) {
        chast[mas[i]]++;
    }
    cout << endl;
    for (int i = 0; i < M; i++) {
        if (chast[i] > m_count) {
            m_count = chast[i];
        }
    }
    if (m_count == 1) {
        cout << "Все числа встречаются по одному разу\n";
    }
    else {
        cout << "Числа, которые встречаются больше всего раз: ";
        for (int i = 0; i < M; i++) {
            if (chast[i] == m_count) {
                cout << i << " ";
            }
        }
        cout << " (встречаются " << m_count << " раз)" << endl;
    }
    system("pause");
    return 0;
}