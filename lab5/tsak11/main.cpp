#include <iostream>
#include <conio.h>

using namespace std;

class fraction {
    static int counter;
    int numerator, denominator, id;

public:
    fraction() {
        if (counter > 2) {
            counter = 0;
        } else {
            counter++;
        }
        id = counter;
    }

    char op;

    void input() {
        cout << "Enter fraction " << id << ":" << endl;
        char waste;
        cin >> numerator >> waste >> denominator;
        if (id % 2 != 0) {
            cout << "Enter operator:" << endl;
            cin >> op;
        }
    }

    void output() const {
        cout << "The answer is " << numerator << "/" << denominator << endl;
    }

    void fadd(fraction, fraction);

    void fsub(fraction, fraction);

    void fmul(fraction, fraction);

    void fdiv(fraction, fraction);

    void lowterms();

};

int fraction::counter = 0;

void fraction::fadd(fraction f1, fraction f2) {
    numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    denominator = f1.denominator * f2.denominator;
}

void fraction::fsub(fraction f1, fraction f2) {
    numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
    denominator = f1.denominator * f2.denominator;
}

void fraction::fmul(fraction f1, fraction f2) {
    numerator = f1.numerator * f2.numerator;
    denominator = f1.denominator * f2.denominator;
}

void fraction::fdiv(fraction f1, fraction f2) {
    numerator = f1.numerator * f2.denominator;
    denominator = f1.denominator * f2.numerator;
}

void fraction::lowterms() // сокращение дроби
{
    long tnum, tden, temp, gcd;
    tnum = labs(numerator); // используем неотрицательные
    tden = labs(denominator); // значения (нужен cmath)
    if (tden == 0) // проверка знаменателя на 0
    {
        cout << "Недопустимый знаменатель!";
        exit(1);
    } else if (tnum == 0) // проверка числителя на 0
    {
        numerator = 0;
        denominator = 1;
        return;
    }
// нахождение наибольшего общего делителя
    while (tnum > 0) {
        if (tnum < tden) // если числитель больше знаменателя,
        {
            temp = tnum;
            tnum = tden;
            tden = temp;
        } // меняем их местами
        tnum = tnum - tden; // вычитание
    }
    gcd = tden; // делим числитель и знаменатель на
    numerator = numerator / gcd; // полученный наибольший общий делитель
    denominator = denominator / gcd;
}


int main() {
    fraction f1, f2, f3;
    char ch = 'y';
    do {
        f1.input();
        f2.input();
        switch (f1.op) {
            case '+':
                f3.fadd(f1, f2);
                break;
            case '-':
                f3.fsub(f1, f2);
                break;
            case '*':
                f3.fmul(f1, f2);
                break;
            case '/':
                f3.fdiv(f1, f2);
                break;
        }
        f3.lowterms();
        f3.output();
        cout << "Do you want to continue? (y/n)" << endl;
    } while (ch == _getch());
    return 0;
}
