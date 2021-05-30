#include <iostream>

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

int main() {
    sterling m1, m2, m3;
    double x;
    cout << "Enter m1" << endl;
    m1.getSterling();
    cout << "Enter m2" << endl;
    m2.getSterling();
    cout << "Enter x" << endl;
    cin >> x;
    m3=m1+m2;
    cout << "m1+m2=";
    m3.putSterling();
    m3=m1-m2;
    cout << "m1-m2=";
    m3.putSterling();
    m3=m1/m2;
    cout << "m1/m2=";
    m3.putSterling();
    m3=m1*x;
    cout << "m1*x=";
    m3.putSterling();
    m3=m1/x;
    cout << "m1/x=";
    m3.putSterling();
    return 0;
}