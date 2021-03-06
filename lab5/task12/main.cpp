#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class fraction {//класс из задания 11

    int numerator, denominator;

public:
    fraction() : numerator(0), denominator(0) {}

    fraction(int x) : denominator(x) {}

    fraction(int x, int y) : numerator(x), denominator(y) {}


    void input() {
        cout << "Enter fraction: " << endl;
        char waste;
        cin >> numerator >> waste >> denominator;
    }


    void output(int length) const {
        cout << setw(length) << numerator << "/" << denominator;
    }

    void fadd(fraction, fraction);

    void fsub(fraction, fraction);

    void fmul(fraction, fraction);

    void fdiv(fraction, fraction);

    void lowterms();

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
    int denominator;
    cout << "Enter denominator" << endl;
    cin >> denominator;

    int length = 0;//для величины отступа таблицы
    int temp = denominator;
    while (temp > 0) {
        temp /= 10;
        length++;
    }
    length *= 10;
    length++;
    cout << setw(length) << " ";//вывод пустой ячейки
    for (int i = 1; i < denominator; i++) {//вывод первой строки
        fraction f(i, denominator);
        f.lowterms();
        f.output(length);
    }
    cout << endl;
    for (int i = 0; i < denominator; i++) {//вывод границы между "шапкой" и таблицей
        cout << setfill('-') << setw(length * 2 - 2) << "";
    }
    cout << setfill(' ') << endl;
    for (int i = 1; i < denominator; i++) {
        fraction fI(i, denominator);//множитель с первой строки
        for (int j = 0; j < denominator; j++) {
            fraction fIJ;//произведение
            if (j == 0) {//вывод первого столбца
                fraction fJ0(i, denominator);
                fJ0.lowterms();
                fJ0.output(length);
            } else {//вычисление произведения
                fraction fJ(j, denominator);
                fIJ.fmul(fI, fJ);
                fIJ.lowterms();//соскращение результата
                fIJ.output(length);//вывод произведения
            }
        }
        cout << endl;
    }
    return 0;
}
