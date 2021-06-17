#include <iostream>
using namespace std;

const int LEN = 80; // максимальная длина имени

enum Period{hourly, weekly, monthly};

class employee // некий сотрудник
{
private:
    char name[LEN]; // имя сотрудника
    unsigned long number; // номер сотрудника
public:
    void getdata()
    {
        cout << "\n Введите фамилию: ";
        cin >> name;
        cout << " Введите номер: ";
        cin >> number;
    }
    void putdata() const
    {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
    }
};

class employee2:employee{
private:double compensation;
    Period period;
public:
    void getdata(){
        employee::getdata();
        cout << "Enter the compensation:" << endl;
        cin >> compensation;
        cout << "Enter the period(h=hourly/w=weekly/m=monthly):" << endl;
        char c;
        cin >> c;
        switch(c){
            case 'w':
                period = weekly;
                break;
            case 'h':
                period=hourly;
                break;
            case 'm':
                period = monthly;
                break;
        }
    }

    void putdata()const{
        employee::putdata();
        cout << "The compensation is " << compensation << endl;
        cout << "The period is ";

        switch(period){
            case hourly:
                cout << "hourly" << endl;
                break;
            case weekly:
                cout << "weekly" << endl;
                break;
            case monthly:
                cout << "monthly" << endl;
                break;
        }
    }
};

class manager : public employee2 // менеджер
{
private:
    char title[LEN]; // должность, например вице-президент
    double dues; // сумма взносов в гольф-клуб
public:
    void getdata()
    {
        employee2::getdata();
        cout << " Введите должность: ";
        cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: ";
        cin >> dues;
    }
    void putdata() const
    {
        employee2::putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
    }
};

class scientist : public employee2 // ученый
{
private:
    int pubs; // количество публикаций
public:
    void getdata()
    {
        employee2::getdata();
        cout << " Введите количество публикаций: ";
        cin >> pubs;
    }
    void putdata() const
    {
        employee2::putdata();
        cout << "\n Количество публикаций: " << pubs;
    }
};


class laborer : public employee2 // рабочий
{
};



int main()
{
    manager m1, m2;
    scientist s1;
    laborer l1;
    // введем информацию о нескольких сотрудниках
    cout << endl;
    cout << "\nВвод информации о первом менеджере";
    m1.getdata();
    cout << "\nВвод информации о втором менеджере";
    m2.getdata();
    cout << "\nВвод информации о первом ученом";
    s1.getdata();
    cout << "\nВвод информации о первом рабочем";
    l1.getdata();
    // выведем полученную информацию на экран
    cout << "\nИнформация о первом менеджере";
    m1.putdata();
    cout << "\nИнформация о втором менеджере";
    m2.putdata();
    cout << "\nИнформация о первом ученом";
    s1.putdata();
    cout << "\nИнформация о первом рабочем";
    l1.putdata();
    cout << endl;
    return 0;
}