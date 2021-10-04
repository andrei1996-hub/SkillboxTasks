//
// Created by andrei1996 on 03/08/2021.
//

#include <iostream>
using namespace std;

int main () {
    float matrix[4][4];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "Enter the element: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nBefore:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j && i != 3-j) matrix[i][j] = 0.f;
        }
    }

    cout << "\nAfter:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}