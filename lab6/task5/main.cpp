#include <iostream>

using namespace std;

int const n=3;

class fraction {
    int numerator, denominator;

public:
    fraction(){}

    void input() {
        cout << "Enter fraction: " << endl;
        char waste;
        cin >> numerator >> waste >> denominator;

    }

    void output() const {
        cout << "The answer is " << numerator << "/" << denominator << endl;
    }

    void fadd(fraction, fraction);

    void fsub(fraction, fraction);

    void fmul(fraction, fraction);

    void fdiv(fraction, fraction);

    void lowterms();

    void addN(){
        denominator*=n;
    }

};

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
    fraction arr[n];
    fraction average;
    cout << "Enter fractions:" << endl;
    for (int i =0;i<n;i++){
        arr[i].input();
    }
    average=arr[0];
    for (int i=1;i<n;i++){
        average.fadd(average,arr[i]);
    }
    average.addN();
    average.lowterms();
    average.output();

    return 0;
}
