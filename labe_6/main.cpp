#include <iostream>

using namespace std;
//���������� ������������
enum etype{laborer, secretary, manager, accountant, executive, researcher};

int main() {
    etype worker;//���������� ���������� ���� etype
    char c;
    cout << "Enter the first letter of the position" << endl;
    cout <<"(laborer, secretary, manager, accountant, executive, researcher)" << endl;
    cin >> c;

    switch(c){//���������� ���������� ���� etype �������� ���������
        case 'l':
            worker=laborer;
            break;
        case 's':
            worker=secretary;
            break;
        case 'm':
            worker = manager;
            break;
        case 'a':
            worker=accountant;
            break;
        case 'e':
            worker=executive;
            break;
        case 'r':
            worker=researcher;
            break;
    }
    cout << "full position name: ";
    switch(worker){//����� ������ ��������� �� �����
        case laborer:
            cout << "laborer" << endl;
            break;
        case secretary:
            cout << "secretary" << endl;
            break;
        case manager:
            cout << "manager" << endl;
            break;
        case accountant:
            cout << "accountant" << endl;
            break;
        case executive:
            cout << "executive" << endl;
            break;
        case researcher:
            cout << "researcher" << endl;
            break;
    }
    return 0;
}
