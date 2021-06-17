#include <iostream>

using namespace std;

class date{//класс с трем€ пол€ми int
    int month,day,year;
public:
    date(){}//конструктор по-умолчанию
    void input(){//метод класса дл€ ввода
        cout << "Enter a month:" << endl;
        cin >> month;
        cout << "Enter a day:" << endl;
        cin >> day;
        cout << "Enter a year:" << endl;
        cin >> year;
    }
    void output()const{//константный метод класса д€л вывода
        cout << "You've entered " << month << "/" << day << "/" << year << endl;
    }
};


int main() {
    date d1;//объ€вление объекта
    d1.input();//ввод полей объекта с помощью метода класса
    d1.output();//вывод полей объекта с помощью метода класса

    return 0;
}
