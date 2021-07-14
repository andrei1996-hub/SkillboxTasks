#include <iostream>
//
// Created by andrei1996 on 12/07/2021.
//

using namespace std;

int main() {
    int arr[] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int sumArrElements = 0, sumIncr = 0;
    int initX = 105;

    for (int i = 0; i < 15; ++i) {
        sumArrElements += arr[i];
        if (i == 14) break;
        sumIncr += initX;
        ++initX;
    }

    cout << "Duplicates found:" << sumArrElements - sumIncr << endl;
}
