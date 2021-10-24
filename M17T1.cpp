//
// Created by andrei1996 on 24/10/2021.
//

#include <iostream>
using namespace std;

void swap(int* pa, int* pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    cout << "=====Pointer-based swapper=====\n\n";

    int a = 10;
    int b = 20;

    cout << "Before:\t" << "a:" << a << ' ' << "b:" << b << endl;
    swap(&a, &b);
    cout << "After:\t" << "a:" << a << ' ' << "b:" << b << endl;
}