#include "windows.h"
#include <iostream>
#include <cmath>

using myexp = double(double x);
using mysin = double(double x);
using mycos = double(double x);
using mytan = double(double x);
using mylog = double(double x);
using myasin = double(double x);
using myatan = double(double x);
using namespace std;

int main() {
	HMODULE lib = LoadLibraryW(L"MyDLL.dll");

	double n = 1;

	myexp* e = (myexp*)GetProcAddress(lib, "Exponenta");
	mysin* s = (mysin*)GetProcAddress(lib, "Sinus");
	mycos* c = (mycos*)GetProcAddress(lib, "Cosinus");
	mysin* t = (mytan*)GetProcAddress(lib, "Tangens");
	mysin* nl = (mylog*)GetProcAddress(lib, "Natural_Logarithm");
	myasin* as = (myasin*)GetProcAddress(lib, "ArcSinus");
	myatan* at = (myatan*)GetProcAddress(lib, "ArcTangens");

	cout << e(4) << " " << exp(4) << endl << endl;
	cout << s(1) << " " << sin(1) << endl << endl;
	cout << c(0.05) << " " << cos(0.05) << endl << endl;
	cout << t(0.25) << " " << tan(0.25) << endl << endl;
	cout << nl(2) << " " << log(2) << endl << endl;
	cout << as(0.04) << " " << asin(0.04) << endl << endl;
	cout << at(1) << " " << atan(1) << endl;

	FreeLibrary(lib);
	system("pause");

	return 0;
}