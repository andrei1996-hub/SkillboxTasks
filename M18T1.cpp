//
// Created by andrei1996 on 25/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;

void swapVecArr(vector<int>& vec, int* arr) {
    for (int i = 0; i < vec.size(); ++i) {
        int temp = vec[i];
        vec[i] = arr[i];
        arr[i] = temp;
    }
}
void displayArr (int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr+i) << ' ';
    }
    cout << endl << endl;
}

void displayVec (vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main() {
    cout << "=====Array-Vector value swapper=====\n\n";

    vector<int> myVec = {1, 2, 3, 4, 5};
    int myArr[] = {6, 7, 8, 9, 10};

    cout << "Before:\n";
    cout << "Vector: ";
    displayVec(myVec);
    cout << "Array: ";
    displayArr(myArr, sizeof(myArr) / sizeof(int));

    swapVecArr(myVec, myArr);

    cout << "After:\n";
    cout << "Vector: ";
    displayVec(myVec);
    cout << "Array: ";
    displayArr(myArr, sizeof(myArr) / sizeof(int));
}
