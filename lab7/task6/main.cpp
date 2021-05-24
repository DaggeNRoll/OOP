#include <iostream>
#include <cmath>

using namespace std;

class time {
    int hours, minutes, seconds;
public:
    time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    time(int x, int y, int z) {
        hours = x;
        minutes = y;
        seconds = z;
    }

    void output() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    time operator+(time);

    time operator++();

    time operator++(int);

    time operator--();

    time operator--(int);

    time operator-(time);

    time operator*(float);

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

time time::operator-(time t2) {
    return time(hours - t2.hours, minutes - t2.minutes, seconds - t2.seconds);
}

time time::operator*(float d) {
    return time(round(hours * d), round(minutes * d), round(seconds * d));
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

    cout << "t1 = ";
    t1.output();
    cout << "t2 = ";
    t2.output();
    t3 = ++t1 + t2++;
    cout << "++t1 + t2++ = ";
    t3.output();

    cout << "t1 = ";
    t1.output();
    cout << "t2 = ";
    t2.output();
    t3 = --t1 + t2--;
    cout << "--t1 + t2-- = ";
    t3.output();

    cout << "t1 = ";
    t1.output();
    cout << "t2 = ";
    t2.output();
    t3 = t2 - t1;
    cout << "t2 - t1 = ";
    t3.output();

    cout << "t1 = ";
    t1.output();
    t3 = t1 * 1.5;
    cout << "t1 * 1.5 = ";
    t3.output();

    return 0;
}
