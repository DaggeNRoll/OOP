#include <iostream>

using namespace std;

struct date{//���������� ��������� � ����� ������
    int day;
    int month;
    int year;
};

int main() {
    date d;//���������� ���������� ���� date
    char c;
    cout << "Enter the date (like 31/12/2002)"<< endl;
    cin >> d.day >> c >> d.month >> c >> d.year;//���������� ����� ���������
    cout << "You've entered: " << d.day << '/' << d.month << "/" << d.year << endl;
    //����� ����� ��������� � �������
    return 0;
}
