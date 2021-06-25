#include <iostream>

class Token{
public:
    virtual float getNumber()const=0;
    virtual char getOperator()const=0;
};

class Operator:public Token{
    char oper;
public:
    Operator(char op):oper(op){}
    virtual char getOperator()const{//возвращает операцию
        return oper;
    }
    virtual float getNumber()const{//функция нужна только для того, чтобы класс не стал абстрактным
        //не должна вызываться объектами класса
        return 0.0f;
    }
};

class Number:public Token {
    float floatNumber;
public:
    Number(float n):floatNumber(n){}

    virtual float getNumber()const{//выдаёт значение вещественного числа
        return floatNumber;
    }

    virtual char getOperator()const{//функция нужна только для того, чтобы класс не стал абстрактным
        //не вызывается объектами самого класса
        return '0';
    }
};

class Stack{
    Token* arrtoken[100];
    int top;
public:
    Stack(){
        top=0;
    }

    void push(Token* x){//поместить токен в стек
        arrtoken[++top]=x;
    }

    Token* pop(){//забрать токен из стека
        return arrtoken[top--];
    }

    int gettop()const{//возвращает индекс вершины стека
        return top;
    }

    bool isNumber()const{//определяет, является ли токен на вершине стека вещественным числом
        //(работает, если стек не пуст)
        Number* pNum;
        return (pNum=dynamic_cast<Number*>(arrtoken[top]));
    }
};

int main(){
    Stack s;

    Number n1(7.08f), n2(10.0f);
    Operator plus('+'),mult('*');

    s.push(&n1);
    s.push(&plus);
    s.push(&n2);
    s.push(&mult);

    while (s.gettop()>0){
        if(s.isNumber()){
            std::cout << s.pop()->getNumber();
        }
        else {
            std::cout << s.pop()->getOperator();
        }
        if(s.gettop()>0){
            std::cout<<" ";
        }
    }
    std::cout<<std::endl;
}

