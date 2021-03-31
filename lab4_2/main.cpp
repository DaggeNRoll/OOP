#include <iostream>

using namespace std;

struct point{
   int x;
   int y;
};
int main() {
    point p1,p2;
    cout << "p1: " << endl;
    cin >> p1.x >> p1.y;
    cout << "p2: " << endl;
    cin >> p2.x >> p2.y;
    cout << "p1+p2= " << p1.x+p2.x << " " << p1.y+p2.y << endl;
    return 0;
}
