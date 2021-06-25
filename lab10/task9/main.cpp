#include "msoftcon.h" // for console graphics
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int CPF = 5;
const int maxHorses = 7;

class track;

class comtrack;

class horse {
private:
    const track *ptrTrack;
protected:
    const int horse_number;
    float distance_run;
    float finish_time;
public:
    horse(const int n, const track *ptrT) :
            horse_number(n),
            ptrTrack(ptrT),
            distance_run(0.0) {}

    ~horse() {}

    void display_horse(const float elapsed_time);
};

class comhorse : public horse {
    const comtrack *ptrTrack;//трек нового класса
public:
    comhorse(const int n, const comtrack *ptrT) : horse(n, NULL), ptrTrack(ptrT) {}
    //null означает, что не будет использоваться объект старого класса track
    //но остальные поля будут использоваться

    void display_horse(const float elapsed_time);
};

class track {
protected:
    int horse_count;
    const float track_length;
    float elapsed_time;
public:
    track(float lenT, int nH);

    ~track();

    void display_track();

    void run();

    float get_track_len() const;

    int total_horses;
    horse *hArray[maxHorses];
};

class comtrack : public track {
    //класс нового трека
private:
    comhorse *hArray[maxHorses];//массив указателей на "лошадей"
    int horse_count;
public://конструктор с двумя аргументами (длина трека, кол-во лошадей
    comtrack(float lenT, int nH);

    ~comtrack();//деструктор
    void run();//Для запуска забега
    friend void comhorse::display_horse(float);//дружественный метод класса comhorse
};

void horse::display_horse(float elapsed_time) {
    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
    set_color(static_cast<color>(cBLUE + horse_number));
    char horse_char = '0' + static_cast<char>(horse_number);
    putch(' ');
    putch('\xDB');
    putch(horse_char);
    putch('\xDB');
// если финиш еще не достигнут
    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        // случайным образом генерируем одно из трех чисел: 0 или 1 или 2
        // в случае генерации 0 лошадь остается на месте,
        // в случае генерации 1 или 2 лошадь продвигается вперед на 0,2 фурлонга
        if (rand() % 3)
            distance_run += 0.2F;
        // запоминаем в поле finish_time для текущей лошади время, прошедшее
        // со старта забега
        finish_time = elapsed_time;
    } else // финиш достигнут
    {
        // вывести время, прошедшее со старта забега до пересечения линии финиша,
        // на экран
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        cout << " Время = " << mins << ":" << secs;
    }
}

void comhorse::display_horse(float elapsed_time) {
    // установим курсор в нужную позицию на экране:
    // координата Х зависит от длины части дистанции пройденной лошадью на данный момент;
    // координата Y зависит от номера лошади, так как лошади отображаются по порядку сверху вниз
    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);

    // все лошади отображаются разных цветов, цвет зависит от номера лошади
    set_color(static_cast<color>(cBLUE + horse_number));

    // вычисляем символ для отображения номера лошади
    wchar_t horse_char = L'0' + static_cast<wchar_t>(horse_number);

    // отображаем лошадь четырьмя символами:
    // пробел, закрашенный прямоугольник, номер лошади, закрашенный прямоугольник
    // (шестнадцатиричный код закрашенного прямоугольника в Юникоде — 2588)
    // (пробел нужен, чтобы стирать предыдущее местонахождение лошади)
    putch(' ');
    putch('\x25AD');
    putch(horse_char);
    putwch('\x2588');

    // если финиш еще не достигнут
    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        float speed = 0.2F; // скорость лошади по умолчанию (0.2 фурлонга за тик)

        // если лошадь прошла 1/3 или больше общей длины трека
        if (distance_run >= ptrTrack->get_track_len() / 3) {
            // если в гонке участвует больше одной лошади
            if (ptrTrack->total_horses > 1) {
                int Ld, Sc; // номера лошадей: лидера и идущей второй

                // сначала возьмем в качестве лидера и идущей второй
                // первые две лошади из массива (номера этих лошадей 0 и 1)
                if (ptrTrack->hArray[0]->distance_run < ptrTrack->hArray[1]->distance_run) {
                    Ld = 1;
                    Sc = 0;
                } else {
                    Ld = 0;
                    Sc = 1;
                }

                // просмотрим массив указателей на объекты-лошади, начиная с лошади под номером 2
                for (int j = 2; j < ptrTrack->total_horses; j++) {
                    if (ptrTrack->hArray[Ld]->distance_run < ptrTrack->hArray[j]->distance_run) {
                        Sc = Ld;
                        Ld = j;
                    } else if (ptrTrack->hArray[Sc]->distance_run < ptrTrack->hArray[j]->distance_run) { Sc = j; }
                }

                // если наша лошадь является лидером или идущей второй
                // (сравниваем не номера, а пройденные дистанции, из-за того, что несколько лошадей
                // могут идти вровень)
                if (distance_run == ptrTrack->hArray[Ld]->distance_run ||
                    distance_run == ptrTrack->hArray[Sc]->distance_run) {
                    // и расстояние между лидером и идущей второй не превышает 0.1 фурлонга
                    if (ptrTrack->hArray[Ld]->distance_run - ptrTrack->hArray[Sc]->distance_run <= 0.1F)
                        // временно ускорим нашу лошадь с 0.2 до 0.3 фурлонга за тик
                        speed = 0.3F;

                    // из-за временного увеличения скорости на треке должна остаться
                    // отметка в том месте, где лошадь ускорялась; я не стал пытаться ее стереть,
                    // так как посчитал это небесполезной особенностью программы (фичей)

                    // в результате этого ускорения некоторые лошади могут закончить гонку,
                    // немного переехав финишную прямую, так как проверка пересечения финиша
                    // рассчитана на скорость 0.2 фурлонга за тик
                }
            }
        }

        // случайным образом генерируем одно из трех чисел: 0 или 1 или 2
        // в случае генерации 0 лошадь остается на месте,
        // в случае генерации 1 или 2 лошадь продвигается вперед на количество фурлонгов,
        // указанное в переменной speed
        if (rand() % 3)
            distance_run += speed;
        // запоминаем в поле finish_time для текущей лошади время, прошедшее
        // со старта забега
        finish_time = elapsed_time;
    } else // финиш достигнут
    {
        // вывести время, прошедшее со старта забега до пересечения линии финиша,
        // на экран
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        wcout << L" Время = " << mins << ":" << secs;
    }
}

