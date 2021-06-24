#include <iostream>

class publication{
    std::string name;
    float price;
public:

    virtual void getdata(){
        std::cout << "Enter the name of the publication: ";
        std::cin.ignore();
        getline(std::cin,name);
        std::cout << "\nEnter its price: ";
        std::cin >> price;
        std::cout << std::endl;
    }

    virtual void putdata()const{
        std::cout << "This is " << name << ". It costs " << price << std::endl;
    }

    virtual bool isOversize()=0;

    void oversized(){
        std::cout<<"!Size overflow!"<<std::endl;
    }
};

class book:public publication{
    int pages;
public:
    virtual void getdata(){
        publication::getdata();
        std::cout<<"Enter the number of pages: ";
        std::cin >> pages;
        std::cout << std::endl;
    }

    virtual void putdata()const{
        publication::putdata();
        std::cout << "This book has " << pages << " pages." << std::endl;
    }

    bool isOversize(){
        return pages>800;
    }
};

class tape:public publication{
    int recordedMinutes;
public:
    virtual void getdata(){
        publication::getdata();
        std::cout << "Enter the number of recorded minutes: ";
        std::cin >> recordedMinutes;
        std::cout << std::endl;
    }

    virtual void putdata()const{
        publication::putdata();
        std::cout << recordedMinutes << " minute(s) was(were) recorded." << std::endl;
    }

    bool isOversize(){
        return recordedMinutes>90;
    }
};

int main(){
    publication *pubPtr[100];
    int counter=0;

    do{
        std::cout<<"What type of publication do you want to enter? (b=book,t=type): ";
        char ch;
        std::cin>>ch;
        std::cout<<std::endl;
        bool flag=0;

        switch(ch){
            case 'b':
               pubPtr[counter]=new book;
                break;
            case 't':
                pubPtr[counter]=new tape;
                break;
            default:
                std::cout << "Wrong type! Try again!" << std::endl;
                flag=1;

        }

        if (!flag) {
            pubPtr[counter]->getdata();
            if (pubPtr[counter]->isOversize()) {
                pubPtr[counter]->oversized();

            } else {
                counter++;
            }
        }

        std::cin.ignore();
        std::cout << "Do you want to continue (y/n)?" << std::endl;
    }while(std::cin.get()=='y');

    for (int i=0;i<counter;i++){
        pubPtr[i]->putdata();
        std::cout<<std::endl;
    }
}