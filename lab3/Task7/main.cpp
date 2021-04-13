#include <iostream>

using namespace std;
//���������� ������������
enum etype{laborer, secretary, manager, accountant, executive, researcher};

struct date{
    int day;
    int month;
    int year;
};//���������� ��������� � ����� ������

struct employee{
    int id;
    float wage;
    etype position;
    date beginDate;
};//���������� ���������, ���������� � ���� ������������ � ������������

etype PositionIn(char c, etype worker){//������� ��� ���������� ���������� �������������� ���� �������� ���������
    switch(c){
        case 'l':
            return laborer;
            break;
        case 's':
            return secretary;
            break;
        case 'm':
            return manager;
            break;
        case 'a':
            return accountant;
            break;
        case 'e':
            return executive;
            break;
        case 'r':
            return researcher;
            break;
    }
}

void PositionOut(etype worker){//������� ��� ������ ������ ��������� �� �����
    switch(worker){
        case laborer:
            cout << "laborer. ";
            break;
        case secretary:
            cout << "secretary. ";
            break;
        case manager:
            cout << "manager. ";
            break;
        case accountant:
            cout << "accountant. ";
            break;
        case executive:
            cout << "executive. ";
            break;
        case researcher:
            cout << "researcher. ";
            break;
    }
}

int main() {
    employee w1,w2,w3;//���������� ���������� ������������ ����
    char c1,c2,c3,waste;//waste ����� ��� ������������� �����
    cout << "Enter the id, the wage, the first letter of the position name and the date of the hiring: " << endl;
    cin >> w1.id >> w1.wage >> c1 >> w1.beginDate.day >> waste >> w1.beginDate.month >> waste
        >> w1.beginDate.year;//���� ����� ���������
    cout << "Enter the id, the wage, the first letter of the position name and the date of the hiring: " << endl;
    cin >> w2.id >> w2.wage >> c2 >> w2.beginDate.day >> waste >> w2.beginDate.month >> waste
        >> w2.beginDate.year;
    cout << "Enter the id, the wage, the first letter of the position name and the date of the hiring: " << endl;
    cin >> w3.id >> w3.wage >> c3 >> w3.beginDate.day >> waste >> w3.beginDate.month >> waste
        >> w3.beginDate.year;

    w1.position = PositionIn(c1,w1.position);//����� ������� ��� ���������� �������� ���������
    w2.position = PositionIn(c2,w2.position);
    w3.position = PositionIn(c3,w3.position);

    cout << "The worker with id " << w1.id << " costs us " << w1.wage << "$ and works as a(n) ";//����� ����� ���������
    PositionOut(w1.position);//����� ���������
    cout << "He (she) was hired on " << w1.beginDate.day << "/" << w1.beginDate.month << "/"
        << w1.beginDate.year << endl;//����� ��������� ����� ���������
    cout << "The worker with id " << w2.id << " costs us " << w2.wage << "$ and works as a(n) ";
    PositionOut(w2.position);
    cout << "He (she) was hired on " << w2.beginDate.day << "/" << w2.beginDate.month << "/"
         << w2.beginDate.year << endl;
    cout << "The worker with id " << w3.id << " costs us " << w3.wage << "$ and works as a(n) ";
    PositionOut(w3.position);
    cout << "He (she) was hired on " << w3.beginDate.day << "/" << w3.beginDate.month << "/"
         << w3.beginDate.year << endl;

    return 0;
}
