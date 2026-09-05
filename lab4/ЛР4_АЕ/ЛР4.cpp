#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "RUS");
    int x, y, k;
    cout << "Введите размерность массива:\n";
    cin >> x >> y;
    int** M = new int* [x];
    for (int i = 0; i < x; i++)
        M[i] = new int[y]; //создание массива
    srand(time(0));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            M[i][j] = rand() % 11 - 5; //заполнение массива
            cout << M[i][j] << "\t"; //вывод массива
        }
        cout << endl;
    }
    cout << endl;
    std::vector <int> s(x);
    for (int i = 0; i < x; i++) {
        s[i] = M[x - 1][i];
        cout << s[i] << "\t";
    }
    cout << endl;
    sort(s.begin(), s.end());
    if (s[0] < 0) {
        for (int i = 0; i < x; i++) {
            M[x - 1][i] = s[i];
        }
    }
    else {
        k = x - 1;
        for (int i = 0; i < x; i++, k--) {
            M[x - 1][i] = s[k];
        }
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    delete[] M;
}