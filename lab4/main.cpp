#include <iostream>
#include <conio.h>

using namespace std;

long hms_to_secs(int,int,int);

int main(){
    int h,m,s;
    char ch='y';
    do{
        cout << "Enter hours, minutes and seconds" << endl;
        cin >> h >> m >> s;
        cout << "Total seconds: " << hms_to_secs(h,m,s) << endl;
        cout << "Do you want to continue? (y/n)" << endl;
    } while (ch==_getch());
    return 0;
}

long hms_to_secs(int h,int m,int s){
    s+=(h*60+m)*60;
    return static_cast<long>(s);
}
