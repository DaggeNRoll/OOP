#include <iostream>

using namespace std;

class time {
    int hours, minutes, seconds;
public:
    time() {//конструктор по-умолчанию
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    time(int x, int y, int z) {//конструктор с тремя аргументами
        hours = x;
        minutes = y;
        seconds = z;
    }

    void output() const {//вывод
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    time operator+(time);//перегрузка операции +

    time operator++();//перегрузка префиксного инкремента

    time operator++(int);//перегрузка постфиксного инкремента

    time operator--();//перегрузка префексного декремента

    time operator--(int);//перегрузка постфиксного декремента

};

time time::operator+(time t2) {
    time temp;
    temp.hours = hours + t2.hours;
    temp.minutes = minutes + t2.minutes;
    temp.seconds = seconds + t2.seconds;
    return temp;
}

time time::operator++() {
    return time(++hours, ++minutes, ++seconds);
}

time time::operator++(int) {
    return time(hours++, minutes++, seconds++);
}

time time::operator--() {
    return time(--hours, --minutes, --seconds);
}

time time::operator--(int) {
    return time(hours--, minutes--, seconds--);
}

int main() {
    int h, m, s;
    char waste;
    cout << "Enter time 1:" << endl;
    cin >> h >> waste >> m >> waste >> s;
    time t1(h, m, s);
    cout << "Enter time 2:" << endl;
    cin >> h >> waste >> m >> waste >> s;
    time t2(h, m, s);
    time t3 = t1 + t2;
    t3.output();

    t3 = ++t1 + t2++;
    cout << "++t1 + t2++ = ";
    t3.output();

    t3 = --t1 + t2--;
    cout << "--t1 + t2-- = ";
    t3.output();

    return 0;
}
