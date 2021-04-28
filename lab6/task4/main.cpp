#include <iostream>
using namespace std;
const int MAX = 10;

void maxint(int[MAX],const int);

int main() {
    int arr[MAX];
    cout << "Enter the elements of the array: " << endl;
    for (int i=0;i<MAX;i++){
        cin >> arr[i];
    }
    maxint(arr,MAX);
    return 0;
}

void maxint(int arr[MAX],const int MAX){
    int max = arr[0];
    int n=0;
    for (int i = 1;i<MAX;i++){
        if (arr[i]>max){
            max=arr[i];
            n=i;
        }
    }
    cout << "The largest element is " << max << " and has id " << n << endl;
}
