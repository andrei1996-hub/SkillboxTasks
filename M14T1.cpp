//
// Created by andrei1996 on 30/07/2021.
//

#include <iostream>
using namespace std;

int main() {
    int cutlery[2][6];
    int plates[2][6];
    int chairs[2][6];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(j == 0) {
                cutlery[i][j] = 4;
                plates[i][j] = 3;
                chairs[i][j] = 1;
            } else {
                cutlery[i][j] = 3;
                plates[i][j] = 2;
                chairs[i][j] = 1;
            }
        }
    }

    cout << "Initial serving configuration:\n";
    cout << "Cutlery:\n";
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << cutlery[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Plates:\n";
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << plates[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Chairs:\n";
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << chairs[i][j] << " ";
        }
        cout << endl;
    }


    cout << "\nAdmin: \"Oh,a woman came with her child, Waiter, bring an extra chair for her, pls!\"\n";
    ++chairs[0][4];

    cout << "Guy from a crowd: \"OMG! My spoon is stolen!\"\n";
    --cutlery[1][2];

    cout << "VIP guy: \"No panic! Take mine, I'm on a diet.\"\n";
    --cutlery[0][0];
    ++cutlery[1][2];

    cout << "VIP guy: \"Waiter! Pls, take the dessert plate also.\"\n";
    --plates[0][0];

    cout << "\nSo, the final serving configuration is:\n";
    cout << "Cutlery:\n";
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << cutlery[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Plates:\n";
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << plates[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Chairs:\n";
    for(int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << chairs[i][j] << " ";
        }
        cout << endl;
    }
}