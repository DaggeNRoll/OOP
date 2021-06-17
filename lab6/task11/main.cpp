#include <iostream>
#include <string>
#include <stdlib.h>//exit

using namespace std;

class ostrstream {
    long double sum;
    string ustring, s;
public:
    ostrstream() {}

    void getdouble() {
        cout << "Enter sum" << endl;
        cin >> sum;
    }

    void Idtoms() {
        if (sum < 9999999999999990.00) {//проверка на размер суммы
            ustring = to_string(sum);//преобразование в строку
            s = ustring;
            for (int i = s.find('.') - 1, j = 0; i > -1; i--, j++) {
                if (j % 3 == 0 && j != 0) {//вставка запятых до десятичной точки
                    s.insert(i + 1, ",");
                }
            }
            s.insert(0, "$");//вставка знака доллара
        } else {
            cout << "Sum is too large!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void stringOutput() const {//вывод
        cout << "The answer is " << s << endl;
    }
};

int main() {
    ostrstream s;
    s.getdouble();//ввод
    s.Idtoms();//преобразование
    s.stringOutput();//вывод
}