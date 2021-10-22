//
// Created by andrei1996 on 21/10/2021.
//

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    cout << "=====DecFrac Parser 2.0=====\n\n";

    int intPart, fracPart;
    double resVal;

    cout << "Enter the integer part: ";
    cin >> intPart;
    cout << "Enter the fraction part: ";
    cin >> fracPart;

    stringstream parseBuf;
    parseBuf << intPart << "." << fracPart;
    parseBuf >> resVal;
    cout << "Result: " << resVal << endl;
}