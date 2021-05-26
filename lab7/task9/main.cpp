#include <iostream>
using namespace std;
#include <process.h> // для функции exit
const int LIMIT = 100; // размер массива

class safearray
{
private:
    int arr[LIMIT];
    int max,min;
public:
    safearray(int x, int y){
        min=x;
        max=y;
    }

    // обратите внимание, что функция возвращает ссылку!
    int& operator[](int n)
    {
        if(n < min || n >= max)
        { cout << "\nОшибочный индекс!"; exit(1); }
        return arr[n];
    }
};
///////////////////////////////////////////////////////////
int main()
{
    int min,max;
    cout << "Enter array limits (min max)" << endl;
    cin >> min >> max;
    safearray sa1(min,max);
    // задаем значения элементов
    for(int j = min; j < max; j++)
        sa1[j] = j * 10; // используем функцию слева от знака =
    // показываем элементы
    for(int j = min; j < max; j++)
    {
        int temp = sa1[j]; // используем функцию справа от знака =
        cout << "Элемент " << j << " равен " << temp << endl;
    }
    return 0;
}