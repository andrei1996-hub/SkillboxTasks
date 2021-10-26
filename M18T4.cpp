//
// Created by andrei1996 on 26/10/2021.
//

#include <iostream>

using namespace std;

void evenDigits(long long num, int& ans) {
    if (num % 2 == 0) ++ans;
    num /= 10;
    if(num == 0) return;
    evenDigits(num, ans);
}

int main() {
    cout << "=====Even Digits Counter=====";

    int ans = 0;
    long long val = 9'223'372'036'854'775'806;

    evenDigits(val, ans);

    cout << "Even Digits: " << ans << endl;
}
