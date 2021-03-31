#include <iostream>

using namespace std;

struct employee{
    int id;
    float wage;
};

int main() {
    employee e1,e2,e3;
    cout << "Enter the id and the wage of the 1st employee" << endl;
    cin >> e1.id >> e1.wage;
    cout << "Enter the id and the wage of the 2nd employee" << endl;
    cin >> e2.id >> e2.wage;
    cout << "Enter the id and the wage of the 3rd employee" << endl;
    cin >> e3.id >> e3.wage;

    cout << "The employee with id " << e1.id <<" costs us " << e1.wage << "$" << endl;
    cout << "The employee with id " << e2.id <<" costs us " << e2.wage << "$" << endl;
    cout << "The employee with id " << e3.id <<" costs us " << e3.wage << "$" << endl;
    return 0;
}
