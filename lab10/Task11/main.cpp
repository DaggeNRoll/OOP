#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 80; // максимальная длина арифметического выражения (в символах)
const int MAX = 40; // размер стека

class Token // абстрактный базовый класс

{
public:
    virtual float getNumber() const = 0;     // чистые виртуальные функции
    virtual char getOperator() const = 0;
};

class Operator : public Token // класс, представляющий токен «арифметическая операция»
{
private:
    char oper; // знак арифметической операции
public:
    Operator(char op) : oper(op) // конструктор с одним аргументом
    { }
    char getOperator() const     // метод выдает знак операции
    { return oper; }
    float getNumber() const // фиктивная функция (нужна только, чтобы данный класс
    { return 0.0f; }    // не стал абстрактным, для объектов данного класса
    // не должна вызываться)
};

class Number : public Token // класс, представляющий токен «вещественное число»
{
private:
    float fnum; // вещественное число
public:
    Number(float n) : fnum(n)       // конструктор с одним аргументом
    { }
    float getNumber() const         // метод выдает значение вещественного числа
    { return fnum; }
    char getOperator() const // фиктивная функция (нужна только, чтобы данный класс
    { return L'0'; }        // не стал абстрактным, для объектов данного класса
    // не должна вызываться)
};

class Stack // класс, реализующий стек
{
private:
    Token* atoken[MAX]; // стек в виде массива указателей на токены

    int top;            // индекс, указывающий на вершину стека
public:
    Stack()                // конструктор без аргументов
    { top = 0; }
    void push(Token* var)  // поместить токен в стек
    { atoken[++top] = var; }
    Token* pop()           // забрать токен из стека
    { return atoken[top--]; }
    int gettop() const     // получить индекс, указывающий на вершину стека
    { return top; }
    bool isNumber() const  // метод определяет, является ли токен на вершине стека
    {                      // вещественным числом (работает, только если стек не пуст)
        // (возможность RTTI в компиляторе должна быть включена)
        Number* pNum;
        if (pNum = dynamic_cast<Number*>(atoken[top]))
            return true;
        else
            return false;
    }
};

class express // класс, представляющий арифметическое выражение
{
private:
    Stack s;       // стек для анализа арифметического выражения
    char* pStr; // указатель на заданную строку с арифметическим выражением
    int len;       // длина заданной строки
public:
    express(char* ptr) // конструктор с одним аргументом
    {
        pStr = ptr;         // запоминаем указатель на заданную строку
        len = strlen(pStr); // запоминаем длину заданной строки
    }
    void parse();  // разбор (парсинг) заданной строки с арифметическим выражением
    float solve(); // вычисление арифметического выражения, оставшегося в стеке
};


