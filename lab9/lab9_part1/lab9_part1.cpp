#include <iostream>
#include <locale>
#include "CAutomobile.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	CAutomobile Mobile1, Mobile2;

	int CarNum;
	cout << "Введите номер машины (1 или 2): ";
	cin >> CarNum;
	cout << endl;
	if (CarNum == 1) {
		cout << "Автомобиль " << (CarNum) << endl;
		Mobile1.SetNumber("A001MP77");
		cout << Mobile1.GetNumber() << endl;
		double x1 = 55.897;
		double y1 = 37.4297;
		double Distance = Mobile1.DistanceTo(x1, y1);
		cout << "Расстояние до точки GPS: " << Distance << " км" << endl;
		cout << "Доедет ли до точки: " << (Mobile1.DriveTo(Distance) ? "нет" : "да") << endl;
		cout << "Стоимость поездки при цене за 1 литр 61 руб: " << Mobile1.DriveCost(x1, y1, 66) << endl;
		cout << "Время в пути: " << Mobile1.DriveTime(Distance, 223) << " часов" << endl;
		cout << "Потеря в цене на данный момент при покупке нового: " << Mobile1.LossValue() << " рублей" << endl;
	}
	else if (CarNum == 2) {
		cout << "Автомобиль " << (CarNum) << endl;
		Mobile2.SetNumber("A002MP77");
		cout << Mobile2.GetNumber() << endl;
		double x1 = 55.8067;
		double y1 = 38.9618;
		double Distance = Mobile2.DistanceTo(x1, y1);
		cout << "Расстояние до точки GPS: " << Distance << " км" << endl;
		cout << "Доедет ли до точки: " << (Mobile2.DriveTo(Distance) ? "нет" : "да") << endl;
		cout << "Стоимость поездки при цене за 1 литр 47 руб: " << Mobile2.DriveCost(x1, y1, 66) << endl;
		cout << "Время в пути: " << Mobile2.DriveTime(Distance, 251) << " часов" << endl;
		cout << "Потеря в цене на данный момент при покупке нового: " << Mobile2.LossValue() << " рублей" << endl;
	}
	else if (CarNum != 1 and CarNum != 2) {
		cout << "Ошибка! Вы не ввели 1 или 2!" << endl;
	}
}