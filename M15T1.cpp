//
// Created by andrei1996 on 18/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=====Maximum sum finder=====\n\n";

    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int res = vec[0];
    int leftLimit = 0, rightLimit = 0;
    int sum = 0;
    int negPos = -1;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i];

        if (sum > res) {
            res = sum;
            leftLimit = negPos + 1;
            rightLimit = i;
        }

        if (sum < 0) {
            sum = 0;
            negPos = i;
        }
    }

    cout << "Limits: " << leftLimit << " and " << rightLimit << endl;
}