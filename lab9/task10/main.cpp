#include <iostream>
using namespace std;

int main(){

    int* ap[10];

    for(int i=0;i<10;i++){
        *(ap+i)=new int[10];
    }

    for (int k=0; k<10; k++){
        for (int i=0; i<10;i++){
            *(*(ap+k)+i)=i;
        }
    }

    for(int i=0;i<10;i++){
        for (int j=0; j<10; j++) {
            cout << *(*(ap + i) + j) << " ";
        }
        cout << endl;
    }

    return 0;
}