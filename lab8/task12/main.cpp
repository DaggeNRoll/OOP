#include <iostream>
#include <cmath>

using namespace std;

class sterling {
protected:
    long pounds;
    int shillings, pence;

public:
    sterling() {}//конструктор по-умолчанию

    sterling(double x) {//конструктор, который переводит из double в sterling
        pence = round(x * 20 * 12);
        shillings = pence / 12;
        pence %= 12;
        pounds = shillings / 20;
        shillings %= 20;
    }

    sterling(long x, int y, int z) { //конструктор с тремя аргументами
        pounds = x;
        shillings = y;
        pence = z;
    }

    void getSterling() {
        char waste;
        cin >> waste >> pounds >> waste >> shillings >> waste >> pence;
    }

    void putSterling() const {
        cout << "Answer is £" << pounds << "." << shillings << "." << pence;
    }

    operator double() const {//для явного преобразования из sterling в double
        return pounds + shillings / 20 + pence / 240;
    }

    sterling operator+(sterling st2) {//перегрузка sterling+sterling
        sterling temp(pounds, shillings, pence);
        return sterling(double(temp) + double(st2));
    }

    sterling operator-(sterling st2) {//перегрузка sterling-sterling
        sterling temp(pounds, shillings, pence);
        return sterling(double(temp) - double(st2));
    }

    sterling operator*(double x) {//перегрузка sterling*double
        sterling temp(pounds, shillings, pence);
        return sterling(double(temp) * x);
    }

    sterling operator/(sterling st2) {//перегрузка sterling/sterling
        sterling temp(pounds, shillings, pence);
        return sterling(double(temp) / double(st2));
    }

    sterling operator/(double x) {//перегрузка sterling/double
        sterling temp(pounds, shillings, pence);
        return sterling(double(temp) / x);
    }
};

class sterfrac : public sterling {
private:
    int eights;
public:
    sterfrac() : sterling(), eights(0) {}

    sterfrac(double x) {//перевод из современных в имперские

        pounds = x;
        shillings = (x - pounds) * 20;
        pence = ((x - pounds) * 20 - shillings) * 12;
        eights = round((((x - pounds) * 20 - shillings) * 12 - pence) * 8);
    }

    sterfrac(long x, int y, int z, int eights) : sterling(x, y, z), eights(eights) {}

    void getSterling() {

        int num, den;
        char waste;
        cin >> waste >> pounds >> waste >> shillings >> waste >> pence >> waste >>
            num >> waste >> den;

        if (den == 2) {
            num *= 4;
        }
        if (den == 4) {
            num *= 2;
        }
        eights = num;
    }

    void putSterling() const {
        sterling::putSterling();
        cout << "-";
        switch (eights) {
            case 2:
                cout << "1/4" << endl;
                break;
            case 4:
                cout << "1/2" << endl;
                break;
            case 6:
                cout << "3/4" << endl;
                break;
            case 0:
                cout << "0" << endl;
                break;
            default:
                cout << eights << "/8" << endl;
        }
    }

    operator double() {
        return sterling::operator double() + eights / 1920.0;//1 фунт = 20 шиллингов = 240 пенсов=
        //= 1920 полуфартингов
    }

    sterfrac operator+(sterfrac s) {
        return sterfrac(double(sterfrac(pounds, shillings, pence, eights)) + double(s));
    }

    sterfrac operator-(sterfrac s) {
        return sterfrac(double(sterfrac(pounds, shillings, pence, eights)) - double(s));
    }

    sterfrac operator*(double x) {
        return sterfrac(double(sterfrac(pounds, shillings, pence, eights)) * x);
    }

    sterfrac operator/(sterfrac s) {
        return sterfrac(double(sterfrac(pounds, shillings, pence, eights)) / double(s));
    }

    sterfrac operator/(double x) {
        return sterfrac(double(sterfrac(pounds, shillings, pence, eights)) / x);
    }
};

int main() {
    sterfrac m1, m2, m3;
    double x;
    cout << "Enter m1" << endl;
    m1.getSterling();
    cout << "Enter m2" << endl;
    m2.getSterling();
    cout << "Enter x" << endl;
    cin >> x;
    m3 = m1 + m2;
    cout << "m1+m2=";
    m3.putSterling();
    m3 = m1 - m2;
    cout << "m1-m2=";
    m3.putSterling();
    m3 = m1 / m2;
    cout << "m1/m2=";
    m3.putSterling();
    m3 = m1 * x;
    cout << "m1*x=";
    m3.putSterling();
    m3 = m1 / x;
    cout << "m1/x=";
    m3.putSterling();
    return 0;
}