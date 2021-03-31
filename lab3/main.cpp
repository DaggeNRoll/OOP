#include <iostream>

using namespace std;

struct phone {
    int cCode;
    int stCode;
    int number;
};
int main() {
    phone n1 = {212, 767, 8900}, n2;
    cout << "Enter the code of a city, a station number and a caller's number" << endl;
    cin >> n2.cCode >> n2.stCode >> n2.number;
    cout << "My number " << "(" << n1.cCode << ") " << n1.stCode << "-" << n1.number << endl;
    cout << n2.cCode << " " << n2.stCode << " " << n2.number;
    return 0;
}
