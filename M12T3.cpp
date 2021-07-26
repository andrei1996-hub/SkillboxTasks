//
// Created by andrei1996 on 13/07/2021.
//

#include <iostream>
using namespace std;

void quickSort(float array[], int low, int high) {
    int i = low;
    int j = high;
    float mid = array[(i + j) / 2];
    float temp;

    while (i <= j)
    {
        while (array[i] < mid) ++i;
        while (array[j] > mid) --j;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            ++i;
            --j;
        }
    }
    if (j > low) quickSort(array, low, j);
    if (i < high) quickSort(array, i, high);
}

int main() {
    cout << "=====Quick Sort Algorithm Implementation=====\n\n";

    float numbers[15];
    for (int i = 0; i < 15; ++i) {
        cout << "Enter the decimal value: ";
        cin >> numbers[i];
    }

    quickSort(numbers, 0, 14);
    for (int i = 14; i >= 0 ; --i) {
        cout << numbers[i] << " ";
    }
}