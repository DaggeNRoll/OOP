#include <iostream>

using namespace std;

int const n=3;//размер массива

class fraction {//класс для дробей
    int numerator, denominator;

public:
    fraction(){}

    void input() {//ввод дроби
        cout << "Enter fraction: " << endl;
        char waste;
        cin >> numerator >> waste >> denominator;

    }

    void output() const {//вывод дроби
        cout << "The answer is " << numerator << "/" << denominator << endl;
    }

    void fadd(fraction, fraction);//сложение

    void fsub(fraction, fraction);//вычитание

    void fmul(fraction, fraction);//умножение

    void fdiv(fraction, fraction);//деление

    void lowterms();//сокращение

    void addN(){
        denominator*=n;//вычисляет среднее, умножая знаменатель на количество дробей
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
    fraction arr[n];//массив дробей
    fraction average;//среднее
    cout << "Enter fractions:" << endl;
    for (int i =0;i<n;i++){//ввод дробей в массив
        arr[i].input();
    }
    average=arr[0];//инициализация среднего первой дробью (для дальнейшего сложения)
    for (int i=1;i<n;i++){
        average.fadd(average,arr[i]);//сложение всех дробей
    }
    average.addN();//деление на количество
    average.lowterms();//сокращение
    average.output();//вывод среднего

    return 0;
}
