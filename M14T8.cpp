//
// Created by andrei1996 on 06/08/2021.
//

#include <iostream>
using namespace std;

int main () {
    int blocks[5][5][10];
    int height, level;
    bool errorFlag = false;
    for (int i = 0; i < 5 && !errorFlag; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << "Enter the block height (0-10): ";
            cin >> height;
            if(height < 0 || height > 10) {
                errorFlag = true;
                cout << "Incorrect input of height! Value must be in a range from 0 to 10!\n";
                break;
            }
            for (int k = 0; k < 10; ++k) {
                if (k < height) blocks[i][j][k] = 1;
                else blocks[i][j][k] = 0;
            }
        }
        cout << "END OF ROW " << i << "\n";
    }

    cout << "\nEnter the level (0-9): ";
    cin >> level;

    if (!errorFlag && level > 0 && level < 10) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k <= level; ++k) {
                    if (k == level) cout << blocks[i][j][k] << "  ";
                }
            }
            cout << endl;
        }
    }
}