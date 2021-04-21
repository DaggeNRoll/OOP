#include <iostream>

using namespace std;

enum etype {
    manager, junior, middle, senior
};

class date {
public:
    int month, day, year;

    date() {}

    void input() {
        cout << "Enter a month:" << endl;
        cin >> month;
        cout << "Enter a day:" << endl;
        cin >> day;
        cout << "Enter a year:" << endl;
        cin >> year;
    }

    void output() {
        cout << month << "/" << day << "/" << year << "." << endl;
    }
};

class employee {
    int id;
    float wage;
    date d;
    etype post;
public:
    employee() {}

    void getemploy() {
        cout << "Enter  worker's id and wage:" << endl;
        cin >> id >> wage;
        cout << "Enter the date of employment." << endl;
        d.input();
        cout << "Enter his(her) post (m = manager, j=junior, d = middle, s = senior:" << endl;
        char ch;
        cin >> ch;
        switch (ch) {
            case 'm':
                post = manager;
                break;
            case 'j':
                post = junior;
                break;
            case 'd':
                post = middle;
                break;
            case 's':
                post = senior;
                break;
        }
    }

    void putemploy() {
        cout << "An employee with the id \"" << id << "\" have been working here since ";
        d.output();
        cout << "He(she) works as a ";
        switch (post) {
            case manager:
                cout << "manager";
                break;
            case junior:
                cout << "junior";
                break;
            case middle:
                cout << "middle";
                break;
            case senior:
                cout << "senior";
                break;
        }
        cout << " and costs us " << wage << " money." << endl;
    }
};

int main() {
    employee e1, e2, e3;
    cout << "Tell me about the first employee." << endl;
    e1.getemploy();
    cout << "Tell me about the second employee." << endl;
    e2.getemploy();
    cout << "Tell me about the third employee." << endl;
    e3.getemploy();
    e1.putemploy();
    e2.putemploy();
    e3.putemploy();
    return 0;
}
