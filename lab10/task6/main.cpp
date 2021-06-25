#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class bMoney {
    long double sum;
    string ustring;
public:
    bMoney() {}//конструктор по умолчанию

    bMoney(long double x, string s) {//конструктор с двумя аргументами
        sum = x;
        ustring = s;
    }

    bMoney(long double x):sum(x){
        Idtoms();
    }

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

    void stringOutput() const {//вывод
        cout << "The answer is " << ustring << endl;
    }

    void getmoney() {//ввод
        getline(cin, ustring);
    }


    bMoney operator+(bMoney);//перегрузка bMoney+bMoney

    bMoney operator-(bMoney);//перегрузка bMoney-bMoney

    bMoney operator*(long double);//перегрузка bMoney/long double

    long double operator/(bMoney);//перегрузка bMoney/bMoney

    bMoney operator/(long double);//перегрузка bMoney/long double

    friend bMoney operator*(long double, bMoney);

    friend bMoney operator/(long double, bMoney);
};

bMoney bMoney::operator+(bMoney m1) {
    bMoney temp;
    temp.sum = sum + m1.sum;
    temp.Idtoms();
    return temp;
}

bMoney bMoney::operator-(bMoney m1) {
    bMoney temp;
    temp.sum = sum - m1.sum;
    temp.Idtoms();
    return temp;
}

bMoney bMoney::operator*(long double x) {
    bMoney temp;
    temp.sum = x * sum;
    temp.Idtoms();
    return temp;
}

long double bMoney::operator/(bMoney m1) {
    return sum / m1.sum;
}

bMoney bMoney::operator/(long double x) {
    bMoney temp;
    temp.sum = sum / x;
    temp.Idtoms();
    return temp;
}

bMoney operator*(long double x, bMoney m){
    return bMoney(x*m.sum);
}

bMoney operator/(long double x, bMoney m){
    return bMoney(x/m.sum);
}

int main() {
    bMoney m1, m2, m3;
    long double x;
    cout << "Enter the first sum of money:" << endl;
    m1.getmoney();
    m1.mstold();
    cout << "Enter the second sum of money:" << endl;
    m2.getmoney();
    m2.mstold();
    cout << "Enter long double value:" << endl;
    cin >> x;

    m3 = m1 + m2;
    cout << "m1 + m2 = ";
    m3.stringOutput();

    m3 = m1 - m2;
    cout << "m1 - m2 = ";
    m3.stringOutput();

    m3 = m1 * x;
    cout << "m1 * x = ";
    m3.stringOutput();

    cout << "m1 / m2 = " << m1 / m2 << endl;

    m3 = m1 / x;
    cout << "m1 / x = ";
    m3.stringOutput();

    m3=x*m1;
    cout<<"x*m1=";
    m3.stringOutput();

    m3=x/m1;
    cout <<"x/m1=";
    m3.stringOutput();

    return 0;
}