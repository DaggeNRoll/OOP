#include <iostream>
#include <cmath>

using namespace std;

class coords{
public:
    float x,y;
    coords(){}

    coords(float a, float b){
        x=a;
        y=b;
    }

    coords operator+(coords c2){
        return coords(x+c2.x,y+c2.y);
    }
};

class polar{
    float r,f;
public:
    polar(){}

    polar(float x, float y){
        r=x;
        f=y;
    }

    void input(){
        cout << "Enter coords" << endl;
        cout << "radius = ";
        cin >> r;
        cout << "\nangle = ";
        cin >> f;
        cout << endl;
    };

    void output()const{
        cout << "Coords:" << endl;
        cout << "Radius = " << r << endl;
        cout << "Angle = " << f << endl;
    }

    polar operator+(polar p2){
        coords temp1, temp2, temp3;
        temp1.x=r*cos(f);
        temp1.y=r*sin(f);
        temp2.x=p2.r*(cos(p2.f));
        temp2.y=p2.r*(cos(p2.f));
        temp3=temp1+temp2;
        return polar(sqrt(temp3.x*temp3.x+temp3.y*temp3.y), atan(temp3.y/temp3.x));
    }
};

int main(){
    polar a,b,c;
    a.input();
    b.input();

    c=a+b;
    c.output();

    return 0;
}