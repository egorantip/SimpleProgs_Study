#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#define FNAME_FIRST "C:\\data.dat"
#define FNAME_SECOND "C:\\result.res"

static void SwapEvenOdd(int** mass) {
    int maximum_even = mass[0][0], maximum_odd = mass[0][9];
    int even_index_i = 0, even_index_j = 0, odd_index_i = 0, odd_index_j = 9;
    for (int i = 0; i < 10; ++i) {
        if (mass[i][i] > maximum_even) {
            maximum_even = mass[i][i];
            even_index_j = even_index_i = i;
        }
        if (mass[i][9 - i] > maximum_odd) {
            maximum_odd = mass[i][9 - i];
            odd_index_i = i;
            odd_index_j = 9 - i;
        }
    }
    int variable = mass[even_index_i][even_index_j];
    mass[even_index_i][even_index_j] = mass[odd_index_i][odd_index_j];
    mass[odd_index_i][odd_index_j] = variable;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "1 - txt\n" << "2 - bin\n";
    int format;
    int n = 10;
    std::cout << "Введите 1 или 2: ";
    std::cin >> format;
    std::string stroka[] = { "Первая ", "Вторая ", "Третья ", "Четвертая ", "Пятая ", "Шестая ", "Седьмая ", "Восьмая ", "Девятая ", "Десятая " };
    std::string str_num = "строка: ";
    int** mass = new int* [10];
    for (int i = 0; i < 10; i++) mass[i] = new int[10];

    if (format == 1) { // Чтение и запись в текстовом виде 
        std::ifstream fin(FNAME_FIRST);
        if (fin.is_open()) {
            std::cout << "Файл открыт!" << std::endl << std::endl;
            // Поиск нужных символов
            int i = 0;
            std::string line;
            while (getline(fin, line)) {
                int j = 0;
                for (int k = 0; k < line.size(); k++) {
                    if (line[k] == '*' or line[k] == '!' or line[k] == ')') {
                        std::string value = "";
                        for (int m = k + 1; m < line.size(); m++) {
                            if (line[m] == '(' or line[m] == '!' or line[m] == '\n') break;
                            value += line[m];
                        }
                        if (!value.empty()) {
                            mass[i][j] = stoi(value);
                            j++;
                        }
                    }
                }
                i++;
            }
        }
        else std::cout << "Ошибка открытия файла!" << std::endl;
        fin.close();
        SwapEvenOdd(mass);

        // Заполнение файла "result.res" в новом формате
        std::ofstream fout(FNAME_SECOND);
        if (fout.is_open()) {
            for (int i = 0; i < n; i++) {
                fout << stroka[i] << str_num;
                std::cout << stroka[i] << str_num;
                for (int j = 0; j < n; j++) {
                    fout << "a" << i + 1 << j + 1 << "-> " << mass[i][j] << " ";
                    std::cout << "a" << i + 1 << j + 1 << "-> " << mass[i][j] << " ";
                }
                fout << std::endl;
                std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout << "Запись в файл прошла успешно!" << std::endl;
        }
        else std::cout << "Ошибка открытия файла!" << std::endl;
        fout.close();

        delete[] mass;
    }
    else if (format == 2) { // Чтение в текстовом и запись в бинарном виде
        std::ifstream fin(FNAME_FIRST);
        if (fin.is_open()) {
            std::cout << "Файл открыт!";
            // Поиск нужных символов
            int i = 0;
            std::string line;
            while (getline(fin, line)) {
                int j = 0;
                for (int k = 0; k < line.size(); k++) {
                    if (line[k] == '*' or line[k] == '!' or line[k] == ')') {
                        std::string value = "";
                        for (int m = k + 1; m < line.size(); m++) {
                            if (line[m] == '(' or line[m] == '!' or line[m] == '\n') break;
                            value += line[m];
                        }
                        if (!value.empty()) mass[i][j++] = stoi(value);
                    }
                }
                i++;
            }
        }
        else std::cout << "Ошибка открытия файла!" << std::endl;
        fin.close();
        SwapEvenOdd(mass);
        
        // Запись чисел в файл в бинарном виде
        std::ofstream fout(FNAME_SECOND, std::ios::binary);
        if (fout.is_open()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    fout.write(reinterpret_cast<char*>(&mass[i][j]), sizeof(mass[i][j]));
                }
                fout << std::endl;
            }
            std::cout << std::endl;
            std::cout << "Запись в файл прошла успешно!" << std::endl;
        }
        else std::cout << "Ошибка открытия файла!" << std::endl;
        fout.close();
    }
    else {
        std::cout << "Ошибка! Вы не ввели 1 или 2!";
    }
    system("pause");
    return 0;
}