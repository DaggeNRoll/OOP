#include <iostream>

using namespace std;

class queue {
private:
    static const int max = 2;//границы массива
    int a[max];
    int head;
    int tail;
public:
    queue() {//инициализация хвоста и головы
        head = 0;
        tail = 0;
    }

    void put(int x)//помещение в очередь и проверка выхода за размер массива
    {
        a[tail++] = x;
        if (tail == max) //при max-1 не добавляло в последний элемент
            tail = -1;
    }

    int get() {//изъятие элемента и проверка выхода за границы массива
        return a[head++];
        if (head == max - 1)
            head = 0;
    }
};

int main() {
    queue q;
    q.put(3);//помещение 3х элементов
    q.put(4);
    q.put(5);

    cout << q.get() << endl;//вывод элемента
    cout << q.get() << endl;
}