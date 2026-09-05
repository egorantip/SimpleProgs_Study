#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

void Opredelitel(float a, float b, float c, float d) {
	cout << "Определитель квадратной матрицы 2 на 2 = " << a * d - b * c << endl;
}

void Zona(float x, float y, int& res) {
	if ((y > x * x) && (sqrt(x * x + y * y) > 2) && (y < x - 2) && (x > 0) && (y < 0)) {
		res = 1;
	}
	else if ((x > 4) && (y >= x - 2) && (x > 0) && (y < 0)) {
		res = 2;
	}
	else if ((y < 0.5f) && (x > 0) && (y > 0) && (y > x - 2)) {
		res = 3;
	}
	else if ((y >= 0.5f) && (y > x - 2) && (x > 0) && (y > 0)) {
		res = 4;
	}
	else if ((y > x - 2) && (y > 4) && (x < 0) && (y > 0)) {
		res = 5;
	}
	else if ((y > sqrt(abs(x))) && (y <= x - 2) && (sqrt(x * x + y * y) > 2) && (y >= 0.5f) && (x < 0) && (y > 0)) {
		res = 6;
	}
	else if ((y > 0.5f) && (y <= sqrt(abs(x))) && (sqrt(x * x + y * y) > 2) && (x < 0) && (y > 0)) {
		res = 7;
	}
	else if ((y <= 0.5f) && (x < 0) && (y > 0) && (sqrt(x * x + y * y) > 2)) {
		res = 8;
	}
	else if ((y > -(x * x)) && (x < 0) && (y < 0) && (sqrt(x * x + y * y) > 2)) {
		res = 9;
	}
	else if ((y <= -(x * x)) && (x < 0) && (y < 0)) {
		res = 10;
	}
	else if ((x > 0) && (y < 0) && (y < x * x) && (sqrt(x * x + y * y) > 2)) {
		res = 11;
	}
	else if ((sqrt(x * x + y * y) <= 2) && (y < x * x) && (x > 0) && (y < 0)) {
		res = 12;
	}
	else if ((y < -(x * x)) && (sqrt(x * x + y * y) <= 2) && (x < 0) && (y < 0)) {
		res = 13;
	}
	else if ((y >= -(x * x)) && (sqrt(x * x + y * y) <= 2) && (x < 0) && (y < 0)) {
		res = 14;
	}
	else if ((y < 0.5f) && (y < sqrt(abs(x))) && (sqrt(x * x + y * y) <= 2) && (x < 0) && (y > 0)) {
		res = 15;
	}
	else if ((x < 0) && (y > 0) && (sqrt(x * x + y * y) <= 2) && (y < sqrt(abs(x))) && (y >= 0.5f)) {
		res = 16;
	}
	else if ((x < 0) && (y > 0) && (y < 0.5f) && (y >= sqrt(abs(x))) && (sqrt(x * x + y * y) <= 2)) {
		res = 17;
	}
	else if ((y >= sqrt(abs(x))) && (y >= 0.5f) && (x < 0) && (y > 0) && (sqrt(x * x + y * y) <= 2)) {
		res = 18;
	}
	else if ((x > 0) && (y > 0) && (y <= x - 2) && (y > 0.5f)) {
		res = 19;
	}
	else if ((y <= 0.5f) && (y <= x - 2) && (x > 0) && (y > 0)) {
		res = 20;
	}
}

double Sum(float SUM, float arg, float q, float s, float n) {
	while (true) {
		q *= s * arg * arg / (n * (n + 1));
		SUM += q;
		n += 2;
		s = -s;
		if (q < 0.0001)
			break;
	}
	return SUM;
}

int main() {
	setlocale(LC_ALL, "RUS");
	double Sum = 1, q = 1, eps = 0.0001f;
	int number, res, n = 1, s = -1;
	float A, B, C, D, x, y, arg;
	cout << "Введите номер задания от 1 до 3: " << endl;
	cin >> number;
	switch (number) {
	case 1:
		cout << ("Введите A и B через пробел: ") << endl;
		cin >> A >> B;
		cout << ("Введите C и D через пробел: ") << endl;
		cin >> C >> D;
		Opredelitel(A, B, C, D);
		break;
	case 2:
		cout << "Введите координаты точки:" << endl;
		cin >> x >> y;
		Zona(x, y, res);
		cout << "Точка находится в зоне: " << res;
		break;
	case 3:
		setlocale(LC_ALL, "RUS");
		cout << "Введите значение аргумента функции(-1;1): ";
		cin >> arg;
		cout << endl << "Сумма ряда = " << Sum << " Значение cos(x) = " << cos(arg);
		break;
	default:
		cout << "Ошибка молодости!" << endl;
		break;
	}
}