#include <iostream>

class Distance // ����� ���������� ����
{
private:
    int feet;
    float inches;
public: // ����� ���������� ����
    Distance() : feet(0), inches(0.0) // ����������� (��� ����������)
    {}

    // ����������� (2 ���������)
    Distance(int ft, float in) : feet(ft), inches(in) {}

    Distance(double x) {
        feet = static_cast<int>(x);
        inches = 12 * (x - feet);
    }

    void showdist() const // ������� ����������
    {
        std::cout << feet << "\'-" << inches << '\"';
    }

    friend float square(Distance); // ������������� �-���

    friend Distance operator*(Distance d1, Distance d2);
};

float square(Distance d) // ������� �������
{ // ����������
    float fltfeet = d.feet + d.inches / 12;// �������������� � float
    float feetsqrd = fltfeet * fltfeet; // ��������� �������
    return feetsqrd; // ������� ���������� ����
}

Distance operator*(Distance d1, Distance d2) {
    int feet = d1.feet * d2.feet;
    float inches = d1.inches * d2.inches;
    if (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
    return Distance(feet, inches);
}

int main() {
    Distance d1(3, 3), d2(4, 4), d3;

    d3 = d1 * d2;
    std::cout << "d1*d2=";
    d3.showdist();
    std::cout << std::endl;

    d3 = 7.5 * d1;
    std::cout << "7.5*d1=";
    d3.showdist();
    std::cout << std::endl;

    d3 = d1 * 7.5;
    std::cout << "d1*7.5=";
    d3.showdist();
    std::cout << std::endl;

    return 0;
}