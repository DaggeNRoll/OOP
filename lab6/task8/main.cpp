#include <iostream>
#include <stdlib.h>//для exit

using namespace std;

class safearray{
    static const int LIMIT = 10;//размер массива
    int arr[LIMIT];
public:
    safearray(){//инициализация массива нулями в конструкторе
        for (int i=0;i<LIMIT;i++){
            arr[i]=0;
        }
    }
    void putel(int id, int number){
        if(id<LIMIT){//если индекс входит в массив, он записывается в массив
            arr[id]=number;
        }
        else{//если возможен выход за пределы массива, программа выходит с кодом ошибки
            cout << "Invalid index!!!" << endl;
            exit(EXIT_FAILURE);
        }
    }
    int getel(int id)const{
        if (id<LIMIT){//если индекс верен, то возвращается элемент по этому индексу
            return arr[id];
        }
        else{//если элемент не входит в пределы массива, программа выходит с кодом ошибки
            cout << "Invalid index!!!" << endl;
            exit(EXIT_FAILURE);
        }
    }
};


int main() {
    safearray sarr;
    int id=11,temp=12345;
    sarr.putel(id,temp);//поместить элемент
    temp = sarr.getel(id);//вернуть элемент
    cout << temp << endl;//вывести возвращённый элемент
    return 0;
}
