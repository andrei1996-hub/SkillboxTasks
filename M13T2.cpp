//
// Created by andrei1996 on 26/07/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=====Total Price Counter=====\n\n";

    vector<float> prices = {2.5, 4.25, 3.0, 10.0};
    vector<int> indices = {1, 1, 0, 3};
    float sum = 0.0f;

    for (int i = 0; i < indices.size(); ++i) {
        sum += prices[indices[i]];
    }

    cout << "SUM = " << sum << endl;
}