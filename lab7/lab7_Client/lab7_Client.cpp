// CLIENT
#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#include <locale>

#define PORT 10000
#pragma warning(disable: 4996)

int main() {
    setlocale(LC_ALL, "Rus");

    WSADATA wsaData; // Инициализация библиотеки Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) { // Проверка инициализации библиотеки Winsock
        std::cout << "Ошибка библиотеки\n";
        exit(1);
    }

    SOCKADDR_IN addr; // Создание структуры для хранения информации об адресе сокета
    int sizeofaddr = sizeof(addr); // Размер структуры SOCKADDR_IN в байтах
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Установка IP-адреса 127.0.0.1
    addr.sin_port = htons(PORT); // Установка порта
    addr.sin_family = AF_INET; // Устанавливает для поля sin_family структуры sockaddr значение, которое соответствует Internet-домену

    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL); // Создание сокета
    if (Connection == INVALID_SOCKET) {
        std::cout << "Ошибка создания сокета\n";
        WSACleanup();
        exit(2);
    }

    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) { // Подключение к серверу
        std::cout << "Ошибка подключения к серверу\n";
        closesocket(Connection);
        WSACleanup();
        exit(3);
    }
    else { // Если подключение успешно, то отправляем на сервер ответ по запросу
        std::cout << "Успешно подключен!\n";
        std::cout << "Напишите букву (латиница): ";
        char name[256];
        while (std::cin >> name) {
            char mass[256];

            send(Connection, name, sizeof(name), NULL); // Отправка на сервер
            recv(Connection, mass, sizeof(mass), NULL); // Получение ответа

            std::cout << mass << std::endl;
            std::cout << "Напишите букву (латиница): ";
        }
        
        closesocket(Connection); // Закрытие сокета
        WSACleanup(); // Освобождение ресурсов
        system("pause");
    }

    return 0;

}
