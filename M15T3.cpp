//
// Created by andrei1996 on 18/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;
void bubbleSort (vector<int>& vec) {
    for (int i = vec.size()-1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (vec[j] > vec[j+1]) {
                int temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
            }
        }
    }
}
int main() {
    vector<int> vec;
    cout << "=====5-th element finder=====\n\n";

    int val = 0;
    while (val != -2) {
        cout << "Enter the value: ";
        cin >> val;
        if (val == -1) {
            if (vec.size() < 5) {
                cout << "Vector is too small. Continue filling it.\n";
                continue;
            } else {
                bubbleSort(vec);
                cout << vec[4] << endl;
            }
        } else vec.push_back(val);
    }
}