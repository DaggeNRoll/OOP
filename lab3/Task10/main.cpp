#include <iostream>

using namespace std;

struct sterling {
    int pounds, shillings, pence;
};//���������� ��������� ��� �������� �����

int main() {
    double sum;
    sterling oldSum;//���������� ����������� ����������
    cout << "Enter the sum using new pounds:" << endl;
    cin >> sum;

    oldSum.pence = static_cast<int>(sum * 12 * 20);//�������������� ����� ��� ������������ ����� ������
    oldSum.shillings = oldSum.pence / 12;
    oldSum.pence %= 12;
    oldSum.pounds = oldSum.shillings / 20;
    oldSum.shillings %= 20;

    cout << "This sum in old pounds is " << oldSum.pounds << " pounds "
         << oldSum.shillings << " shillings " << oldSum.pence << " pennies";

    return 0;
}
