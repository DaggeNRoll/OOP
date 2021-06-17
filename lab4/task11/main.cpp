#include <iostream>

using namespace std;

struct sterling{//струткура
    int pounds, shillings, pence;
};

void input(sterling&,sterling&);//объявление функции, принимающая структурные переменные по ссылке
sterling sum(sterling, sterling);//объявленние функции структурного типа
void output(sterling);//объявление функции, принимающей структурную переменную

int main() {

    sterling m1,m2;//объявление струткурных переменных
    input(m1,m2);
    output(sum(m1,m2));
    return 0;
}

void input(sterling& m1, sterling& m2){//инициализация функции
    cout << "Enter the first amount of money:" << endl;
    cin >> m1.pounds >> m1.shillings >> m1.pence;
    cout << "Enter the second amount of money:" << endl;
    cin  >> m2.pounds >> m2.shillings >> m2.pence;
}

sterling sum(sterling m1, sterling m2){//инициализация функции
    sterling m3;//объявление локальной структурной переменной
    m3.pence=m1.pence+m2.pence;
    m3.shillings=(m1.pence+m2.pence)/12 + m1.shillings+m2.shillings;
    m3.pence%=12;
    m3.pounds=m1.pounds+m2.pounds + m3.shillings/20;
    m3.shillings%=20;
    return m3;
}

void output(sterling m3){//инициализация функции
    cout << "Answer is " << m3.pounds << " " << m3.shillings << " " << m3.pence << endl;
}
