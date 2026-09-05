// TestDllApp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <cmath>

using myexp = double(double x);
using namespace std;

int main()
{
	HMODULE lib = LoadLibraryW(L"Test.dll");
	
	myexp *e = (myexp*)GetProcAddress(lib, "Exponenta");
		
	for (double x = 0; x < 20; x++)
	{		  
		cout << e(x) <<" "<< exp(x)<< endl;
	}
	
	FreeLibrary(lib);
	system("pause");

    return 0; 
}

