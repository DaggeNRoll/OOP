#include <iostream>

using namespace std;

int f() {
    static int i = 0;
    cout << "Hello world!";
    i++;
    return i;
}

int main() {
    for (int j = 1; j < 11; j++) {
        cout << "function which prints \"";
        cout << "\" " << f();
        cout << " times was used" << endl;
    }
    return 0;
}
//удобнее использовать глобальную переменную, но статическая переменная чётко связана с функцией, для которой используется
//более того, использование статической переменной - эффективнее
