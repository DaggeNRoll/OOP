#include <iostream>

using namespace std;

class queue
{
private:
    static const int max = 2;
    int a[max];
    int head;
    int tail;
public:
    queue()
    {
        head = 0;
        tail = 0;
    }
    void put(int x)
    {
        a[tail++] = x;
        if (tail == max) //при max-1 не добавляло в последний элемент
            tail = -1;
    }
    int get()
    {
        return a[head++];
        if (head == max-1)
            head = 0;
    }
};
int main()
{
    queue q;
    q.put(3);
    q.put(4);
    q.put(5);

    cout << q.get() << endl;
    cout << q.get() << endl;
}