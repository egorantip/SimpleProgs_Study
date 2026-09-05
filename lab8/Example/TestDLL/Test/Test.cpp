// Test.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>

using namespace std;

double Exponenta(double x)
{
	double Sum = 1;
	int n = 1;
	double t = x;
	while (t > 0.00001f)
	{
		n++;
		Sum += t;
		t *= x/n;
	}

	return Sum;
}



