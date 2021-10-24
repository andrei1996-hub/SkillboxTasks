//
// Created by andrei1996 on 24/10/2021.
//

#include <iostream>

using namespace std;

void reverseArr(int* arr, int size){
    int temp;
    for (int i = 0; i < size/2; ++i) {
        temp = *(arr+i);
        *(arr+i) = *(arr+size-i-1);
        *(arr+size-i-1) = temp;
    }
}

void display(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr+i) << ' ';
    }
    cout << endl;
}


int main() {
    cout << "=====Pointer-based array reverser=====\n\n";

    int myArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Before:\n";
    display(myArr,sizeof(myArr) / sizeof(int));

    reverseArr(myArr, sizeof(myArr) / sizeof(int));

    cout << "After:\n";
    display(myArr,sizeof(myArr) / sizeof(int));
}
