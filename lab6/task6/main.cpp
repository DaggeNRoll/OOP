#include <iostream>
#include <cstdlib>
#include <ctime>

const int bridge = 13;
using namespace std;
enum Suit {
    clubs, diamonds, hearts, spades
};
// �� 2 �� 10 ������� �����
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;


class card {
private:
    int number;
    Suit suit;
public:
    card() // �����������
    {}

    void set(int n, Suit s) // ��������� ��������
    {
        suit = s;
        number = n;
    }

    void display(); // ����� �����
};


void card::display() {
    if (number >= 2 && number <= 10)
        cout << number;
    else {
        switch (number) {
            case jack:
                cout << 'J';
                break;
            case queen:
                cout << 'Q';
                break;
            case king:
                cout << 'K';
                break;
            case ace:
                cout << 'A';
                break;
        }
    }
    switch (suit) {
        case clubs:
            cout << static_cast<char>(5);
            break;
        case diamonds:
            cout << static_cast<char>(4);
            break;
        case hearts:
            cout << static_cast<char>(3);
            break;
        case spades:
            cout << static_cast<char>(6);
            break;
    }
}


int main() {
    card deck[52],deck1[12],deck2[12],deck3[12],deck4[12];
    int j;
    cout << endl;
    for (j = 0; j < 52; j++) // ������� ������������� ������ ����
    {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }

    // ���������� �������� ������
    cout << "�������� ������:\n";
    for (j = 0; j < 52; j++) {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13)) // �������� ����� ������ ����� ������ 13-� �����
            cout << endl;
    }
    srand(time(NULL)); // �������������� ��������� ��������� �����
    for (j = 0; j < 52; j++) {
        int k = rand() % 52; // �������� ��������� �����
        card temp = deck[j]; // � ������ �� � �������
        deck[j] = deck[k];
        deck[k] = temp;
    }

    for (j = 0;j<52;j++){
        if (j>38){
            deck4[j-13]=deck[j];
        }
        else if(j>25){
            deck3[j-26]=deck[j];
        }
        else if(j>12){
            deck2[j-39]=deck[j];
        }
        else{
            deck1[j]=deck[j];
        }
    }

    cout << "First part of deck:" << endl;
    for (j=0;j<13; j++){
        deck1[j].display();
        cout << " ";
    }
    cout << endl;

    cout << "Second part of deck:" << endl;
    for (j=0;j<13; j++){
        deck2[j].display();
        cout << " ";
    }
    cout << endl;

    cout << "Third part of deck:" <<endl;
    for (j=0;j<13; j++){
        deck3[j].display();
        cout << " ";
    }
    cout << endl;

    cout << "Fourth part of deck:" << endl;
    for (j=0;j<13; j++){
        deck4[j].display();
        cout << " ";
    }
    cout << endl;
    /*// ���������� ������������ ������
    cout << "\n������������ ������:\n";
    for (j = 0; j < 52; j++) {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13)) // �������� ����� ������ ����� ������ 13-� �����
            cout << endl;
    }*/
    return 0;
}