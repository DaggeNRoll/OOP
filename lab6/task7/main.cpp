#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class money {
    long double sum;
public:
    money() {}

    void mstold(string s) {
        string s1 = s;
        s1.erase(0, 1);//удаление знака доллара
        for (int i = 0; i < s1.length(); i++) {//удаление пробелов
            if (s1[i] == ' ') {
                s1.erase(i, 1);
            }
        }
        sum = stold(s1);//приведение к long double
    }

    void moneyOutput() const {//вывод с двумя знаками после запятой
        cout << "Answer is " << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << sum;
    }
};

int main() {
    money m;
    cout << "Enter money:" << endl;
    string s;
    getline(cin, s);//ввод строки с клавиатуры
    m.mstold(s);//преобразование
    m.moneyOutput();//вывод
    return 0;
}