track::track(float lenT, int nH) :
        track_length(lenT),
        total_horses(nH),
        horse_count(0),
        elapsed_time(0.0) {
    init_graphics();
    total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
    for (int j = 0; j < total_horses; j++)
        hArray[j] = new horse(horse_count++, this);
    time_t aTime;
    srand(static_cast<unsigned>(time(&aTime)));
    display_track();
}

// конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге
// (для трека нового класса)
comtrack::comtrack(float lenT, int nH) :
        track(lenT, nH), horse_count(0) {
    // создать объекты нового класса comhorse и заполнить массив указателей на них
    for (int j = 0; j < total_horses; j++)
        hArray[j] = new comhorse(horse_count++, this);
}

track::~track() {
    for (int j = 0; j < total_horses; j++)
        delete hArray[j];
}

// деструктор (для трека нового класса)
comtrack::~comtrack() {
    // освободить память, выделенную в конструкторе под объекты-лошади нового класса
    for (int j = 0; j < total_horses; j++)
        delete hArray[j];
}

void track::display_track() {
    clear_screen();
    for (int f = 0; f <= track_length; f++)
        for (int r = 1; r <= total_horses * 2 + 1; r++) {
            set_cursor_pos(f * CPF + 5, r);
            if (f == 0 || f == track_length)
                cout << '\xDE';
            else
                cout << '\xB3';
        }
}

///////////////////////////////////////////////////////////
void track::run() {
    while (!kbhit()) {
        elapsed_time += 1.75;
        for (int j = 0; j < total_horses; j++)
            hArray[j]->display_horse(elapsed_time);
        wait(500);
    }
    getch();
    cout << endl;
}

/
метод для
запуска забега(для
трека нового
класса)

void comtrack::run() {
    // продолжать цикл до момента нажатия любой клавиши на клавиатуре
    while (!_kbhit()) {
        elapsed_time += 1.75; // увеличиваем время забега на 1,75 секунд
        // обрабатываем очередное движение каждой лошади (нового класса)
        for (int j = 0; j < total_horses; j++)
            hArray[j]->display_horse(elapsed_time);
        // функция из msoftcon.h, пауза на 500 миллисекунд
        // (то есть описанное выше увеличение времени забега elapsed_time соответствует
        // в реальном измерении интервалу времени в 500 миллисекунд)
        wait(500);
    }
    _getch(); // принять символ с клавиатуры, возникший из-за нажатия на клавишу
    cout << endl;
}

///////////////////////////////////////////////////////////
float track::get_track_len() const { return track_length; }

///////////////////////////////////////////////////////////
int main() {
    float length; // длина трека (дистанции)
    int total;    // количество лошадей, участвующих в забеге

    // получаем данные для забега от пользователя
    cout << "Введите длину дистанции (от 1 до 12 фурлонгов): ";
    cin >> length;
    cout << "Введите количество лошадей (от 1 до 7): ";
    cin >> total;
    cout << endl;

    comtrack theTrack(length, total); // создаем трек
    theTrack.run();                   // запускаем забег
    cout << endl;

    // возвратим первоначальный цвет текста в консоли
    end_graphics();

    return 0;
}