#include <iostream>
#include <conio.h>//дл€ _getch()

using namespace std;

class fraction{//класс с двум€ пол€ми int
    int numerator, denominator;
public:
    fraction(){}//конструткор по-умолчанию
    void input(){//метод ввода
        char waste;//дл€ игнорировани€ "/"
        cout << "Enter fraction:" << endl;
        cin >> numerator >> waste >> denominator;
    }
    void output()const{//константный метод вывода
        cout << "The answer is " << numerator << "/" << denominator << endl;
    }
    void sum(fraction f1, fraction f2){//метод, суммирующий два объекта
        numerator=f1.numerator*f2.denominator + f1.denominator*f2.numerator;
        denominator = f1.denominator*f2.denominator;
    }
};

int main() {
    char ch = 'y';
    fraction f1,f2,f3;//ќбъ€вление трЄх объектов
    do {
        f1.input();//ввод с помощью метода класса
        f2.input();
        f3.sum(f1,f2);//суммирование введЄнных дробей
        f3.output();//вывод с помощью метода класса
        cout << "Do you want to continue? (y/n)" << endl;
    } while(ch == _getch());
    return 0;
}
