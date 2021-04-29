#include <iostream>

using namespace std;

class angle {//класс из задани€ 7
    int degrees;
    float minutes;
    char direction;
public:
    angle() {}

    void input() {
        cout << "Enter coords:" << endl;
        cin >> degrees >> minutes >> direction;
    }

    void output() const {
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

class ship {//класс полем int, статической переменной int (счЄтчик), двум€ объектами класса angle
    static int count;
    int id;
    angle x, y;
public:
    ship() {//конструктор, инкрементирующий счЄтчик объектов и присваивающий специальному полю объекта его номер
        count++;
        id = count;
    }

    void input() {//метод ввода
        cout << "\nEnter information about the ship:" << endl;
        cout << "X" << endl;
        x.input();//метод ввода класса angle
        cout << "Y" << endl;
        y.input();
    }

    void output() const {//метод вывода
        cout << "\nShip with id " << id << endl;
        cout << "X: ";
        x.output();//метод вывода класса angle
        cout << "Y: ";
        y.output();
    }

};

int ship::count = 0;//инициализаци€ статической переменнйо вне тела класса

int main() {
    ship s1, s2, s3;//объ€вление трЄх объектов
    s1.input();//ввод с помощью метода класса
    s2.input();
    s3.input();
    s1.output();//вывод с помощью метода класса
    s2.output();
    s3.output();
    return 0;
}
