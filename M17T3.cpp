//
// Created by andrei1996 on 24/10/2021.
//

#include <iostream>

using namespace std;

bool subStr(char* a, char* b) {
    int i = 0;

    while (*(a+i) != '\0') {
        if (*(a+i) == *b) {
            int j = 1;
            while (true) {
                if (*(b+j) != *(a+i+j)) return false;
                ++j;
                if(*(b+j) == '\0') return true;
            }
        }
        ++i;
    }
    return false;
}

int main() {
    cout << "=====Substring Finder=====\n\n";

    char a[] = "Hello, World!";
    char b[] = "Wor";
    char c[] = "banana";

    cout << boolalpha << subStr(a, b) << ' ' << subStr(a, c) << endl;
}