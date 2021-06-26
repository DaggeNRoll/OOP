#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////

struct link // ���� ������� ������
{
    int data; // ��������� ������
    link *next; // ��������� �� ��������� ���������
};

///////////////////////////////////////////////////////////
class linklist // ������
{
private:
    link *first;
public:
    linklist() // ����������� ��� ����������
    { first = NULL; } // ������� �������� ���� ���
    linklist(linklist& oldLinkList){//����������� �����������
        first=NULL;//����� ������ ���� ����
        link* newlink=oldLinkList.first;//�������� � ������� ��������

        while(newlink){//���� ������ �� ��������, �������� � ����� ��� ��������
            additem(newlink->data);
            newlink=newlink->next;
        }
    }

    void additem(int d); // ���������� ��������

    void display(); // ����� ������

    ~linklist() {
        while (first) {//���� ������ �� ��������
            link *nextDel = first->next;//�������� ��������� �� ��������� �������
            link *nextDelNext = NULL;
            if (first->next) {//�������� ��������� �� �����-��������� �������
                nextDelNext = first->next->next;//�������� �� ������� ���������
            }
            cout << first->data << " is deleting" << endl;
            delete first;//��������� ������� �������
            first = nextDel;//��������� �� ������� ���������� ���������
            if (nextDelNext) {//�������� �� ������� ���������
                first->next = nextDelNext;//��������� �� ��������� ���������� �����-���������
            }
        }
        cout << "This linklist has been deleted" << endl;
    }

    linklist operator=(linklist &oldLinkList) {//���������� ��������� ������������
        if (this == &oldLinkList) {//�������� �������������� ������ ����
            return *this;
        }

        link *newlink = first;//�������� ������ ������� �������, ���� �� ����� �� ����� ������
        while (newlink) {
            first = newlink->next;
            delete newlink;
            newlink = first;
        }
//�������� ������ �������� ������ ������ � �������� � ���� �������� ������� ������
        newlink = oldLinkList.first;
        while (newlink) {
            additem(newlink->data);
            newlink = newlink->next;
        }
        return *this;
    }
};

///////////////////////////////////////////////////////////
void linklist::additem(int d) // ���������� ��������
{
    link *newlink = new link; // �������� ������
    newlink->data = d; // ���������� ������
    newlink->next = first; // ���������� �������� first
    first = newlink; // first ������ ��������� �� ����� �������
}

///////////////////////////////////////////////////////////
void linklist::display() {
    link *current = first; // �������� � ������� ��������
    while (current) // ���� ���� ������
    {
        cout << current->data << endl; // �������� ������
        current = current->next; // ��������� � ���������� ��������
    }
}

int main() {
    linklist newLinkList;
    newLinkList.additem(1);
    newLinkList.additem(2);
    newLinkList.additem(3);
    newLinkList.additem(4);

    newLinkList.display();

    linklist newLinkList2;
    newLinkList2 = newLinkList;

    newLinkList2.display();

    return 0;
}