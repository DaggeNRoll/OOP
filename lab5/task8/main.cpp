#include <iostream>

using namespace std;

class task8{//класс с полем int и статической переменнйо типа int
    int n;
    static int count;
public:
    task8(){//конструктор, увеличивающий счётчик объектов на 1 и присваивающий номер объекта соответствующему полю
        count++;
        n=count;
    }
    void output()const{//константный метод вывода
        cout << "My serial number is " << endl;
    }
    int getcount()const{//метод, возвращающий порядковый нмоер объекта
        return n;
    }
};
int task8::count=0;//инициализация кончтвнтной переменной за телом класса
int main() {
    task8 o1,o2,o3;//обявление трёх объектов
    o1.output();//вывод методом класса
    cout << o1.getcount() << endl;//вывод порядкового номера объекта
    o2.output();
    cout << o2.getcount() << endl;
    o3.output();
    cout << o3.getcount() << endl;
    return 0;
}
