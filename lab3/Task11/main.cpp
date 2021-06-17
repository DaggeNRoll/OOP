#include <iostream>

using namespace std;

struct time {
    int hours, minutes, seconds;
};//объявление структуры для хранения времени

int main() {
    time t1, t2, t3;
    char waste;//для игнорирования ":"
    cout << "Enter the first time" << endl;
    cin >> t1.hours >> waste >> t1.minutes >> waste >> t1.seconds;
    cout << "Enter the second time" << endl;
    cin >> t2.hours >> waste >> t2.minutes >> waste >> t2.seconds;
    int seconds = ((t1.hours + t2.hours) * 60 + t1.minutes + t2.minutes) * 60 + t1.seconds + t2.seconds;
    //вычисляет общее количество секунд
    int minutes = seconds / 60;//выделяет минуты из общего количества секунд
    seconds %= 60;//оставшееся количество секунд
    int hours = (minutes / 60) % 13;//выделяет часы
    minutes %= 60;//оставшееся количество секунд
    cout << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " + "
         << t2.hours << ":" << t2.minutes << ":" << t2.seconds << " = "
         << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}
