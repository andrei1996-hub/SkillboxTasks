//
// Created by andrei1996 on 06/11/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string path = "/home/andrei1996/CLionProjects/SkillboxTasks/salaryPaidM19T3.txt";

int main() {
    cout << "=====Salary calculator=====\n\n";

    vector<string> names;
    vector<string> surnames;
    vector<string> dates;
    vector<int> salaries;
    int count = 0, max = 0, sum = 0;
    ifstream salaryInfo;


    salaryInfo.open(path);

    if (salaryInfo.is_open()){
        while (!salaryInfo.eof()) {
            names.push_back("");
            surnames.push_back("");
            salaries.push_back(0);
            dates.push_back("");
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
    } else {
        cerr << "File not found.\n";
    }
}