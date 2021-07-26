//
// Created by andrei1996 on 26/07/2021.
//

#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> vec,int qty) {
    for (int i = 0; i < qty; ++i) {
        cout << vec[i] << " ";
    }
}

int main() {
    cout << "=====Recursive element deleter=====\n\n";

    int qty;
    vector<int> vec;
    cout << "Enter the length of your vector: ";
    cin >> qty;

    for (int i = 0; i < qty; ++i) {
        int elem;
        cout << "Enter the element: ";
        cin >> elem;
        vec.push_back(elem);
    }

    printVec(vec, vec.size());

    int elemToDelete;
    cout << "\nWhich element do you want to delete from the vector?: ";
    cin >> elemToDelete;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == elemToDelete) {
            if (i == vec.size() -1) {
                vec.pop_back();
            }
            else {
                vec.erase(vec.begin()+i);
                --i;
            }
        }
    }

    printVec(vec, vec.size());
}