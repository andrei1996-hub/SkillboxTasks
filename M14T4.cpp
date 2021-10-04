//
// Created by andrei1996 on 02/08/2021.
//

#include <iostream>
using namespace std;

int main() {
    int matrixA[4][4], matrixB[4][4], elem;
    bool isEqual = true;

    cout << "Matrix 1:\n";
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "Enter the element: ";
            cin >> elem;
            matrixA[i][j] = elem;
        }
    }

    cout << "\nMatrix 2:\n";
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "Enter the element: ";
            cin >> elem;
            matrixB[i][j] = elem;
        }
    }

    for(int i = 0; i < 4 && isEqual; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrixA[i][j] != matrixB[i][j]) isEqual = false;
        }
    }

    cout << "Matrices are ";
    isEqual ? cout << "" : cout << "not ";
    cout << "equal.\n";
}

