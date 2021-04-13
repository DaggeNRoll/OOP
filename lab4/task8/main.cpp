#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int main() {
    int a,b;
    cout << "Enter a and b" << endl;
    cin >> a >> b;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "SWAP!" << endl;
    swap(a,b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}
