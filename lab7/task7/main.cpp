#include <iostream>
#include <conio.h>//для _getch()

using namespace std;

class fraction {//структура со статической переменной int и тремя полями int
    static int counter;
    int numerator, denominator, id;

public:
    fraction() {//конструктор, инкрементирующий счётчик объектов и обнуляющий его, если их число становистя больше 3
        if (counter > 2) {//(нужно для удобного ввода
            counter = 0;
        } else {
            counter++;
        }
        id = counter;//присваивание номера объекта
    }

    fraction(int x, int y) {
        if (counter > 2) {//(нужно для удобного ввода
            counter = 0;
        } else {
            counter++;
        }
        id = counter;//присваивание номера объекта

        numerator = x;
        denominator = y;
    }

    char op;//открытое поле для математических операций

    void input() {//метод ввода
        cout << "Enter fraction " << id << ":" << endl;
        char waste;//для игнорирования "/"
        cin >> numerator >> waste >> denominator;
        if (id == 1) {//для считывания математического действия (после первой дроби в выражении)
            cout << "Enter operator:" << endl;
            cin >> op;
        }
    }

    void output() const {//константный метод вывода
        cout << "The answer is " << numerator << "/" << denominator << endl;
    }

    void lowterms();

    void lowterms(fraction);

    fraction operator+(fraction);//перегрузка +

    fraction operator-(fraction);//перегрузка -

    fraction operator*(fraction);//перегрузка *

    fraction operator/(fraction);//перегрузка делить

    bool operator==(fraction);//перегрузка операции равно

    bool operator!=(fraction);//перегрузка операции неравно

};

int fraction::counter = 0;

fraction fraction::operator+(fraction f2) {
    return fraction(numerator * f2.denominator + denominator * f2.numerator, denominator * f2.denominator);
}

fraction fraction::operator-(fraction f2) {
    return fraction(numerator * f2.denominator - denominator * f2.numerator, denominator * f2.denominator);
}

fraction fraction::operator*(fraction f2) {
    return fraction(numerator * f2.numerator, denominator * f2.denominator);
}

fraction fraction::operator/(fraction f2) {
    return fraction(numerator * f2.denominator, denominator * f2.numerator);
}

bool fraction::operator==(fraction f2) {
    return (numerator == f2.numerator && denominator == f2.denominator);
}

bool fraction::operator!=(fraction f2) {
    return !(numerator == f2.numerator && denominator == f2.denominator);
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
    fraction f1, f2, f3;//Объявление трёх объектов
    fraction check(0, 0), check2(0, 1), check3(1, 0), check4(1, 1);
    char ch = 'y';
    do {
        f1.input();//ввод с помощью метода класса
        f2.input();
        if (f1 == check || f1 == check2 || f1 == check3 || f1 == check4 ||
            f2 == check || f2 == check2 || f2 == check3 || f2 == check4) {//проверка на правильность введённой дроби
            cout << "Bad data format!" << endl;
            exit(1);
        }
        switch (f1.op) {//ветвление для разных математических операций
            case '+':
                f3 = f1 + f2;
                break;
            case '-':
                f3 = f1 - f2;
                break;
            case '*':
                f3 = f1 * f2;
                break;
            case '/':
                f3 = f1 / f2;
                break;
        }
        f3.lowterms();//сокращение результата
        f3.output();//вывод с помощью метода класса
        cout << "Do you want to continue? (y/n)" << endl;
    } while (ch == _getch());
    return 0;
}
