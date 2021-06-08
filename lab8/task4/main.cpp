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
        std::cin.ignore();
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
        int i;
        std::cout << "Enter the month:" << std::endl;
        std::cin >> i;
        std::cout << "Enter an amount of sold books:" << std::endl;
        std::cin >> arr[i-1];
    }
    void putdata()const {
        for (int i = 0; i < 2; i++) {
            std::cout << arr[i] << " books were sold in the " << i + 1 << " st(nd/rd) month";
        }
    }
};

class book:publication,sales{
    int pages;
public:
    book():pages(0), publication(), sales(){}

    void getdata(){
        std::cout << "Enter the number of pages this book has:" << std::endl;
        std::cin >> pages;
        publication::getdata();
        sales::getdata();
    }

    void putdata()const{
        std::cout << "This book has " << pages << "pages" << std::endl;
        publication::putdata();
        sales::putdata();
    }
};

class type:publication,sales{
    float time;
public:
    type():time(0), publication(), sales(){}
    void getdata(){
        std::cout<<"Enter the length of the type:" << std::endl;
        std::cin >> time;
        publication::getdata();
        sales::getdata();
    }

    void putdata()const{
        std::cout << "This type is " << "minutes long" << std::endl;
        publication::putdata();
        sales::putdata();
    }
};

class disk:publication,sales{
    diskTypes diskType;
public:
    disk():publication(),sales(){}

    void getdata(){
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

        publication::getdata();
        sales::getdata();
    }

    void putdata(){
        std::cout << "This is a ";
        switch (diskType) {
            case CD:
                std::cout << "CD" << std::endl;
                break;
            case DVD:
                std::cout << "DVD" << std::endl;
                break;
        }

        publication::putdata();
        sales::putdata();
    }
};
int main() {
    book b;
    type t;
    disk d;
    b.getdata();
    t.getdata();
    d.getdata();
    b.putdata();
    t.putdata();
    d.putdata();

    return 0;
}


