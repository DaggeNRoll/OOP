#include <iostream>
#include <cmath>

using namespace std;

class coords {//для декартовых координат
public:
    float x, y;

    coords() {}//конструктор по-умолчанию

    coords(float a, float b) {//конструктор с двумя аргументами
        x = a;
        y = b;
    }

    coords operator+(coords c2) {//перегрузка coords+coords
        return coords(x + c2.x, y + c2.y);
    }
};

class polar {
    float r, f;
public:
    polar() {}//конструктор по-умолчанию

    polar(float x, float y) {//конструктор с двумя аргументами
        r = x;
        f = y;
    }

    void input() {
        cout << "Enter coords" << endl;
        cout << "radius = ";
        cin >> r;
        cout << "\nangle = ";
        cin >> f;
        cout << endl;
    };

    void output() const {
        cout << "Coords:" << endl;
        cout << "Radius = " << r << endl;
        cout << "Angle = " << f << endl;
    }

    polar operator+(polar p2) {//перегрузка polar+polar
        coords temp1, temp2, temp3;
        temp1.x = r * cos(f);//перевод из полярных в декартовы
        temp1.y = r * sin(f);
        temp2.x = p2.r * (cos(p2.f));
        temp2.y = p2.r * (cos(p2.f));
        temp3 = temp1 + temp2;
        return polar(sqrt(temp3.x * temp3.x + temp3.y * temp3.y), atan(temp3.y / temp3.x));
        //перевод из декартовых в полярные
    }
};

int main() {
    polar a, b, c;
    a.input();
    b.input();

    c = a + b;
    c.output();

    return 0;
}