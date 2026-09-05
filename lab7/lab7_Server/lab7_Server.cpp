// SERVER
#pragma comment (lib, "ws2_32.lib")

#include "winsock2.h"
#include <iostream>
#include <locale>

#define PORT 10000

int main()
{
    setlocale(LC_ALL, "Rus");

    WSADATA wsaData; // Инициализация библиотеки Winsock
    std::cout << "Сервер запущен\n"; //
    if (WSAStartup(MAKEWORD(2, 2), &wsaData)) { // Проверка инициализации библиотеки Winsock
        std::cout << "Ошибка библиотеки\n";
        exit(1);
    }

    SOCKET mysocket = socket(AF_INET, SOCK_STREAM, NULL); // Создаем сокет
    if (mysocket == INVALID_SOCKET) { 
        std::cout << "Ошибка Сокета\n";
        WSACleanup();
        exit(2);
    }

    // Устанавливаем параметры локального адреса для привязки сокета
    sockaddr_in local_addr; 
    local_addr.sin_family = AF_INET; // Устанавливает для поля sin_family структуры sockaddr значение, которое соответствует Internet-домену
    local_addr.sin_port = htons(PORT); // Установка номера порта
    local_addr.sin_addr.s_addr = INADDR_ANY; // Вложенная структура типа in_addr, в которой будет храниться сам сетевой адрес

    // Привязываем сокет к локальному адресу
    if (bind(mysocket, (sockaddr*)&local_addr, sizeof(local_addr)) == SOCKET_ERROR) {
        std::cout << "Ошибка Сокета\n";
        closesocket(mysocket);
        WSACleanup();
        exit(3);
    }

    // Устанавливаем сокет в режим прослушивания
    if (listen(mysocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cout << "Ошибка чтения\n";
        closesocket(mysocket);
        WSACleanup();
        exit(4);
    }

    std::cout << "Ожидание подключения\n";

    // Принимаем подключение клиента
    SOCKET client_socket;
    sockaddr_in client_addr;
    int client_addr_size = sizeof(client_addr);
    client_socket = accept(mysocket, (sockaddr*)&client_addr, &client_addr_size);

    // Проверяем успешность подключения
    if (client_socket == INVALID_SOCKET) {
        std::cout << "Ошибка соединения\n";
        closesocket(client_socket);
    }
    else { // Если подключение успешно, проверям введенную пользователем букву Латинского алфавита
        char letter[256];
        int bytes = 0;
        while ((bytes = recv(client_socket, &letter[0], sizeof(letter), 0)) && bytes != SOCKET_ERROR) {
            char Glas_Symbols[] = { 'A','a','E', 'e', 'I','i', 'O','o','U','u','Y','y' };
            char Soglas_Symbols[] = { 'B', 'b', 'C', 'c', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'V', 'v', 'X', 'x', 'Z', 'z' };
            int a = *letter, count1 = 0, count2 = 0;
            for (int i = 0; i != sizeof(Glas_Symbols); ++i) {
                int b = Glas_Symbols[i];
                if (a == b) count1++;
                else for (int j = 0; j != sizeof(Soglas_Symbols); ++j) {
                    int c = Soglas_Symbols[j];
                    if (a == c) count2++;
                }
            }
            char Glas[256] = "Гласная буква", Soglas[256] = "Согласная буква", Err[256] = "Ошибка! Вы не ввели букву(латиница)!";
            if (count1 == 0 and count2 != 0) send(client_socket, Soglas, sizeof(Soglas), NULL);
            else if (count2 == 0 and count1 != 0) send(client_socket, Glas, sizeof(Glas), NULL);
            else send(client_socket, Err, sizeof(Err), NULL);
        }
        closesocket(client_socket); // Закрытие сокета Client
    }
    closesocket(mysocket); // Закрытие сокета Server
    WSACleanup();
    return 0;
}
