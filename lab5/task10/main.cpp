#include <iostream>

using namespace std;

class angle {//����� �� ������� 7
    int degrees;
    float minutes;
    char direction;
public:
    angle() {}

    void input() {
        cout << "Enter coords:" << endl;
        cin >> degrees >> minutes >> direction;
    }

    void output() const {
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

class ship {//����� ����� int, ����������� ���������� int (�������), ����� ��������� ������ angle
    static int count;
    int id;
    angle x, y;
public:
    ship() {//�����������, ���������������� ������� �������� � ������������� ������������ ���� ������� ��� �����
        count++;
        id = count;
    }

    void input() {//����� �����
        cout << "\nEnter information about the ship:" << endl;
        cout << "X" << endl;
        x.input();//����� ����� ������ angle
        cout << "Y" << endl;
        y.input();
    }

    void output() const {//����� ������
        cout << "\nShip with id " << id << endl;
        cout << "X: ";
        x.output();//����� ������ ������ angle
        cout << "Y: ";
        y.output();
    }

};

int ship::count = 0;//������������� ����������� ���������� ��� ���� ������

int main() {
    ship s1, s2, s3;//���������� ��� ��������
    s1.input();//���� � ������� ������ ������
    s2.input();
    s3.input();
    s1.output();//����� � ������� ������ ������
    s2.output();
    s3.output();
    return 0;
}
