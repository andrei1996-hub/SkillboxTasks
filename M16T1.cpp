//
// Created by andrei1996 on 21/10/2021.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "=====Speedometer=====\n\n";

    stringstream buf;
    float speed = 0.0f, delta = 0.0f;
    do {
        buf.str("");
        cout << "Enter the speed delta: ";
        cin >> delta;
        if ((speed + delta) > 149.9f) {
            speed = 150.0f;
        } else if ((speed + delta) <= 0.1f) speed = 0.0f;
        else speed += delta;
        buf << fixed << setprecision(1) << speed << " km/h";
        cout << "Speed: " << buf.str() << endl;
    } while (speed > 0);
    cout << "Car has been stopped." << endl;
}