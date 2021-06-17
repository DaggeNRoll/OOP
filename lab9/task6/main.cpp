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
    while (*s1 && *s2){//пока не кончитс€ хот€ бы одна из строк
        if (*s1>*s2){//если символ первой больше
            return 1;
        }else if(*s1<*s2){//если символ второй больше
            return -1;
        }
        s1++;
        s2++;
    }
    //на случай если достигнут конец одной из строк, либо конец обеих и они
    //совпадают посимвольно
    if (!(*s1||*s2)){//если совпадают
        return 0;
    } else if(!*s1){//если перва€ короче, а посимвольно совпадают
        return -1;
    } else{//если втора€ короче, а посимвольно совпадают
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
