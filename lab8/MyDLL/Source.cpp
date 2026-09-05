#include "pch.h"
#include "Header.h"
#include <iostream>
#define pi 4*atan(1)

double Exponenta(double x) {
	double Sum = 1;
	int n = 1;
	double t = x;
	while (t > 0.00001)
	{
		n++;
		Sum += t;
		t *= x / n;
	}

	return Sum;

}

double Sinus(double x) {
	double sum = 0;
	int n = 1;
	double q = x / 1;
	int d = 1;
	while (q > 0.00001) {
		sum += n * q;
		n *= (-1);
		q = q * (x * x) / ((d + 1) * (d + 2));
		d += 2;
	}
	return sum;
}

double Cosinus(double x) {
	double sum = 1;
	int n = -1, d = 1;
	double q = x * x / ((d + 1) * d);
	while (q > 0.00001) {
		sum += n * q;
		n *= (-1);
		d += 2;
		q = q * (x * x) / ((d + 1) * (d + 2));
	}
	return sum;
}

double Tangens(double x) {
	return Sinus(x) / Cosinus(x);
}

double Natural_Logarithm(double x) {
	double sum = 0;
	int n = 1, d = 1;
	double q = (x - 1) / d;
	while (q > 0.00001) {
		sum += n * q;
		n *= (-1);
		d++;
		q = q * (x - 1) * (d - 1) / d;
	}
	return sum;

}

double ArcSinus(double x) {
	double sum = 0, q = x;
	int n = 0;
	while (q > 0.00001) {
		double new_x = x;
		sum += q;
		int first_factorial = 1, second_factorial = 1;
		n++;
		int new_n = n, thourth = 1;
		while (new_n != 0) {
			second_factorial *= new_n;
			thourth *= 4;
			new_n--;
		}
		new_n = 2 * n;
		while (new_n != 0) {
			first_factorial *= new_n;
			new_x *= x;
			new_n--;
		}
		q = first_factorial * (new_x * x) / (thourth * second_factorial * second_factorial * (2 * n + 1));
	}
	return sum;
}

double ArcTangens(double x) {
	double sum = 0;
	int n = 1, d = 1;
	double q = x;
	while (q > 0.00001) {
		sum += n * q;
		n *= (-1);
		d += 2;
		q *= (x * x) * (d - 2) / d;
	}
	return sum;
}
