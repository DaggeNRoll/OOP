#include <iostream>
#include <conio.h>

using namespace std;

struct fraction {
    int numerator, denominator;
};//объ€вление структуры дл€ хранени€ дробей

int main() {
    fraction f1, f2, f3;
    char waste, c = 'y';
    char op;

    do {
        cout << "Enter the first fraction, the operator and the second fraction (a/b + c/d)" << endl;
        cin >> f1.numerator >> waste >> f1.denominator >> op >> f2.numerator >> waste >> f2.denominator;

        switch (op) {//разные формулы дл€ разных математических операций
            case '+':
                f3.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
                f3.denominator = f1.denominator * f2.denominator;
                break;
            case '-':
                f3.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
                f3.denominator = f1.denominator * f2.denominator;
                break;
            case '*':
                f3.numerator = f1.numerator * f2.numerator;
                f3.denominator = f1.denominator * f2.denominator;
                break;
            case '/':
                f3.numerator = f1.numerator * f2.denominator;
                f3.denominator = f1.denominator * f2.numerator;
                break;
        }

        cout << f1.numerator << "/" << f1.denominator << " " << op << " "
             << f2.numerator << "/" << f2.denominator << " = "
             << f3.numerator << "/" << f3.denominator << endl;
        cout << "Would you like to solve another math problem with fractions? (y/n)" << endl;
    } while (c == _getch());//идЄт к новому шагу, если введено "y"

    return 0;
}
