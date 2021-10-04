//
// Created by andrei1996 on 06/08/2021.
//

#include <iostream>
using namespace std;

int main() {
    float m[4][4];
    float v[4];
    float r[4];

    cout << "Matrix initialization:\n";
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            cout << "Enter the element: ";
            cin >> m[i][j];
        }
    }

    cout << "\nVector initialization:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Enter the element: ";
        cin >> v[i];
    }

    cout << "\nMatrix:\n";
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "\nVector:\n";
    for (int i = 0; i < 4; ++i) {
        cout << v[i] << ' ';
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            r[i] += m[i][j] * v[j];
        }
    }

    cout << "\nResult is:\n";
    for(int i = 0; i < 4; ++i) {
        cout << r[i] << ' ';
    }
}