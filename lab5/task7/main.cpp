#include <iostream>

using namespace std;

class angle{//структура с полями int,float,char
    int degrees;
    float minutes;
    char direction;
public:
    angle(int de, float m, char di)://конструктор с аргументами int,float,char
        degrees(de), minutes(m), direction(di)
    {}
    void input(){//метод ввода
        cout << "Enter coords:" << endl;
        cin >> degrees >>  minutes >>  direction;
    }
    void output()const{//константный метод вывода
    cout << "The point is " << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};
int main() {
    int degrees=179;
    float minutes=59.9;
    char direction='E';
    angle x(degrees,minutes,direction);//инициализация полей объекта
    x.output();//вывод полей объекта с помощью метода класса
    x.input();//ввод полей объекта с помощью метода класса
    x.output();
    return 0;
}
