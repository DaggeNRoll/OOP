#include <iostream>
using namespace std;

int main(){
    int a[10], a2[10], a3[10],a4[10], a5[10], a6[10], a7[10], a8[10], a9[10], a10[10];
    int* ap[10] = {a,a2,a3,a4,a5,a6,a7,a8,a9,a10};

    for (int k=0; k<10; k++){
        for (int i=0; i<10;i++){
            *(*(ap+k)+i)=0;
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