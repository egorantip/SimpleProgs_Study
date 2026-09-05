#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

int main()
{
    float x;
    setlocale(LC_ALL, "RUS");
    cout << "Введите значение аргумента функции(-1;1): ";
    cin >> x;
    double Sum = 1, q = 1, eps = 0.0001f;
    int n = 1;
    int s = -1;
    while (true)
    {
        q = q * s * x * x / (n * (n + 1));
        Sum += q;
        n += 2;
        s = -s;
        if (fabs(q) < eps)
            break;
    }
    cout << "\nСумма ряда = " << Sum << " Значение cos(x) = " << cos(x);
}