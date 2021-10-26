//
// Created by andrei1996 on 25/10/2021.
//

#include <iostream>

using namespace std;

int hopComboCount(int stepsTotal = 3, int stepsMax = 3) {
    int result = 0;
    if (stepsTotal == 0) return 1;
    else {
        for (int i = 1; i <= min(stepsTotal, stepsMax); ++i) {
            result += hopComboCount(stepsTotal-i, stepsMax);
        }
        return result;
    }
}

int main() {
    cout << "=====Jump-combo counter=====\n\n";

    int stepsTotal;

    cout << "Enter steps quantity: ";
    cin >> stepsTotal;

    cout << "Ways to do: " << hopComboCount(stepsTotal) << endl;
}
