#include <iostream>
#include <conio.h>

using namespace std;
//перегрузка функции для разных входных данных
double power(float n, int p = 2) {
    for (int i = 2; i <= p; i++) {//вычисление степени умножением
        n *= n;
    }
    return n;
}

double power(int n, int p = 2) {
    for (int i = 2; i <= p; i++) {
        n *= n;
    }
    return n;
}

double power(char n, int p = 2) {
    double n1 =  n - '0';
    for (int i = 2; i <= p; i++) {
        n1 *= n1;
    }
    return n1;
}

long power(long n, int p = 2) {
    for (int i = 2; i <= p; i++) {
        n *= n;
    }
    return n;
}

int main() {
    char ch, op;
    int p;
    cout << "What type of n do you want to use? (f = float, i = integer, c = char, l = long)" << endl;
    cin >> op;
    switch (op) {//ветвление для разных типов данных
        case 'f':
            float n;
            cout << "Enter n: " << endl;
            cin >> n;
            cout << "Would you like to enter p? (y/n) " << endl;
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter p" << endl;
                cin >> p;
                cout << "Answer is " << power(n, p);
            } else
                cout << "Answer is " << power(n);
            break;
        case 'i':
            int n1;
            cout << "Enter n: " << endl;
            cin >> n1;
            cout << "Would you like to enter p? (y/n) " << endl;
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter p" << endl;
                cin >> p;
                cout << "Answer is " << power(n1, p);
            } else
                cout << "Answer is " << power(n1);
            break;
        case 'c':
            char n2;
            cout << "Enter n: " << endl;
            cin >> n2;
            cout << "Would you like to enter p? (y/n) " << endl;
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter p" << endl;
                cin >> p;
                cout << "Answer is " << power(n2, p);
            } else
                cout << "Answer is " << power(n2);
            break;
        case 'l':
            long n3;
            cout << "Enter n: " << endl;
            cin >> n3;
            cout << "Would you like to enter p? (y/n) " << endl;
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter p" << endl;
                cin >> p;
                cout << "Answer is " << power(n3, p);
            } else
                cout << "Answer is " << power(n3);
            break;
    }
    return 0;
}

