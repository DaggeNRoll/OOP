#include <iostream>
#include<string>


class publication {
protected:
    std::string name;
    float price;
public:
    publication() : name(""), price(0) {}

    void getdata() {
        std::cout << "Enter the name of the book" << std::endl;

        if (std::cin.peek() == '\n') {//"смотрит" на символ, но не считывает его
            std::cin.ignore();//удаляет один символ из входного потока
        }

        getline(std::cin, name);
        std::cout << "Enter its price" << std::endl;
        std::cin >> price;
    }

    void putdata() const {
        std::cout << "The name of the book is " << name;
        std::cout << ". It costs " << price << std::endl;
    }
};

class publication2 : public publication {
private:
    struct Date {
        int day, month, year;
    } date;
public:
    publication2() : date{0, 0, 0}, publication() {}

    void getdata() {
        publication::getdata();
        std::cout << "Enter when this book was published (day, month, year):" << std::endl;
        std::cin >> date.day >> date.month >> date.year;
    }

    void putdata() const {
        publication::putdata();
        std::cout << "It was published on " << date.day << "." << date.month << "." << date.day << std::endl;
    }
};

class book : public publication2 {
    int pages;
public:
    book() : pages(0), publication2() {}

    void getdata() {
        publication2::getdata();
        std::cout << "Enter the number of pages this book has:" << std::endl;
        std::cin >> pages;
    }

    void putdata() const {
        publication2::putdata();
        std::cout << "This book has " << pages << " pages" << std::endl;
    }
};

class type : public publication2 {
    float time;
public:
    type() : time(0), publication2() {}

    void getdata() {
        publication2::getdata();
        std::cout << "Enter the length of the type:" << std::endl;
        std::cin >> time;
    }

    void putdata() const {
        publication2::putdata();
        std::cout << "This type is " << time << "minutes long" << std::endl;
    }
};

int main() {
    book b;
    type t;
    std::cout << "Book" << std::endl;
    b.getdata();
    std::cout << "Type" << std::endl;
    t.getdata();
    b.putdata();
    t.putdata();

    return 0;
}

