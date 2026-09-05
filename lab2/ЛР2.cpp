#include <iostream>
#include <locale>

using namespace std;

int main()
{

	float x, y;
	setlocale(LC_ALL, "RUS");
	cout << "Введите координаты x и y";
	cin >> x >> y;
	float R = sqrt(x * x + y * y);
	int res = -1;

	if (x > 0 && y > 0)	//1 четверть
	{
		if (y > x - 2)
		{
			if (y >= 0.5f)
				res = 4;
			else
				res = 3;
		}

		if (y <= x - 2)
		{
			if (y <= 0.5f)
				res = 20;
			else
				res = 19;
		}
	}

	if (x > 0 && y < 0) //2 четверть
	{
		if (y < x * x && R > 2)
			res = 11;

		else if (R <= 2 && y < x * x)
			res = 12;

		if (x > 4 && y >= x - 2)
			res = 2;

		else if (y > x * x && R > 2 && y < x - 2)
			res = 1;
	}

	if (x < 0 && y < 0)	//3 четверть
	{
		if (R > 2)
		{
			if (y <= -(x * x))
				res = 10;
			else
				res = 9;
		}

		else if (R <= 2)
		{
			if (y >= -(x * x))
				res = 14;
			else
				res = 13;
		}
	}

	if (x < 0 && y > 0) //4 четверть
	{
		if (y > x - 2 && y > 4)
			res = 5;

		if (R > 2)
		{
			if (y <= 0.5f)
				res = 8;

			else if (y > 0.5f && y <= sqrt(abs(x)))
				res = 7;

			else if (y > sqrt(abs(x)) && y <= x - 2)
				res = 6;
		}

		else if (R <= 2)
		{
			if (y < sqrt(abs(x)) && y >= 0.5f)
				res = 16;

			else if (y < 0.5f && y < sqrt(abs(x)))
				res = 15;

			else if (y < 0.5f && y >= sqrt(abs(x)))
				res = 17;

			else if (y >= sqrt(abs(x)) && y >= 0.5f)
				res = 18;
		}
	}

	cout << "\nЗона номер: " << res;
}