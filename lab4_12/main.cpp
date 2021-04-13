#include <iostream>
#include <conio.h>

using namespace std;

struct fraction {
    int numerator, denominator;
};//объявление структуры для хранения дробей

fraction fadd(fraction, fraction);

fraction fsub(fraction, fraction);

fraction fmul(fraction, fraction);

fraction fdiv(fraction, fraction);

int main() {
    fraction f1, f2, f3;
    char waste, c = 'y';
    char op;

    do {
        cout << "Enter the first fraction, the operator and the second fraction (a/b + c/d)" << endl;
        cin >> f1.numerator >> waste >> f1.denominator >> op >> f2.numerator >> waste >> f2.denominator;

        switch (op) {//разные формулы для разных математических операций
            case '+':
                f3 = fadd(f1, f2);
                break;
            case '-':
                f3 = fsub(f1, f2);
                break;
            case '*':
                f3 = fmul(f1, f2);
                break;
            case '/':
                f3 = fdiv(f1, f2);
                break;
        }

        cout << f1.numerator << "/" << f1.denominator << " " << op << " "
             << f2.numerator << "/" << f2.denominator << " = "
             << f3.numerator << "/" << f3.denominator << endl;
        cout << "Would you like to solve another math problem with fractions? (y/n)" << endl;
    } while (c == _getch());//идёт к новому шагу, если введено "y"

    return 0;
}

fraction fadd(fraction f1, fraction f2) {
    fraction f3;
    f3.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    f3.denominator = f1.denominator * f2.denominator;
    return f3;
}

fraction fsub(fraction f1, fraction f2) {
    fraction f3;
    f3.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
    f3.denominator = f1.denominator * f2.denominator;
    return f3;
}

fraction fmul(fraction f1, fraction f2) {
    fraction f3;
    f3.numerator = f1.numerator * f2.numerator;
    f3.denominator = f1.denominator * f2.denominator;
    return f3;
}

fraction fdiv(fraction f1, fraction f2) {
    fraction f3;
    f3.numerator = f1.numerator * f2.denominator;
    f3.denominator = f1.denominator * f2.numerator;
    return f3;
}


