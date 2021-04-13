#include <iostream>

using namespace std;

class date{
    int month,day,year;
public:
    date(){}
    void input(){
        cout << "Enter a month:" << endl;
        cin >> month;
        cout << "Enter a day:" << endl;
        cin >> day;
        cout << "Enter a year:" << endl;
        cin >> year;
    }
    void output()const{
        cout << "You've entered " << month << "/" << day << "/" << year << endl;
    }
};


int main() {
    date d1;
    d1.input();
    d1.output();

    return 0;
}
