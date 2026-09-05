#include <iostream>

using namespace std;

int main()
{
	printf_s("%3s%5s%5s%5s\n", "***", "***", "***", "***");
	printf_s("%s %4s %4s %s %2s %s\n", "*", "*", "*", "*", "*", "*");
	printf_s("%3s %2s %4s %s %4s\n", "***", "*", "*", "*", "***");
	printf_s("%s %4s %4s %s %2s\n", "*", "*", "*", "*", "*");
	printf_s("%3s %2s %6s %2s\n", "***", "*", "***", "*");
	return 0;
}