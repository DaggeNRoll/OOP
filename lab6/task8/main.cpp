#include <iostream>
#include <stdlib.h>

using namespace std;

class safearray{
    static const int LIMIT = 10;
    int arr[LIMIT];
public:
    safearray(){
        for (int i=0;i<LIMIT;i++){
            arr[i]=0;
        }
    }
    void putel(int id, int number){
        if(id<LIMIT){
            arr[id]=number;
        }
        else{
            cout << "Invalid index!!!" << endl;
            exit(EXIT_FAILURE);
        }
    }
    int getel(int id)const{
        if (id<LIMIT){
            return arr[id];
        }
        else{
            cout << "Invalid index!!!" << endl;
            exit(EXIT_FAILURE);
        }
    }
};


int main() {
    safearray sarr;
    int id=11,temp=12345;
    sarr.putel(id,temp);
    temp = sarr.getel(id);
    cout << temp << endl;
    return 0;
}
