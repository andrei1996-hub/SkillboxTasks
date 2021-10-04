//
// Created by andrei1996 on 06/08/2021.
//

#include <iostream>
using namespace std;

void init(bool bubbles[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j){
            bubbles[i][j] = true;
        }
    }
}

void displayBubbles(bool bubbles[12][12]){
    for(int i =0 ; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if(bubbles[i][j]) cout << 'o';
            else cout << 'x';
            cout << "  ";
        }
        cout << endl;
    }
}

void pop (bool bubbles[12][12], int start[2], int end[2]) {
    int popCount = 0;
    bool isCoordValid = (start[0] >= 0 && start[0] <= 11) &&
            (start[1] >= 0 && start[1] <= 11) &&
            (end[0] >= 0 && end[0] <= 11) &&
            (end[1] >= 0 && end[1] <= 11);
    if (isCoordValid) {
        for (int i = start[0]; i <= end[0]; ++i){
            for (int j = start[1]; j < end[1] + 1; ++j) {
                if(bubbles[i][j]) {
                    ++popCount;
                    cout << "Pop! (x" << popCount <<')' << endl;
                    bubbles[i][j] = false;
                }
            }
        }
    } else cout << "Invalid coordinates! Values must be in a range from 0 to 11!\n";
    cout << endl;
}

bool isFieldEmpty(bool bubbles[12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if(bubbles[i][j]) return false;
        }
    }

    return true;
}

int main(){
    bool bubbles[12][12], emptyFlag = false;
    int start[2], end[2];

    init(bubbles);

    while (!emptyFlag) {
        displayBubbles(bubbles);
        cout << "\nEnter the initial coordinates: ";
        cin >> start[0] >> start[1];
        cout << "Enter the final coordinates: ";
        cin >> end[0] >> end[1];

        pop(bubbles, start, end);

        emptyFlag = isFieldEmpty(bubbles);
    }
}