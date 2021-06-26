#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 80; // ������������ ����� ��������������� ��������� (� ��������)
const int MAX = 40; // ������ �����

class Token // ����������� ������� �����

{
public:
    virtual float getNumber() const = 0;     // ������ ����������� �������
    virtual char getOperator() const = 0;
};

class Operator : public Token // �����, �������������� ����� ��������������� ���������
{
private:
    char oper; // ���� �������������� ��������
public:
    Operator(char op) : oper(op) // ����������� � ����� ����������
    { }
    char getOperator() const     // ����� ������ ���� ��������
    { return oper; }
    float getNumber() const // ��������� ������� (����� ������, ����� ������ �����
    { return 0.0f; }    // �� ���� �����������, ��� �������� ������� ������
    // �� ������ ����������)
};

class Number : public Token // �����, �������������� ����� ������������� �����
{
private:
    float fnum; // ������������ �����
public:
    Number(float n) : fnum(n)       // ����������� � ����� ����������
    { }
    float getNumber() const         // ����� ������ �������� ������������� �����
    { return fnum; }
    char getOperator() const // ��������� ������� (����� ������, ����� ������ �����
    { return L'0'; }        // �� ���� �����������, ��� �������� ������� ������
    // �� ������ ����������)
};

class Stack // �����, ����������� ����
{
private:
    Token* atoken[MAX]; // ���� � ���� ������� ���������� �� ������

    int top;            // ������, ����������� �� ������� �����
public:
    Stack()                // ����������� ��� ����������
    { top = 0; }
    void push(Token* var)  // ��������� ����� � ����
    { atoken[++top] = var; }
    Token* pop()           // ������� ����� �� �����
    { return atoken[top--]; }
    int gettop() const     // �������� ������, ����������� �� ������� �����
    { return top; }
    bool isNumber() const  // ����� ����������, �������� �� ����� �� ������� �����
    {                      // ������������ ������ (��������, ������ ���� ���� �� ����)
        // (����������� RTTI � ����������� ������ ���� ��������)
        Number* pNum;
        if (pNum = dynamic_cast<Number*>(atoken[top]))
            return true;
        else
            return false;
    }
};

class express // �����, �������������� �������������� ���������
{
private:
    Stack s;       // ���� ��� ������� ��������������� ���������
    char* pStr; // ��������� �� �������� ������ � �������������� ����������
    int len;       // ����� �������� ������
public:
    express(char* ptr) // ����������� � ����� ����������
    {
        pStr = ptr;         // ���������� ��������� �� �������� ������
        len = strlen(pStr); // ���������� ����� �������� ������
    }
    void parse();  // ������ (�������) �������� ������ � �������������� ����������
    float solve(); // ���������� ��������������� ���������, ����������� � �����
};


void express::parse()
{
    wchar_t ch;     // ������ �� �������� ������ � �������������� ����������
    Token* lastval; // ��������� ���������� � ���� ����� (�������)
    Token* lastop;  // ��������� ���������� � ���� ���� ��������

    float ans;      // ��� ������������ �����
    Number* ptrN;   // ��� ���������� �� ������-�����
    Operator* ptrO; // ��� ���������� �� ������-��������

    // ��������� �� ������� ������������� ������� � ������ � �������������� ����������
    // (�������� ������ � ������ ���� ������)
    char* pCurrent = pStr;

    while (pCurrent[0]) // ���� �� ��������� ����� ������������� ������
    {
        // ������� ������ �� ������� ������������� ������� � ������ � �������������� ����������
        ch = pCurrent[0];

        if (ch >= '0' && ch <= '9') // ���� ��� �����,
        {
            ans = stof(pCurrent, &pCurrent); // ������� �� ������ ������������ �����
            // (��������� pCurrent ����������� �� ��������� �����)
            ptrN = new Number(ans);            // ������� ������ ��� �����-�����
            s.push(ptrN);                      // �������� ����� � ����
        }
            // ���� ��� ���� �������������� ��������
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (s.gettop() == 1) // ���� ��� ������ � ��������� ���� ��������,
            {
                ptrO = new Operator(ch); // ������� ������ ��� �����-��������
                s.push(ptrO);            // �������� ����� � ����
            }
            else // ��� �� ������ � ��������� ���� ��������
            {
                lastval = s.pop(); // �������� ���������� � ������� �����-�������
                lastop = s.pop();  // �������� ���������� � ������� ���� ��������
                // ���� ��� ���� �������� * ��� /, � ���������� ��� + ��� -, ��
                if ((ch == '*' || ch == '/') &&
                    (lastop->getOperator() == '+' || lastop->getOperator() == '-'))
                {
                    s.push(lastop);  // �������� ��������� ��� ������ �� �����
                    s.push(lastval);
                }
                else // �� ���� ������ �������
                {
                    // �������� ���������� �������� � �������� ��������� � ����
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
                        default: wcout << "\n����������� ���� ��������\n"; exit(1);
                    }
                }
                Operator* ptrO = new Operator(ch); // ������� ������ ��� �����-��������
                s.push(ptrO);                      // �������� ����� � ����
            }
            pCurrent++; // ��������� pCurrent ����������� �� ��������� �����
        }
        else // ���� ������ �� �������� �� ������������ ������, �� ������ ��������
        { wcout << "\n������������� ������ � �������������� ���������\n"; exit(1); }
    }
}

// ���������� ��������������� ���������, ����������� � �����
// (����� ���� ���� �������� ������)
float express::solve()
{
    Token* lastval; // ��������� ���������� � ���� ����� (�������)

    float ans;    // ��� ������������ �����
    Number* ptrN; // ��� ���������� �� ������-�����

    while (s.gettop() > 1) // ���� � ����� �� ��������� ��������� ����������
    {                      // ������ ��������������� ���������,
        lastval = s.pop(); // ������� ��������� � ������� �����-�������
        switch (s.pop()->getOperator()) // ������� ��������� � ������� ���� ��������
        {                  // �������� �������� � �������� ��������� � ����
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
            default: wcout << "\n����������� ���� ��������\n"; exit(1);
        }
    }

    return s.pop()->getNumber(); // � ����� ������� ��������� ���������� ���������,
    // �������� ��� � ����������; ���� �������� ������
}

int main() {


    char ans;
    char string[LEN]; // ������ � �������������� ���������� ��� ������� (��������)

    do {
        cout << "\n������� ���������: "; // �������� ������ �� ������������ (����� ��������� �������),

        cin.get(string, LEN);   // �������������� ����� �� ������ cin ������� ���������� �������
        // (�������, �������� ������, ���������)

        express *eptr = new express(string);  // ������� ������-��������� ��� �������

        eptr->parse();                        // ��������� ������ (�������) ���������
        // (������ �� ���� ����� ������ ������ �� ������
        // �������� � ���������, � �� ������)

        cout << "��������� ���������� ���������: "
              << eptr->solve();               // �������� ��������� ����������

        delete eptr;                          // ������� ������-���������

        wcout << "\n��� ���� ��������� (y/n)? ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}