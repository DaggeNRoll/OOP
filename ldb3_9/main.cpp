#include <iostream>

using namespace std;

struct time{//���������� ��������� ��� �������� �������
    int hours,minutes,seconds;
};

int main() {
    time t1;//���������� ���������� ������������ ����
    cout << "Enter the quantity of hours, minutes and seconds:" << endl;
    cin >> t1.hours >> t1.minutes >> t1.seconds;
    long totalsecs = t1.hours*3600+t1.minutes*60+t1.seconds;//���������� ���-�� ������ �� �������
    cout << "This is " << totalsecs << " seconds" << endl;
    return 0;
}
