#include <iostream>
using namespace std;
#include <string.h> // для функций str*


class String
{
protected:
    enum { SZ = 80 }; // размер массива
    char str[SZ]; // массив для хранения строки
public:
    // конструктор без параметров
    String()
    { str[0] = '\0'; }
    // конструктор с одним параметром
    String(char s[])
    { strcpy(str, s); } // сохраняем строку в массиве
    // показ строки
    void display() const
    { cout << str << endl; }
    // перевод строки к обычному типу
    operator char*()
    { return str; }
};

class Pstring:public String{
public:
    Pstring():String(){}

    Pstring(char s[]):String(test(s)){}

private:
    char* test(char s[]){
        if (strlen(s) >= SZ) {
            char temp[SZ];
            int i;
            for (i = 0; i < SZ - 1; i++) {
                temp[i] = s[i];
            }
            temp[i] = '\0';
            return temp;
        }
        else{
            return s;
        }
    }

};

class Pstring2:public Pstring{
public:
    Pstring2():Pstring(){}

    Pstring2(char s[]):Pstring(s){}

    Pstring2& left(Pstring2 const &s, int n){//s - объект, не требующий измененения, лучше передавать
        //по константной ссылке
        for (int i = 0; i<n; i++ ){
            str[i]=s.str[i];
        }
        str[n]='\0';
        return *this;//возврат ссылки на сам объект
    }

    Pstring2& mid(Pstring2 const &s, int x, int n){
        for (int i=x;i<x+n;i++){
            str[i-x]=s.str[i];
        }
        str[n]='\0';
        return *this;
    }

    Pstring2& right(Pstring2 const &s, int n){
        for (int i=strlen(s.str)-n; i<strlen(s.str); i++){
            str[i-(strlen(s.str)-n)]=s.str[i];
        }
        str[n]='\0';
        return *this;
    }

};

int main()
{
    Pstring2 s1("abcdefghijklmno"), s2;
    s2.left(s1,4);
    s2.display();
    s2.mid(s1, 3, 5);
    s2.display();
    s2.right(s1,4);
    s2.display();
    return 0;
}