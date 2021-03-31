#include <iostream>

using namespace std;

struct employee{//объ€вление структуры с двум€€ пол€ми
    int id;
    float wage;
};

int main() {
    employee w1,w2,w3;//объ€вление переменных типа employee
    cout << "Enter the id and the wage of the first worker:" << endl;
    cin >> w1.id >> w1.wage;//считывание полей структуры с клавиатуры
    cout << "Enter the id and the wage of the second worker:" << endl;
    cin >> w2.id >> w2.wage;
    cout << "Enter the id and the wage of the third worker:" << endl;
    cin >> w3.id >> w3.wage;

    cout << "The worker with id " << w1.id << " costs us " << w1.wage << "$" << endl;
    cout << "The worker with id " << w2.id << " costs us " << w2.wage << "$" << endl;
    cout << "The worker with id " << w3.id << " costs us " << w3.wage << "$" << endl;
    //вывод полей структуры в консоль
    return 0;
}
