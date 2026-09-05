#include <iostream>
#include <cmath>
#include "CAutomobile.h"
#define PI 4*atan(1)

using namespace std;
// конструктор класса автомобиль
CAutomobile::CAutomobile() {
	color = "белый";
	brand = "Skoda";
	typeDrive = "передний"; // тип привода
	typeEngine = "2л"; // тип двигателя
	mileage = 2345; // пробег
	number = ""; // по умолчанию номер пуст
	newPrice = 2650000; // стоимость нового автомобиля
	curPrice = 1800000; // текущая цена
	x = 0; // координата(ш)
	y = 0; // координата(д)
	maxSpeed = 125; // максимальная скорость
	fuelRate = 11; // расход топлива на 100 км
	fuelRemains = 76; // остаток топлива в баке
	serviceInterval = 365; // меж сервисный интервал
}

CAutomobile::CAutomobile(string newnumber) { // создаем конструктор
	if (IsNumberValid(newnumber))// проверка валидности номера методом класса 
		number = newnumber; // установка номера по параметру конструктора       
}

// присвоение номера
bool CAutomobile::SetNumber(string newnumber) {
	if (IsNumberValid(newnumber))
	{
		number = newnumber; // установка номера после проверки
		return true; // успешный выход из метода
	}
	return false; // выход из метода без внесения изменений
}

// вывод номера
string CAutomobile::GetNumber() {
	return "Государственный регистрационный номер машины: " + number;
}

bool CAutomobile::IsNumberValid(string newnumber) { // Проверка номера на валидность
	return newnumber.size() == 8;
}

// метод: доедет ли до города
bool CAutomobile::DriveTo(double distance) {
	double maxDistance = (fuelRemains / fuelRate) * 100;
	if (distance <= maxDistance) {
		return true;
	}
	else return false;
}

// метод: расстояние до точки GPS
double CAutomobile::DistanceTo(double x1, double y1) {
	const double R = 6371; // константа - радиус земли
	double xDiff = (x1 - x) * PI / 180;
	double yDiff = (y1 - y) * PI / 180;
	double a = sin(xDiff / 2) * sin(xDiff / 2) + cos(x * 3.14 / 180.0) * cos(x1 * 3.14 / 180.0) * sin(yDiff / 2) * sin(yDiff / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	return R * c;
}

// стоимость поездки
double CAutomobile::DriveCost(double x1, double y1, double fuelPrice) {
	double distance = DistanceTo(x1, y1);
	return distance * fuelRate / 100 * fuelPrice;
}

// время поездки
double CAutomobile::DriveTime(double x1, double y1) {
	double distance = DistanceTo(x1, y1);
	return distance / maxSpeed;
}

// потеря в стоимости
int CAutomobile::LossValue() {
	return newPrice - curPrice;
}

// информация об автомобиле
string CAutomobile::InfoAboutCar() const {
	return "Цвет: " + color + "\nМарка: " + brand + "\nПривод: " + typeDrive + "\nПробег: " + to_string(mileage) + " км";
}

CAutomobile::~CAutomobile() {

}