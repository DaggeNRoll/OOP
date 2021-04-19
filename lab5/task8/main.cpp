#include <iostream>

using namespace std;

class task8{
    int n;
    static int count;
public:
    task8(){
        count++;
        n=count;
    }
    void output()const{
        cout << "My serial number is " << endl;
    }
    int getcount()const{
        return n;
    }
};
int task8::count=0;
int main() {
    task8 o1,o2,o3;
    o1.output();
    cout << o1.getcount() << endl;
    o2.output();
    cout << o2.getcount() << endl;
    o3.output();
    cout << o3.getcount() << endl;
    return 0;
}
