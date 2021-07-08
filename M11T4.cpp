//
// Created by andrei1996 on 08/07/2021.
//
#include <iostream>
using namespace std;

bool isNumberValid(string num){
    int pointCount = 0;
    if ((num[0] < '-' || num[0] > '9') || num[0] == '/') return false;
    if (num == "-.") return false;
    for (int i = 1; i < num.length(); ++i) {
        if (num[i] == '.') ++pointCount;
        if (pointCount > 1) return false;
        if ((num[i] < '.' || num[i] > '9') || num[i] == '/') return false;
    }
    return true;
}

string getIntPart (string num) {
    string str;
    if (num.find('.') == std::string::npos) {
        str = num;
    } else str = num.substr(0,num.find('.'));
    for (int i = 0; i < str.length(); ++i){
        if (i == 0 && str[i] == '0') {
            str = str.substr(1, str.length() - 1);
            --i;
        }
    }
    if (str.empty()) str = "0";

    return str;
}

string getFractionPart(string num) {
    string str;
    if (num.find('.') == std::string::npos) return "0";
    str = num.substr(num.find('.') + 1, num.length() - 1);

    if (str.empty()) return "0";

    for (int i = str.length() - 1; i >= 0; --i){
        if ((i == (str.length() - 1)) && str[i] == '0') {
            str = str.substr(0,(str.length() - 1));
        }
    }
    if (str.empty()) return "0";
    return str;
}

string comparison(string num1, string num2) {
    string intFirst = getIntPart(num1);
    string intSecond = getIntPart(num2);
    string fracFirst = getFractionPart(num1);
    string fracSecond = getFractionPart(num2);

    if (intFirst > intSecond) return "More";
    else if (intFirst < intSecond) return "Less";
    else {
        if (fracFirst > fracSecond) return "More.";
        else if (fracFirst < fracSecond) return "Less";
        else return "Equal.";
    }
}
int main() {
    cout << "=====Long number comparator=====\n\n";
    string number1, number2;
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;

    while (!isNumberValid(number1) || !isNumberValid(number2)) {
        cout << "Incorrect input of numbers. Please, try again.\n\n";
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;
    }
    cout << comparison(number1, number2);
}