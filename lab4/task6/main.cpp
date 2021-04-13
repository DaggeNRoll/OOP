#include <iostream>

using namespace std;

struct time {
    int hours,minutes,seconds;
};

long time_to_secs(time);

time secs_to_time(long);

int main() {
    time t1, t2, t3;
    char waste;//для игнорирования ":"
    cout << "Enter the first time" << endl;
    cin >> t1.hours >> waste >> t1.minutes >> waste >> t1.seconds;
    cout << "Enter the second time" << endl;
    cin >> t2.hours >> waste >> t2.minutes >> waste >> t2.seconds;
    t3.seconds = ((t1.hours + t2.hours) * 60 + t1.minutes + t2.minutes) * 60 + t1.seconds + t2.seconds;
    //вычисляет общее количество секунд
    t3.minutes = t3.seconds / 60;//выделяет минуты из общего количества секунд
    t3.seconds %= 60;//оставшееся количество секунд
    t3.hours = (t3.minutes / 60) % 13;//выделяет часы
    t3.minutes %= 60;//оставшееся количество секунд
    cout << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " + "
         << t2.hours << ":" << t2.minutes << ":" << t2.seconds << " = "
         << time_to_secs(t3) << " seconds = " << t3.hours << ":" << t3.minutes <<":" << t3.seconds;
    return 0;
}

long time_to_secs(time t){
    return (t.hours*60+t.minutes)*60+t.seconds*60;
}

time secs_to_time(long s){
    time t3;
    t3.minutes = t3.seconds / 60;//выделяет минуты из общего количества секунд
    t3.seconds %= 60;//оставшееся количество секунд
    t3.hours = (t3.minutes / 60) % 13;//выделяет часы
    t3.minutes %= 60;//оставшееся количество секунд
    return t3;
}
