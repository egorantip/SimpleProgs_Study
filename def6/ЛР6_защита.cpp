#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <locale>
#define FNAME "C:\\datadef.dat"

int main() {
    int n;
    setlocale(LC_ALL, "ru");
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    double* num = new double[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        num[i] = -100 + (rand() % 1001) / 5;
        std::cout << std::fixed << std::setprecision(2) << num[i] << " ";
    }
    std::cout << std::endl;
    // cоздаём бинарный файл и записываем в него числа
    std::fstream file("datadef.dat", std::ios::binary | std::ios::out | std::ios::trunc);
    if (!file) {
        std::cerr << "error open file for write" << std::endl;
        return 1;
    }

    //int size = sizeof(num) / sizeof(num[0]);
    int size = n;
    for (int i = 0; i < size; i++) {
        // reinterpret_cast используется для приведения указателя к типу const char* (требуется для write)
        file.write(reinterpret_cast<const char*>(&num[i]), sizeof(double) /*указвает кол-во нужных байт (8)*/);
    }
    file.close();

    int j;
    std::cout << "В файл записан бинарный массив (введите 0, чтобы продолжить): ";
    std::cin >> j;

    if (j == 0) {
        // открываем файл для чтения в бинарном режиме
        std::fstream file("datadef.dat", std::ios::binary | std::ios::in | std::ios::out);
        if (!file) {
            std::cerr << "error open file" << std::endl;
            return 1;
        }

        double x; // текущее значение 
        double minv, maxv; // мин и макс значения
        int mini = 0, maxi = 0; // индексы мин и макс

        // ищем минимальное и максимальное значения
        file.seekg(0, std::ios::beg); // начинаем с начала файла
        file.read(reinterpret_cast<char*>(&x), sizeof(double));
        minv = maxv = x;
        for (int i = 1; i < size; i++) {
            file.read(reinterpret_cast<char*>(&x), sizeof(double));
            if (x < minv) {
                minv = x;
                mini = i;
            }
            if (x > maxv) {
                maxv = x;
                maxi = i;
            }
        }

        // меняем местами значения минимального и максимального элементов
        file.seekp(mini * sizeof(double), std::ios::beg);
        file.write(reinterpret_cast<const char*>(&maxv), sizeof(double));

        file.seekp(maxi * sizeof(double), std::ios::beg);
        file.write(reinterpret_cast<const char*>(&minv), sizeof(double));

        file.close();

        // записываем изменённый массив в тот же файл в текстовом формате
        std::ifstream file2("datadef.dat", std::ios::binary);
        if (!file2) {
            std::cerr << "error open file for read" << std::endl;
            return 1;
        }

        // читаем массив обратно
        double* mass = new double[size];
        file2.read(reinterpret_cast<char*>(mass), size * sizeof(double));
        for (int i = 0; i < size; i++) {
            std::cout << std::fixed << std::setprecision(2) << mass[i] << " ";
        }
        std::cout << std::endl;
        file2.close();


        // перезаписываем файл в bin формате
        std::fstream file3("datadef.dat", std::ios::binary | std::ios::out | std::ios::trunc);
        if (!file3) {
            std::cerr << "error open!" << std::endl;
            delete[] mass;
            return 1;
        }
        for (int i = 0; i < n; i++) {
            file3.write(reinterpret_cast<const char*>(&mass[i]), sizeof(double));
        }
        file3.close();
    }

    return 0;
}
