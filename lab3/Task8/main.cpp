#include <iostream>

using namespace std;

struct fraction{
    int numerator;
    int denominator;
};//��������� ��������� ��� �������� ������

int main() {
    fraction f1,f2;//���������� ���������� ������������ ����
    char c;//����� ��� ������������� ����� �������
    cout << "Enter the first fraction:" << endl;
    cin >> f1.numerator >> c >> f1.denominator;
    cout << "Enter the second fraction:" << endl;
    cin >> f2.numerator >> c >> f2.denominator;
    cout << f1.numerator << "/" << f1.denominator << " + "
        << f2.numerator << "/" << f2.denominator << " = "
        << f1.numerator*f2.denominator+f2.numerator*f1.denominator << "/"
        << f1.denominator*f2.denominator;//���������� ���������� �� �������� �������� ������
    return 0;
}
