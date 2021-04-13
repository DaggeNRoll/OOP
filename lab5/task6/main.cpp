#include <iostream>

using namespace std;

enum etype{
    manager,  junior, middle, senior
};

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
        cout << month << "/" << day << "/" << year << endl;
    }
};

class employee{
    int id;
    float wage;
    date d;
    etype position;
public:
    employee()
    {}
    void getemploy(employee e){
        cout << "Enter id:" << endl;
        cin >> id;
        cout << "Enter wage:"<< endl;
        cin >> wage;
        cout << "Enter the date of employment." << endl;
        e.d.input();

        char c;
        cout << "Enter the first letter of the post (m = manager, j = junior, mid = middle, s = senior)." << endl;
        cin >> c;
        switch(c) {
            case 'm':
                e.position = manager;
                break;
            case 'j':
                e.position = junior;
                break;
            case 'mid':
                e.position = middle;
                break;
            case 's':
                e.position = senior;
                break;
        }
    }
    void putemploy()const{
        cout << "The employee with the id \"" << id <<"\" started his(her) work at ";
        d.output();
        cout << "He(she) is a ";
        switch(position){
            case manager:
                cout << "manager ";
                break;
            case junior:
                cout << "junior ";
                break;
            case middle:
                cout << "middle ";
                break;
            case senior:
                cout << "senior ";
                break;
        }
        cout << "and costs us " << wage << " money" << endl;
    }
};



int main() {
    employee e1,e2,e3;
    cout <<"Tell me about the first employee." << endl;
    e1.getemploy(e1);
   // cout <<"Tell me about the second employee." << endl;
    //e2.getemploy(e2);
    //cout <<"Tell me about the third employee." << endl;
    //e3.getemploy(e3);
    e1.putemploy();
    //e2.putemploy();
    //e3.putemploy();
    return 0;
}
