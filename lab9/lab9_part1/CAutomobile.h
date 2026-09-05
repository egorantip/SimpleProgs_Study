#pragma once
#include <cmath>
#include <string>

using namespace std;

class CAutomobile {
public: // методы и св-ва класса доступны другим функциям и объектам
	CAutomobile(); // конструктор класса Автомобиль
	CAutomobile(string newnumber); // конструктор с параметром класса Автомобиль

	bool SetNumber(string newnumber); // метод для задания номера автомобиля
	string GetNumber(); // метод для получения номера автомобиля

	bool DriveTo(double distance); // доедет ли до города
	double DistanceTo(double x1, double y1); // расстояние до заданной точки GPS по заданным координатам
	double DriveCost(double x1, double y1, double fuelPrice); // стоимость поездки в точку с заданными координатами и заданной ценой топлива
	double DriveTime(double x1, double y1); // время поездки до точки
	string InfoAboutCar() const;

	int LossValue(); // потеря в цене на данный момент при покупке нового
	int newPrice; // стоимость нового автомобиля
	int curPrice; // текущая стоимость

	~CAutomobile(); // деструктор класса Автомобиль

private: // методы и св-ва класса  доступны только внутри класса
	string number; // строка содержащая номер автомобиля
	bool IsNumberValid(string newnumber); // метод проверки валидности автомобиля
	string color;
	string brand;
	string typeDrive; // привод
	string typeEngine; // двигатель
	double mileage; // пробег
	double x; // координаты (ш)
	double y; // координаты (д)
	double maxSpeed; // максимальная скорость
	double fuelRate; // расход топлива
	double fuelRemains; // остаток топлива в баке
	double serviceInterval; // межсервисный интервал
};
