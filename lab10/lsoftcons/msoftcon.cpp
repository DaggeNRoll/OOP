// �������� ����� ��������� �������� � ��������� UTF-8 � ����������

// msoftcon.cpp
// ������� ���������� ������� �� ������� ������
// (� ��� ������������ ���������� ������� Windows)

#include "msoftcon.h"

HANDLE hConsole;   // ���������� �������
wchar_t fill_char; // ������ ����������
CONSOLE_SCREEN_BUFFER_INFO info; // ���������� � ���������� �������

//---------------------------------------------------------
void init_graphics()
{
    COORD console_size = { 80, 25 };
    // ������� ����� �����/������ �� �������
    hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,
                          FILE_SHARE_READ | FILE_SHARE_WRITE,
                          0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
    // ���������� ������ ������ 80 x 25
    SetConsoleScreenBufferSize(hConsole, console_size);

    // ����� ����� �� �������
    // (���������������, ��� ��� � ������� ���� ����� �� ���������)
    // SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

    // �������� �������������� ��������� �������
    GetConsoleScreenBufferInfo(hConsole, &info);

    fill_char = L'\x2588'; // ���������� �� ���������
    clear_screen();
}

//---------------------------------------------------------
// ��������� �������� ������ (��. ������������ color � ����� "msoftcon.h"):
// 0 ������           8 �����-�����
// 1 �����-�����      9 �����
// 2 �����-�������   10 �������
// 3 �����-�������   11 �������
// 4 �����-�������   12 �������
// 5 �����-��������� 13 ���������
// 6 ����������      14 ������
// 7 ������-�����    15 �����
void set_color(color foreground, color background)
{
    SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | foreground));
}

//---------------------------------------------------------
// ������� ������� ���, ����� ���������� ������� ���� ��������������,
// ��� ��� �� ������ ����� ������� ���� ����� ���������� (0, 0).
// ��������, ���� ��������� ��������� ��������� ��� �� ��������� ������,
// ��� ������ �������, � �������, ���������� Y ������ ���� ������
// �� ������ ������� ���������� ������ ��������� � ��� �����.
void set_cursor_pos(int x, int y)
{
    COORD cursor_pos;                               // ������ � ������� ����� ����
    cursor_pos.X = info.dwCursorPosition.X + x - 1; // Windows �������� � (0, 0)
    cursor_pos.Y = info.dwCursorPosition.Y + y - 1; // �� ������ � (1, 1)
    SetConsoleCursorPosition(hConsole, cursor_pos);
}

//---------------------------------------------------------
void clear_screen()
{
    set_cursor_pos(1, 1);
    for (int j = 0; j < 25; j++)
        _putwch(L'\n');
    set_cursor_pos(1, 1);
}

//---------------------------------------------------------
void wait(int milliseconds)
{
    Sleep(milliseconds);
}

//---------------------------------------------------------
void clear_line() // ������� �� ����� ������ (80 ��������)
{
    //........1234567890123456789012345678901234567890
    //........0........1.........2.........3.........4
    _cputws(L"                                        ");
    _cputws(L"                                        ");
}

//---------------------------------------------------------
void draw_rectangle(int left, int top, int right, int bottom)
{
    wchar_t temp[80];
    int width = right - left + 1;

    for (int j = 0; j < width; j++) // ������ ��������������
        temp[j] = fill_char;
    temp[width] = 0;                // null (������� ��������� ������)

    for (int y = top; y <= bottom; y++) // ������� ��������� �����
    {                                   // ��������� �������������
        set_cursor_pos(left, y);
        _cputws(temp);
    }
}

//---------------------------------------------------------
void draw_circle(int xC, int yC, int radius)
{
    double theta, increment, xF, pi = 3.14159;
    int x, xN, yN;

    increment = 0.8 / static_cast<double>(radius);
    for (theta = 0; theta <= pi / 2; theta += increment) // 1/4 �����
    {
        xF = radius * cos(theta);
        xN = static_cast<int>(xF * 2 / 1); // ������� �� ���������� :-(
        yN = static_cast<int>(radius * sin(theta) + 0.5);
        x = xC - xN;
        while (x <= xC + xN) // ��������� ��� �������������� �����
        {                    // �� ����� �� ������ ��������� �����
            set_cursor_pos(x, yC - yN); _putwch(fill_char);   // ����
            set_cursor_pos(x++, yC + yN); _putwch(fill_char); // ���
        }
    }
}

//---------------------------------------------------------
void draw_line(int x1, int y1, int x2, int y2)
{
    int w, z, t, w1, w2, z1, z2;
    double xDelta = x1 - x2, yDelta = y1 - y2, slope;
    bool isMoreHoriz;

    if (fabs(xDelta) > fabs(yDelta)) // ����� � �������������� �����
    {
        isMoreHoriz = true;
        slope = yDelta / xDelta;
        w1 = x1; z1 = y1; w2 = x2, z2 = y2; // w=x, z=y
    }
    else                             // ����� � ������������ �����
    {
        isMoreHoriz = false;
        slope = xDelta / yDelta;
        w1 = y1; z1 = x1; w2 = y2, z2 = x2; // w=y, z=x
    }

    if (w1 > w2)                 // ���� �� w
    {
        t = w1; w1 = w2; w2 = t; // �������� ������� (w1,z1)
        t = z1; z1 = z2; z2 = t; //                � (w2,z2)
    }

    for (w = w1; w <= w2; w++)
    {
        z = static_cast<int>(z1 + slope * (w - w1));
        if (!(w == 80 && z == 25)) // ������ ��������� �� 80,25
        {
            if (isMoreHoriz)
                set_cursor_pos(w, z);
            else
                set_cursor_pos(z, w);
            _putwch(fill_char);
        }
    }
}

//---------------------------------------------------------
void draw_pyramid(int x1, int y1, int height)
{
    int x, y;
    for (y = y1; y < y1 + height; y++)
    {
        int incr = y - y1;
        for (x = x1 - incr; x <= x1 + incr; x++)
        {
            set_cursor_pos(x, y);
            _putwch(fill_char);
        }
    }
}

//---------------------------------------------------------
void set_fill_style(fstyle fs)
{
    switch (fs)
    {
        case SOLID_FILL:  fill_char = L'\x2588'; break;
        case DARK_FILL:   fill_char = L'\x2591'; break;
        case MEDIUM_FILL: fill_char = L'\x2592'; break;
        case LIGHT_FILL:  fill_char = L'\x2593'; break;
        case X_FILL:      fill_char = L'X'; break;
        case O_FILL:      fill_char = L'O'; break;
    }
}

//---------------------------------------------------------
void end_graphics()
{
    // ������ �������������� ��������� ������
    SetConsoleTextAttribute(hConsole, info.wAttributes);
}