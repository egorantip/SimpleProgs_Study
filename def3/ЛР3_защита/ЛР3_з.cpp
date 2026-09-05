#include <iostream>
using namespace std;
int main() {
    for (int a = 1; a <= 5; a += 4) {
        for (int i = 1; i < 10; i++) {
            for (int j = a + 1; j < a + 5; j++) {
                printf_s("%i*%i=%2i ", i, j, i * j);
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    return 0;
}