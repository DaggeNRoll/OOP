#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class bMoney {
    long double sum;
    string ustring;
public:
    bMoney() {}

    void mstold() { //string to long double
        string s1 = ustring;
        s1.erase(0, 1);
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == ' ') {
                s1.erase(i, 1);
            }
        }
        sum = stold(s1);
    }

    void Idtoms() { //Long double to string
        if (sum < 9999999999999990.00) {
            ustring = to_string(sum);
            for (int i = ustring.find('.') - 1, j = 0; i > -1; i--, j++) {
                if (j % 3 == 0 && j != 0) {
                    ustring.insert(i + 1, ",");
                }
            }
            ustring.insert(0, "$");
        } else {
            cout << "Sum is too large!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void madd(bMoney m1, bMoney m2) {//сложение
        sum = m1.sum + m2.sum;
    }

    void stringOutput() const {//вывод
        cout << "The answer is " << ustring << endl;
    }

    void getmoney() {//ввод
        getline(cin, ustring);
    }
};

int main() {
    bMoney m1, m2, m3, m4;
    cout << "Enter sum1" << endl;
    m1.getmoney();//ввод
    m1.mstold();//преоьбразование
    cout << "Enter sum2" << endl;
    m2.getmoney();
    m2.mstold();
    cout << "Enter sum3" << endl;
    m3.getmoney();
    m3.mstold();
    m4.madd(m1, m2);//сложение
    m4.madd(m3, m4);//сложение
    m4.Idtoms();//преобразование
    m4.stringOutput();//вычитание

    return 0;
}