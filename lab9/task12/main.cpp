#include <iostream>

using namespace std;

char address[999];
float fmemory[100];
int pmemory[100];
int pmem_top = 0;
int fmem_top = 0;

class Float {
    int addr;//индекс fmemory
public:
    Float(float f) {
        fmemory[fmem_top] = f;//сохранение значения в память
        addr = fmem_top;//запонимаем адрес в памяти
        fmem_top++;//изменяем индекс, указывающий на свободное место
        //в памяти
    }

    int operator&() {//перегрузка взятия адреса
        return addr;
    }
};

class ptrFloat {
    int addr;//индекс в pmemory
public:
    ptrFloat(int x) {
        pmemory[pmem_top] = x;
        addr = pmem_top;
        pmem_top++;
    }

    float &operator*() {//перегрузка разыменования
        return fmemory[pmemory[addr]];
    }
};

int main() {
    Float var1 = 1.234; // определяем и инициализируем
    Float var2 = 5.678; // две вещественные переменные
    ptrFloat ptr1 = &var1; // определяем и инициализируем
    ptrFloat ptr2 = &var2; // два указателя
    cout << " *ptr1 = " << *ptr1; // получаем значения переменных
    cout << " *ptr2 = " << *ptr2; // и выводим на экран
    *ptr1 = 7.123; // присваиваем новые значения
    *ptr2 = 8.456; // переменным, адресованным через указатели
    cout << " *ptr1 = " << *ptr1; // снова получаем значения
    cout << " *ptr2 = " << *ptr2; // и выводим на экран

    return 0;
}
