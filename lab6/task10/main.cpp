#include <iostream>
#include <stdlib.h>//для exit

using namespace std;

class matrix {
    int x, y;
    int arr[10][10];
public:
    matrix() {//границы матрицы по-умолчанию
        x = 10;
        y = 10;
    }

    matrix(int i, int j) {//пользовательские границы
        x = i;
        y = j;
    }

    void putel(int i, int j, int temp) {
        if (i < 0 || i > x || j < 0 || j > y) {//проверка на соответствие размеру
            cout << "Invalid index!" << endl;
            exit(EXIT_FAILURE);
        } else {//если всё успешно, происходит запись
            arr[i][j] = temp;
        }
    }

    int getel(int i, int j) const {//проверка на соответствие размеру
        if (i < 0 || i > x || j < 0 || j > y) {
            cout << "Invalid index!" << endl;
            exit(EXIT_FAILURE);
        } else {//возврат знаечния по индексам
            return arr[i][j];
        }
    }
};

int main() {
    matrix m1(8, 5); // описываем матрицу
    int temp = 12345; // описываем целое
    m1.putel(7, 4, temp); // помещаем значение temp в матрицу
    temp = m1.getel(7, 4); // получаем значение из матрицы
}