#include <iostream>

using namespace std;

int k=0;

void f(){
    cout << "Hello world!" << endl;
    k++;
}

int main() {
    for (int i=1; i<11; i++){
        f();
    }
    cout << "Function was used " << k << " times" << endl;
    return 0;
}
