//
// Created by andrei1996 on 06/11/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "=====Simple File Reader=====\n\n";
    string path;
    char buffer[100];

    cout << "Enter the path: ";
    cin >> path;

    ifstream fileToRead;
    fileToRead.open(path, ios::binary);
    if (fileToRead.is_open()) {
        fileToRead.read(buffer, sizeof(buffer));
        cout << buffer;
        fileToRead.close();
    } else {
        cerr << "File is not found." << endl;
    }
}