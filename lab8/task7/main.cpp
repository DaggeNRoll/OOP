#include <iostream>
using namespace std;

class Counter
{
protected: // заметьте, что тут не следует использовать private
    unsigned int count; // счетчик
public:
    Counter() : count() // конструктор без параметров
    { }
    Counter(int c) : count(c) // конструктор с одним параметром
    { }
    unsigned int get_count() const // получение значения
    { return count; }
    Counter operator++() // оператор увеличения
    { return Counter(++count); }
};

class CountDn : public Counter
{
public:
    CountDn() : Counter() // конструктор без параметров
    { }
    CountDn(int c) : Counter(c) // конструктор с одним параметром
    { }
    CountDn operator--() // оператор уменьшения
    { return CountDn(--count); }
};

class CountPost : public CountDn{
public:
    CountPost():CountDn(){}
    CountPost(int c): CountDn(c){}

    CountPost operator++(int){
        return CountPost(count++);
    }

    const CountPost operator--(int){
        return CountPost(count--);
    }

    using Counter::operator++;//так как имена функций в производном классе совпадают с именами в родительском и
    //родительском родительского, происходит сокрытие данных, для использования префиксных операций необходимо
    //расширить область видимости
    using CountDn::operator--;
};

int main()
{
    CountPost c1; // переменные класса CountDn
    CountDn c2(100);
    cout << "\nc1 = " << c1.get_count();// выводим значения на экран
    cout << "\nc2 = " << c2.get_count();
    ++c1; ++c1; ++c1; // увеличиваем c1
    cout << "\nc1 = " << c1.get_count();// показываем результат
    --c2; --c2; // уменьшаем c2
    cout << "c2 = " << c2.get_count(); // показываем результат
    CountDn c3 = --c2; // создаем переменную c3 на основе c2
    cout << "\nc3 = " << c3.get_count();// показываем значение
    cout << endl;
    return 0;
}