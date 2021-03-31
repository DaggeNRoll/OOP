#include <iostream>
#include <iomanip>
using namespace std;

struct date
{
    int day, month, year;
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct employee
{
    float allowance;
    int number;
    date DATE;
    etype post;
};

int P(int a);
int F(char a);

int main()
{
    int f1 = 0, f2=0, f3 = 0;
    char ch, letterPost1, letterPost2, letterPost3;
    employee emp1, emp2, emp3;
    cout << "Enter all information about emloyees ( number, allowance, post, date of employment)" << endl << "The first: " << endl;
    cin >> emp1.number;
    cout << endl;
    cin >> emp1.allowance;
    cout << endl;
    cin >> letterPost1;
    cout << endl;
    cin >> emp1.DATE.day >> ch >> emp1.DATE.month >> ch >> emp1.DATE.year;
    f1 = F(letterPost1);

    cout << endl << "The second: " << endl;
    cin >> emp2.number;
    cin >> emp2.allowance;
    cin >> letterPost2;
    cin >> emp2.DATE.day >> ch >> emp2.DATE.month >> ch >> emp2.DATE.year;
    f2 = F(letterPost2);

    cout << endl << "The third: " << endl;
    cin >> emp3.number;
    cout << endl;
    cin >> emp3.allowance;
    cout << endl;
    cin >> letterPost3;
    cout << endl;
    cin >> emp3.DATE.day >> ch >> emp3.DATE.month >> ch >> emp3.DATE.year;
    f3 = F(letterPost3);

    cout << "Information about employees: " << endl << setw(20) << "Number of eployee" << setw(20) << "Allowance" << setw(20)
         << "Post" << setw(20) << "Date of hiring" << endl;
    cout << setw(20) << emp1.number << setw(20) << emp1.allowance << setw(20) << P(f1) << setw(20)
         << emp1.DATE.day << "/" << emp1.DATE.month << "/" << emp1.DATE.year << endl;
    cout << setw(20) << emp2.number << setw(20) << emp2.allowance << setw(20) << P(f2) << setw(20)
         << emp2.DATE.day << "/" << emp2.DATE.month << "/" << emp2.DATE.year << endl;
    cout << setw(20) << emp3.number << setw(20) << emp3.allowance << setw(20) << P(f3) << setw(20)
         << emp3.DATE.day << "/" << emp3.DATE.month << "/" << emp3.DATE.year << endl;
    return 0;
}

int F(char a)
{
    int b = 0;
    switch (a)
    {
        case 'l':
            b = laborer;
            break;
        case 's':
            b = secretary;
            break;
        case 'm':
            b = manager;
            break;
        case 'a':
            b = accountant;
            break;
        case 'e':
            b = executive;
            break;
        case 'r':
            b = researcher;
            break;
    }
    return b;
}

int P(int a)
{
    switch (a)
    {
        case 0:
            cout << "laborer";
            break;
        case 1:
            cout << "secretary";
            break;
        case 2:
            cout << "manager";
            break;
        case 3:
            cout << "accountant";
            break;
        case 4:
            cout << "executive";
            break;
        case 5:
            cout << "researcher";
            break;
    }
    return 0;
}
