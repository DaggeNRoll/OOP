#include <iostream>

const int n=10;

void addarrays(int*,int*,int*,int);

int main(){
    int arr1[n], arr2[n], arr3[n];

    for(int i=0;i<n;i++){
        arr1[i]=1;
        arr2[i]=2;
    }

    addarrays(arr1,arr2,arr3,n);

    for (int i=0; i<n;i++){
        std::cout << arr3[i] << " ";
    }

    return 0;
}

void addarrays(int* arr1,int* arr2, int* arr3, int n){
    for (int i=0;i<n;i++){
        *(arr3+i)=*(arr1+i)+*(arr2+i);
    }
}