#include <iostream>
using namespace std;
#include <process.h> // для exit()

struct Pair{int x,y;};

class Stack
{
protected: // Замечание: использовать private нельзя
    enum { MAX = 3 }; // размер стека
    int st[MAX]; // данные, хранящиеся в стеке
    int top; // индекс последнего элемента в стеке
public:
    Stack() // конструктор
    { top = -1; }
    void push(int var) // помещение числа в стек
    { st[++top] = var; }
    int pop() // извлечение числа из стека
    { return st[top--]; }
};

class Stack2 : public Stack
{
public:
    void push(int var) // помещение числа в стек
    {
        if(top >= MAX - 1) // если стек полон, то ошибка
        { cout << "\nОшибка: стек полон"; exit(1); }
        Stack::push(var); // вызов функции push класса Stack
    }
    int pop() // извлечение числа из стека
    {
        if(top < 0) // если стек пуст, то ошибка
        { cout << "\nОшибка: стек пуст\n"; exit(1); }
        return Stack::pop(); // вызов функции pop класса Stack(можно без return)
    }
};

class pairStack:public Stack2{

public:
    void push(Pair &pair){
        Stack2::push(pair.x);
        Stack2::push(pair.y);
    }

    Pair pop(){
        Pair temp;
        temp.y=Stack2::pop();
        temp.x=Stack2::pop();
        return temp;
    }
};

int main(){
    Pair p1={3,4},p2;
    pairStack st;
    st.push(p1);
    p2=st.pop();
    cout << p2.x << " " << p2.y;

    return 0;
}