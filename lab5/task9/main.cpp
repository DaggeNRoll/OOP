#include <iostream>
#include <conio.h>

using namespace std;

class fraction{
    int numerator, denominator;
public:
    fraction(){}
    void input(){
        char waste;
        cout << "Enter fraction:" << endl;
        cin >> numerator >> waste >> denominator;
    }
    void output()const{
        cout << "The answer is " << numerator << "/" << denominator << endl;
    }
    void sum(fraction f1, fraction f2){
        numerator=f1.numerator*f2.denominator + f1.denominator*f2.numerator;
        denominator = f1.denominator*f2.denominator;
    }
};

int main() {
    char ch = 'y';
    fraction f1,f2,f3;
    do {
        f1.input();
        f2.input();
        f3.sum(f1,f2);
        f3.output();
        cout << "Do you want to continue? (y/n)" << endl;
    } while(ch == _getch());
    return 0;
}
