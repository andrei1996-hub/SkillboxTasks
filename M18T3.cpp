//
// Created by andrei1996 on 26/10/2021.
//

#include <iostream>

using namespace std;

int hopComboCount(int stepsTotal, int stepsMax) {
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
    cout << "=====Jump-combo counter(v2.0)=====\n\n";

    int stepsTotal;
    int stepsMaxPossible;

    cout << "Enter total steps quantity: ";
    cin >> stepsTotal;
    cout << "Enter rabbit's hop power(steps/hop): ";
    cin >> stepsMaxPossible;

    cout << "Ways to do: " << hopComboCount(stepsTotal, stepsMaxPossible) << endl;
}
