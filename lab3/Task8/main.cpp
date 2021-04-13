#include <iostream>

using namespace std;

struct fraction{
    int numerator;
    int denominator;
};//обявление структуры для хранения дробей

int main() {
    fraction f1,f2;//объявления переменных структурного типа
    char c;//нужна для игнорирования знака деления
    cout << "Enter the first fraction:" << endl;
    cin >> f1.numerator >> c >> f1.denominator;
    cout << "Enter the second fraction:" << endl;
    cin >> f2.numerator >> c >> f2.denominator;
    cout << f1.numerator << "/" << f1.denominator << " + "
        << f2.numerator << "/" << f2.denominator << " = "
        << f1.numerator*f2.denominator+f2.numerator*f1.denominator << "/"
        << f1.denominator*f2.denominator;//вычисление результата по правилам сложения дробей
    return 0;
}
