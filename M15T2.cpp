//
// Created by andrei1996 on 18/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=====Sum-components finder=====\n\n"
    vector<int> vec = {2, 7, 11, 15};
    int res = 9;
    int num1, num2;
    bool pairFound = false;

    for (int i = 0; i < vec.size() && !pairFound; ++i) {
        num1 = vec[i];
        for (int j = i+1; j < vec.size() && !pairFound; ++j) {
            num2 = vec[j];
            if (num1 + num2 == res) {
                pairFound = true;
                cout << "Elements: " << num1 << " and " << num2 << endl;
            }
        }
    }


}