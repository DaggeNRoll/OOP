#include <iostream>

using namespace std;

struct time {
    int hours, minutes, seconds;
};//���������� ��������� ��� �������� �������

int main() {
    time t1, t2, t3;
    char waste;//��� ������������� ":"
    cout << "Enter the first time" << endl;
    cin >> t1.hours >> waste >> t1.minutes >> waste >> t1.seconds;
    cout << "Enter the second time" << endl;
    cin >> t2.hours >> waste >> t2.minutes >> waste >> t2.seconds;
    int seconds = ((t1.hours + t2.hours) * 60 + t1.minutes + t2.minutes) * 60 + t1.seconds + t2.seconds;
    //��������� ����� ���������� ������
    int minutes = seconds / 60;//�������� ������ �� ������ ���������� ������
    seconds %= 60;//���������� ���������� ������
    int hours = (minutes / 60) % 13;//�������� ����
    minutes %= 60;//���������� ���������� ������
    cout << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " + "
         << t2.hours << ":" << t2.minutes << ":" << t2.seconds << " = "
         << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}
