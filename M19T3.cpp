//
// Created by andrei1996 on 06/11/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

string path = "/home/andrei1996/CLionProjects/SkillboxTasks/salaryPaidM19T3.txt";

int main() {
    cout << "=====Salary calculator=====\n\n";

    string names[10];
    string surnames[10];
    string dates[10];
    int salaries[10];
    int count = 0, max = 0, sum = 0;
    ifstream salaryInfo;


    salaryInfo.open(path);

    while (!salaryInfo.eof()) {
        salaryInfo >> names[count] >> surnames[count] >> salaries[count] >> dates[count];
        ++count;
    }

    for (int i = 0; i < count; ++i) {
        if (salaries[i] > salaries[max]) max = i;
        sum += salaries[i];
    }

    salaryInfo.close();
    cout << "Total sum paid: $" << sum << endl;
    cout << "The biggest salary ($" << salaries[max] << ") was paid to " << names[max] << ' ' << surnames[max];
}