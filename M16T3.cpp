//
// Created by andrei1996 on 21/10/2021.
//

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    cout << "=====Buffered Calculator=====\n\n";

    string expression;
    stringstream buf;
    cout << "Enter the expression (a(|+|-|*|/|)b): " << endl;
    cin >> expression;
    buf << expression;

    double a, b, result;
    char operation;

    buf >> a >> operation >> b;
    if (operation == '+') result = a + b;
    else if (operation == '-') result = a - b;
    else if (operation == '*') result = a * b;
    else if (b != 0.0 && operation == '/') result = a / b;
    else {
        cerr << "Unknown error." << endl;
        return 0;
    }
    cout << "Result: " << result << endl;
}