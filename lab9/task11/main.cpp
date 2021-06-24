#include <iostream>

using namespace std;

const int n = 10;

class suparr {
    int *ptr[n];
public:
    suparr() {
        for (int i = 0; i < n; i++) {
            *(ptr + i) = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                *(*(ptr + i) + j) = 0;
            }
        }
    }

    ~suparr() {
        for (int i = 0; i < n; i++) {
            delete[] *(ptr + i);
        }
    }

    int &operator[](int);
};

int &suparr::operator[](int n) {
    int x = n / 10;
    return *(*(ptr + x) + n % 10);
}

int main() {
    suparr arr;

    arr[1]=10;
    arr[11]=20;
    arr[31]=300;

    for (int i = 0; i < 50; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}