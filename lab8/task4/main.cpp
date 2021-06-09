#include <iostream>
#include <string>

enum diskTypes{CD,DVD};

class publication{
protected: std::string name;
    float price;
public:
    publication():name(""),price(0){}
    void getdata(){
        std::cout << "Enter the name of the book" << std::endl;

        if (std::cin.peek() == '\n'){//"смотрит" на символ, но не считывает его
            std::cin.ignore();//удаляет один символ из входного потока
        }

        getline(std::cin,name);
        std::cout << "Enter its price" << std::endl;
        std::cin >> price;
    }

    void putdata()const{
        std::cout << "The name of the book is " << name;
        std::cout << ". It costs " << price << std::endl;
    }
};

class sales{
protected:float arr[3];
public:
    sales():arr{0,0,0}{}
    void getdata(){

        std::cout << "Enter an amount of sold books for last 3 months" << std::endl;
        for (int i=0; i<3;i++) {
            std::cin >> arr[i];
        }
    }

    void putdata()const {
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i] << " books were sold in the " << i + 1 << " st(nd/rd) month." << std::endl;
        }
    }
};

class book:publication,sales{
    int pages;
public:
    book():pages(0), publication(), sales(){}

    void getdata(){
        publication::getdata();
        std::cout << "Enter the number of pages this book has:" << std::endl;
        std::cin >> pages;
        sales::getdata();
    }

    void putdata()const{
        publication::putdata();
        std::cout << "This book has " << pages << " pages" << std::endl;
        sales::putdata();
    }
};

class type:publication,sales{
    float time;
public:
    type():time(0), publication(), sales(){}
    void getdata(){
        publication::getdata();
        std::cout<<"Enter the length of the type:" << std::endl;
        std::cin >> time;
        sales::getdata();
    }

    void putdata()const{
        publication::putdata();
        std::cout << "This type is " << time <<"minutes long" << std::endl;
        sales::putdata();
    }
};

class disk:publication,sales{
    diskTypes diskType;
public:
    disk():publication(),sales(){}

    void getdata(){
        publication::getdata();

        std::cout << "Enter the type of the disk(c=CD/d=DVD):" << std::endl;
        char t;
        std::cin >> t;

        switch(t){
            case 'c':
                diskType=CD;
                break;
            case 'd':
                diskType=DVD;
                break;
        }

        sales::getdata();
    }

    void putdata(){
        publication::putdata();

        std::cout << "This is a ";
        switch (diskType) {
            case CD:
                std::cout << "CD" << std::endl;
                break;
            case DVD:
                std::cout << "DVD" << std::endl;
                break;
        }

        sales::putdata();
    }
};
int main() {
    book b;
    type t;
    disk d;
    std::cout << "Book" << std::endl;
    b.getdata();
    std::cout << "Type" << std::endl;
    t.getdata();
    std::cout << "Disk" << std::endl;
    d.getdata();
    std::cout << "Book" << std::endl;
    b.putdata();
    std::cout << "Type" << std::endl;
    t.putdata();
    std::cout << "Disk" << std::endl;
    d.putdata();

    return 0;
}


