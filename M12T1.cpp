//
// Created by andrei1996 on 12/07/2021.
//

#include <iostream>
using namespace std;

int main(){
    cout << "=====Interactive Ownerlist=====\n\n";


    string owners[10];
    for (int i = 0; i < 10; ++i) {
        cout << "Enter the apartment owners surname: ";
        cin >> owners[i];
    }

    int appNumber;
    for (int i = 0; i < 3; ++i) {
        cout << "Enter the apartment number (1 - 10): ";
        cin >> appNumber;
        if (appNumber > 0 && appNumber < 10) cout << owners[appNumber - 1] << endl;
        else cout << "Incorrect apartment number!\n";
    }
}
