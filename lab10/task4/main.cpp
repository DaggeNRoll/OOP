#include <iostream>

using namespace std;

class Array // моделирует обычный массив C++
{
private:
    int *ptr; // указатель на содержимое Array
    int size; // размер Array
public:
    Array(int s) // конструктор с одним аргументом
    {
        size = s; // аргумент - размер Array
        ptr = new int[s]; // выделить память под Array
    }

    Array(Array &arr) {
        size = arr.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++) {
            *(ptr + i) = *(arr.ptr + i);
        }
    }

    ~Array() // деструктор
    {
        delete[] ptr;
    }

    int &operator[](int j) // перегружаемая операция
    // списка индексов
    {
        return *(ptr + j);
    }

    Array operator=(Array &arr) {
        for (int i = 0; i < size; i++) {
            *(ptr + i) = (i < arr.size) ? *(arr.ptr + i) : 0;
        }
        return *this;
    }
};

int main()
{
    const int ASIZE = 10; // размер массива
    Array arr(ASIZE); // создать массив
    for(int j = 0; j < ASIZE; j++) // заполнить его j^2
        arr[j] = j*j;
    for(int j = 0; j < ASIZE; j++) // вывести его содержимое
        cout << arr[j] << ' ';
    cout << endl;

    Array arr2(arr),arr3(ASIZE);
    arr3=arr;
    for(int i =0;i<ASIZE;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    for (int i=0;i<ASIZE;i++){
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}