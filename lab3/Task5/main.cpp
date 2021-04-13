#include <iostream>

using namespace std;

struct date{//объ€вление структуры с трем€ пол€ми
    int day;
    int month;
    int year;
};

int main() {
    date d;//объ€вление переменной типа date
    char c;
    cout << "Enter the date (like 31/12/2002)"<< endl;
    cin >> d.day >> c >> d.month >> c >> d.year;//считывание полей структуры
    cout << "You've entered: " << d.day << '/' << d.month << "/" << d.year << endl;
    //вывод полей структуры в консоль
    return 0;
}