void express::parse()
{
    wchar_t ch;     // символ из заданной строки с арифметическим выражением
    Token* lastval; // последнее помещенное в стек число (операнд)
    Token* lastop;  // последний помещенный в стек знак операции

    float ans;      // для вещественных чисел
    Number* ptrN;   // для указателей на токены-числа
    Operator* ptrO; // для указателей на токены-операции

    // указатель на текущую анализируемую позицию в строке с арифметическим выражением
    // (начинаем анализ с начала этой строки)
    char* pCurrent = pStr;

    while (pCurrent[0]) // пока не достигнут конец анализируемой строки
    {
        // получим символ из текущей анализируемой позиции в строке с арифметическим выражением
        ch = pCurrent[0];

        if (ch >= '0' && ch <= '9') // если это цифра,
        {
            ans = stof(pCurrent, &pCurrent); // получим из строки вещественное число
            // (указатель pCurrent передвигаем на следующий токен)
            ptrN = new Number(ans);            // выделим память под токен-число
            s.push(ptrN);                      // поместим токен в стек
        }
            // если это знак арифметической операции
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (s.gettop() == 1) // если это первый в выражении знак операции,
            {
                ptrO = new Operator(ch); // выделим память под токен-операцию
                s.push(ptrO);            // поместим токен в стек
            }
            else // это не первый в выражении знак операции
            {
                lastval = s.pop(); // получаем предыдущее в анализе число-операнд
                lastop = s.pop();  // получаем предыдущий в анализе знак операции
                // если наш знак операции * или /, а предыдущий был + или -, то
                if ((ch == '*' || ch == '/') &&
                    (lastop->getOperator() == '+' || lastop->getOperator() == '-'))
                {
                    s.push(lastop);  // отменяем последние два взятия из стека
                    s.push(lastval);
                }
                else // во всех других случаях
                {
                    // выполним предыдущую операцию и поместим результат в стек
                    switch (lastop->getOperator())
                    {
                        case '+':
                            ans = s.pop()->getNumber() + lastval->getNumber();
                            ptrN = new Number(ans);
                            s.push(ptrN);
                            break;
                        case '-':
                            ans = s.pop()->getNumber() - lastval->getNumber();
                            ptrN = new Number(ans);
                            s.push(ptrN);
                            break;
                        case '*':
                            ans = s.pop()->getNumber() * lastval->getNumber();
                            ptrN = new Number(ans);
                            s.push(ptrN);
                            break;
                        case '/':
                            ans = s.pop()->getNumber() / lastval->getNumber();
                            ptrN = new Number(ans);
                            s.push(ptrN);
                            break;
                        default: wcout << "\nНеизвестный знак операции\n"; exit(1);
                    }
                }
                Operator* ptrO = new Operator(ch); // выделим память под токен-операцию
                s.push(ptrO);                      // поместим токен в стек
            }
            pCurrent++; // указатель pCurrent передвигаем на следующий токен
        }
        else // если символ не является ни вещественным числом, ни знаком операции
        { wcout << "\nНеразрешенный символ в арифметическом выражении\n"; exit(1); }
    }
}

// вычисление арифметического выражения, оставшегося в стеке
// (после чего стек остается пустым)
float express::solve()
{
    Token* lastval; // последнее помещенное в стек число (операнд)

    float ans;    // для вещественных чисел
    Number* ptrN; // для указателей на токены-числа

    while (s.gettop() > 1) // пока в стеке не останется результат вычисления
    {                      // нашего арифметического выражения,
        lastval = s.pop(); // получим последнее в анализе число-операнд
        switch (s.pop()->getOperator()) // получим последний в анализе знак операции
        {                  // выполним операцию и поместим результат в стек
            case '+':
                ans = s.pop()->getNumber() + lastval->getNumber();
                ptrN = new Number(ans);
                s.push(ptrN);
                break;
            case L'-':
                ans = s.pop()->getNumber() - lastval->getNumber();
                ptrN = new Number(ans);
                s.push(ptrN);
                break;
            case '*':
                ans = s.pop()->getNumber() * lastval->getNumber();
                ptrN = new Number(ans);
                s.push(ptrN);
                break;
            case '/':
                ans = s.pop()->getNumber() / lastval->getNumber();
                ptrN = new Number(ans);
                s.push(ptrN);
                break;
            default: wcout << "\nНеизвестный знак операции\n"; exit(1);
        }
    }

    return s.pop()->getNumber(); // в стеке остался результат вычисления выражения,
    // забираем его и возвращаем; стек остается пустым
}

int main() {


    char ans;
    char string[LEN]; // строка с арифметическим выражением для разбора (парсинга)

    do {
        cout << "\nВведите выражение: "; // получаем строку от пользователя (может содержать пробелы),

        cin.get(string, LEN);   // предварительно убрав из потока cin ведущие пробельные символы
        // (пробелы, переводы строки, табуляция)

        express *eptr = new express(string);  // создаем объект-выражение для разбора

        eptr->parse();                        // выполняем разбор (парсинг) выражения
        // (только на этом этапе выдаем ошибку по поводу
        // пробелов в выражении, а не раньше)

        cout << "Результат вычисления выражения: "
              << eptr->solve();               // получаем результат вычисления

        delete eptr;                          // удаляем объект-выражение

        wcout << "\nЕще одно выражение (y/n)? ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}