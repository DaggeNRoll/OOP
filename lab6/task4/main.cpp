#include <iostream>
using namespace std;
const int MAX = 10;//размер массива

void maxint(int[MAX],const int);//описание функции

int main() {
    int arr[MAX];//объявление массива
    cout << "Enter the elements of the array: " << endl;
    for (int i=0;i<MAX;i++){//ввод элементов массива
        cin >> arr[i];
    }
    maxint(arr,MAX);//вызов функции, выводящей максимальный элемент
    return 0;
}

void maxint(int arr[MAX],const int MAX){
    int max = arr[0];//инициализация максимума первым элементом массива
    int n=0;//номер максимума в массиве
    for (int i = 1;i<MAX;i++){
        if (arr[i]>max){//сравнение текущего элемента с максимальным
            max=arr[i];
            n=i;
        }
    }
    cout << "The largest element is " << max << " and has id " << n << endl;
}
