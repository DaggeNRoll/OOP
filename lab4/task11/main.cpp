#include <iostream>

using namespace std;

struct sterling{
    int pounds, shillings, pence;
};

void input(sterling&,sterling&);
sterling sum(sterling, sterling);
void output(sterling);

int main() {

    sterling m1,m2;
    input(m1,m2);
    output(sum(m1,m2));
    return 0;
}

void input(sterling& m1, sterling& m2){
    cout << "Enter the first amount of money:" << endl;
    cin >> m1.pounds >> m1.shillings >> m1.pence;
    cout << "Enter the second amount of money:" << endl;
    cin  >> m2.pounds >> m2.shillings >> m2.pence;
}

sterling sum(sterling m1, sterling m2){
    sterling m3;
    m3.pence=m1.pence+m2.pence;
    m3.shillings=(m1.pence+m2.pence)/12 + m1.shillings+m2.shillings;
    m3.pence%=12;
    m3.pounds=m1.pounds+m2.pounds + m3.shillings/20;
    m3.shillings%=20;
    return m3;
}

void output(sterling m3){
    cout << "Answer is " << m3.pounds << " " << m3.shillings << " " << m3.pence << endl;
}
