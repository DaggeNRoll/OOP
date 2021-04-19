#include <iostream>

using namespace std;

class angle{
    int degrees;
    float minutes;
    char direction;
public:
    angle(int de, float m, char di):
        degrees(de), minutes(m), direction(di)
    {}
    void input(){
        cout << "Enter coords:" << endl;
        cin >> degrees >>  minutes >>  direction;
    }
    void output()const{
    cout << "The point is " << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};
int main() {
    int degrees=179;
    float minutes=59.9;
    char direction='E';
    angle x(degrees,minutes,direction);
    x.output();
    x.input();
    x.output();
    return 0;
}
