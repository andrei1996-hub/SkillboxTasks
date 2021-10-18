//
// Created by andrei1996 on 18/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {-100,-50, -5, 1, 10, 15};

    for (int i = vec.size()-1; i >= 0; --i) {
        for (int j = 0; j < i; ++j){
            if (abs(vec[j]) > abs(vec[j+1])) swap(vec[j], vec[j+1]);
        }
    }

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ' ';
    }
}
