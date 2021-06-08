#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class sterling {
    long pounds;
    int shillings, pence;

public:
    sterling() {}

    sterling(double x) {
        pence = static_cast<int>(x * 20 * 12);
        shillings = pence / 12;
        pence %= 12;
        pounds = shillings / 20;
        shillings %= 20;
    }

    sterling(long x, int y, int z) {
        pounds = x;
        shillings = y;
        pence = z;
    }

    void getSterling() {
        char waste;
        cin >> waste >> pounds >> waste >> shillings >> waste >> pence;
    }

    void putSterling() const {
        cout << "Answer is £" << pounds << "." << shillings << "." << pence << endl;
    }

    explicit operator double() const {
        return pounds + (shillings * 12 + pence) / (20 * 12);
    }

    sterling operator+(sterling st2) {
        sterling temp(pounds,shillings,pence);
        return sterling(double(temp)+double(st2));
    }

    sterling operator-(sterling st2) {
        sterling temp(pounds,shillings,pence);
        return sterling(double(temp) - double(st2));
    }

    sterling operator*(double x) {
        sterling temp(pounds,shillings,pence);
        return sterling(double(temp)*x);
    }

    sterling operator/(sterling st2) {
        sterling temp(pounds,shillings,pence);
        return sterling(double(temp)/double(st2));
    }

    sterling operator/(double x) {
        sterling temp(pounds,shillings,pence);
        return sterling(double(temp)/x);
    }


};

class bMoney {
    long double sum;
    string ustring;
public:
    bMoney() {}

    bMoney(long double x, string s) {
        sum = x;
        ustring = s;
    }

    bMoney(sterling m1){
        sum=double(m1)*50;
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


    bMoney operator+(bMoney);

    bMoney operator-(bMoney);

    bMoney operator*(long double);

    long double operator/(bMoney);

    bMoney operator/(long double);

    explicit operator sterling();

};

bMoney::operator sterling() {
    return sterling(double(sum/50));
}

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

int main(){
    sterling s;
    bMoney bm;
    cout << "Enter British money:" << endl;
    s.getSterling();
    bm=bMoney(s);
    cout << "It equals:" << endl;
    bm.stringOutput();
    cout << "Enter American money:" << endl;
    bm.getmoney();
    s = sterling(bm);
    cout << "It equals:" << endl;
    s.putSterling();

    return 0;
}