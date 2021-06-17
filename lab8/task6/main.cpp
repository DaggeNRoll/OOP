#include <iostream>
#include <process.h> // для функции exit

using namespace std;

const int LIMIT = 100; // размер массива

class safearray
{
private:
    int arr[LIMIT];
public:

    // обратите внимание, что функция возвращает ссылку!
    int& operator[](int n)
    {
        if(n < 0 || n >= LIMIT)
        { cout << "\nОшибочный индекс!"; exit(1); }
        return arr[n];
    }
};

class safehilo:safearray{
    int min,max;
public:
    safehilo(int x, int y):min(x),max(y){}

    int& operator[](int n){
        if (n<min || n>= max){
            cout << "\nОшибочный индекс!";
            exit(1);
        }
        else safearray::operator[](n);
    }
};

int main()
{

    safehilo sa1(0,6);
    // задаем значения элементов
    for(int j = 0; j < 6; j++)
        sa1[j] = j * 10; // используем функцию слева от знака =
    // показываем элементы
    for(int j = 0; j < 6; j++)
    {
        int temp = sa1[j]; // используем функцию справа от знака =
        cout << "Элемент " << j << " равен " << temp << endl;
    }
    return 0;
}