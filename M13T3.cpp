//
// Created by andrei1996 on 26/07/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=====Self-Renewable Database=====\n\n";

    vector<int> db;

    int val;
    cout << "Enter the element to the database: ";
    cin >> val;

    while (val != -1) {
        if (db.size() < 20) db.push_back(val);
        else {
            db.erase(db.begin());
            db.push_back(val);
        }

        cout << "Enter the element to the database: ";
        cin >> val;
    }

    for (int i = 0; i < db.size(); ++i) {
        cout << db[i] << " ";
    }
}