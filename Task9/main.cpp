#include <iostream>
using namespace std;

struct time{
    int h,m,s;
};

void swap(time& t1, time& t2){
    time temp;
    temp = t1;
    t1=t2;
    t2 = temp;
}

int main() {
    time t1,t2;
    char waste;
    cout << "Enter the first time:" << endl;
    cin >> t1.h >> waste >> t1.m >> waste >> t1.s;
    cout << "Enter the second time:" << endl;
    cin >> t2.h >> waste >> t2.m >> waste >> t2.s;
    cout << "t1 = " << t1.h << waste << t1.m << waste << t1.s << endl;
    cout << "t2 = " << t2.h << waste << t2.m << waste << t2.s << endl;
    cout << "SWAP!" << endl;
    swap(t1,t2);
    cout << "t1 = " << t1.h << waste << t1.m << waste << t1.s << endl;
    cout << "t2 = " << t2.h << waste << t2.m << waste << t2.s << endl;
    return 0;
}
