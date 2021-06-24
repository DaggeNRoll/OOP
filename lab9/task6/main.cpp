#include <iostream>
using namespace std;

int strcmp(const char*, const char*);

void output(int);

int main() {
   const char *s1,*s2, *s3;
   s1="Ivanov";
   s2="Smith";
   s3="Smith";
    output(strcmp(s1,s2));
    output(strcmp(s2,s1));
    output(strcmp(s2,s3));

    return 0;
}

int strcmp(const char* s1, const char* s2){
    while (*s1 && *s2){//���� �� �������� ���� �� ���� �� �����
        if (*s1>*s2){//���� ������ ������ ������
            return 1;
        }else if(*s1<*s2){//���� ������ ������ ������
            return -1;
        }
        s1++;
        s2++;
    }
    //�� ������ ���� ��������� ����� ����� �� �����, ���� ����� ����� � ���
    //��������� �����������
    if (!(*s1||*s2)){//���� ���������
        return 0;
    } else if(!*s1){//���� ������ ������, � ����������� ���������
        return -1;
    } else{//���� ������ ������, � ����������� ���������
        return 1;
    }
}

void output(int x){
    switch(x){
        case 0:
            cout << "equal" << endl;
            break;
        case 1:
            cout << "The first is bigger" << endl;
            break;
        case -1:
            cout << "The second is bigger" << endl;
            break;
    }
}
