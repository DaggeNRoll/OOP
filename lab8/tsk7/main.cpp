// persort.cpp
// сортировка объектов через массив указателей на них
#include <iostream>
#include <string>
using namespace std;

class person // некоторый человек
{
protected:
    string name; // имя
    float salary;
public:
    void setData() // установка имени
    {
        cout << "Введите имя: " << endl;
        cin >> name;
        cout << "Введите зарплату: " << endl;
        cin >> salary;
    }
    void printData() // показ имени
    {
        cout << endl << name << endl;
        cout << endl << salary << endl;
    }
    string getName() // получение имени
    {
        return name;
    }
    float getSalary(){
        return salary;
    }
};

int main()
{
    void bsort(person**, int); // прототип функции
    void salsort(person**, int);
    person* persPtr[100]; // массив указателей на person
    int n = 0; // количество элементов в массиве
    char choice; // переменная для ввода символа
    do
    {

        persPtr[n] = new person; // создаем новый объект
        persPtr[n]->setData(); // вводим имя
        n++; // увеличиваем количество
        cout << "Продолжаем ввод (y/n)?"; // спрашиваем, закончен ли ввод
        cin >> choice;
    }
    while(choice == 'y');
    cout << "\nНеотсортированный список:";
    for(int j = 0; j < n; j++) // покажем неотсортированный список
        persPtr[j]->printData();
    bsort(persPtr, n); // отсортируем указатели
    cout << "\nОтсортированный по именам список:";
    for(int j = 0; j < n; j++) // покажем отсортированный список
        persPtr[j]->printData();
    cout << endl;
    salsort(persPtr,n);
    cout <<"Отсортированный по зарплате список:";
    for (int i=0;i<n;i++){
        persPtr[i]->printData();
    }
    
    return 0;
}

void bsort(person** pp, int n)
{
    void order(person**, person**); // прототип функции
    int j, k; // переменные для циклов
    for(j = 0; j < n - 1; j++) // внешний цикл
        for(k = j + 1; k < n; k++) // внутренний цикл
            order(pp + j, pp + k); // сортируем два элемента
}

void order(person** pp1, person** pp2)
{
    if((*pp1)->getName() > (*pp2)->getName()) // если первая строка больше второй,
    {
        person* tempptr = *pp1; // меняем их местами
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}

void salsort(person** pp, int n){
    for (int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((*pp+i)->getSalary()>(*pp+j)->getSalary()){
                swap(*(pp+i),*(pp+j));
            }
        }
    }
}