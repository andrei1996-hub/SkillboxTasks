//
// Created by andrei1996 on 02/08/2021.
//
#include <iostream>

using namespace std;

int main()
{
    int arr[5][5];
    int counter = 0;

    for (int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            arr[i][j+i%2*(4-j*2)] = counter;
            ++counter;
        }
    }

    for (int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

