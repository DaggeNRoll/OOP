#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////

struct link // один элемент списка
{
    int data; // некоторые данные
    link *next; // указатель на следующую структуру
};

///////////////////////////////////////////////////////////
class linklist // список
{
private:
    link *first;
public:
    linklist() // конструктор без параметров
    { first = NULL; } // первого элемента пока нет
    linklist(linklist& oldLinkList){//конструктор копирования
        first=NULL;//новый список пока пуст
        link* newlink=oldLinkList.first;//начинаем с первого элемента

        while(newlink){//пока список не кончится, копируем в новый его элементы
            additem(newlink->data);
            newlink=newlink->next;
        }
    }

    void additem(int d); // добавление элемента

    void display(); // показ данных

    ~linklist() {
        while (first) {//пока список не кончится
            link *nextDel = first->next;//копирует указатель на следующий элемент
            link *nextDelNext = NULL;
            if (first->next) {//копирует указатель на после-следующий элемент
                nextDelNext = first->next->next;//проверка на нулевой указатель
            }
            cout << first->data << " is deleting" << endl;
            delete first;//удаляется текущий элемент
            first = nextDel;//уаазатель на текущий становится следующим
            if (nextDelNext) {//проверка на нулевой указатель
                first->next = nextDelNext;//указатель на следующий становится после-следующим
            }
        }
        cout << "This linklist has been deleted" << endl;
    }

    linklist operator=(linklist &oldLinkList) {//перегрузка оператора присваивания
        if (this == &oldLinkList) {//проверка наприсваивание самому себе
            return *this;
        }

        link *newlink = first;//копирует ссылки старого объекта, пока не дойдёт до конца списка
        while (newlink) {
            first = newlink->next;
            delete newlink;
            newlink = first;
        }
//выделяет память элементы нового списка и копирует в него элементы старого списка
        newlink = oldLinkList.first;
        while (newlink) {
            additem(newlink->data);
            newlink = newlink->next;
        }
        return *this;
    }
};

///////////////////////////////////////////////////////////
void linklist::additem(int d) // добавление элемента
{
    link *newlink = new link; // выделяем память
    newlink->data = d; // запоминаем данные
    newlink->next = first; // запоминаем значение first
    first = newlink; // first теперь указывает на новый элемент
}

///////////////////////////////////////////////////////////
void linklist::display() {
    link *current = first; // начинаем с первого элемента
    while (current) // пока есть данные
    {
        cout << current->data << endl; // печатаем данные
        current = current->next; // двигаемся к следующему элементу
    }
}

int main() {
    linklist newLinkList;
    newLinkList.additem(1);
    newLinkList.additem(2);
    newLinkList.additem(3);
    newLinkList.additem(4);

    newLinkList.display();

    linklist newLinkList2;
    newLinkList2 = newLinkList;

    newLinkList2.display();

    return 0;
}