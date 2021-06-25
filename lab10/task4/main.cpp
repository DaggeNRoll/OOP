#include <iostream>

using namespace std;

class Array // ���������� ������� ������ C++
{
private:
    int *ptr; // ��������� �� ���������� Array
    int size; // ������ Array
public:
    Array(int s) // ����������� � ����� ����������
    {
        size = s; // �������� - ������ Array
        ptr = new int[s]; // �������� ������ ��� Array
    }

    Array(Array &arr) {
        size = arr.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++) {
            *(ptr + i) = *(arr.ptr + i);
        }
    }

    ~Array() // ����������
    {
        delete[] ptr;
    }

    int &operator[](int j) // ������������� ��������
    // ������ ��������
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
    const int ASIZE = 10; // ������ �������
    Array arr(ASIZE); // ������� ������
    for(int j = 0; j < ASIZE; j++) // ��������� ��� j^2
        arr[j] = j*j;
    for(int j = 0; j < ASIZE; j++) // ������� ��� ����������
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