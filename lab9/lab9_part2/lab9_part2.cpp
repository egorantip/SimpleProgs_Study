#include <iostream>
#include "Vector2D.h"

int main() {
    setlocale(LC_ALL, "ru");

    double v11, v12, v21, v22;

    std::cout << "Введите координаты начальной точки: " << std::endl;
    std::cin >> v11 >> v12;

    std::cout << "Введите координаты конечной точки: " << std::endl;
    std::cin >> v21 >> v22;

    Vector2D v1(v11, v12);
    Vector2D v2(v21, v22);

    std::cout << "Длина v1: " << v1.value() << std::endl;
    std::cout << "Угол v1 к оси X: " << v1.angleToXAxis() << " радиан" << std::endl;
    std::cout << "Угол v1 к v2: " << v1.angleToVector(v2) << " радиан" << std::endl;
    std::cout << "Скалярное произведение: " << v1.scalarProduct(v2) << std::endl;
    std::cout << "Векторное произведение: " << v1.vectorProduct(v2) << std::endl;

    return 0;
}