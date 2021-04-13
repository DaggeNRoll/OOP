#include <iostream>

using namespace std;

class employee{
    int id;
    float wage;
public:
    employee()
    {}
    void input(){
        cout << "Enter id:" << endl;
        cin >> id;
        cout << "Enter wage:"<< endl;
        cin >> wage;
    }
    void output ()const{
        cout << "The employee with the id \"" << id << "\" costs us " << wage << " money" << endl;
    }
};
int main() {
    employee e1,e2,e3;
    cout << "Enter an id and wage of the first employee:" << endl;
    e1.input();
    cout << "Enter an id and wage of the second employee:" << endl;
    e2.input();
    cout << "Enter an id and wage of the third employee:" << endl;
    e3.input();
    e1.output();
    e2.output();
    e3.output();
    return 0;
}
