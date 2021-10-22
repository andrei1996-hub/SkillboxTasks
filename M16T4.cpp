//
// Created by andrei1996 on 21/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;

enum Piano {
    DO  = 1,
    RE  = 2,
    MI  = 4,
    FA  = 8,
    SOL = 16,
    LA  = 32,
    SI  = 64,
};

bool isCorrectInput (char ch) {

    if (ch >= '1' && ch <= '7') return true;
    else return false;
}

bool isAccordCorrect (string text, vector<int>& accord) {
    int b = 0;
    for (int i = 0; i < text.length(); ++i)
    {
        if (isCorrectInput(text[i]))
        {
            switch (text[i])
            {
                case '1':
                    b |= DO;
                    break;
                case '2':
                    b |= RE;
                    break;
                case '3':
                    b |= MI;
                    break;
                case '4':
                    b |= FA;
                    break;
                case '5':
                    b |= SOL;
                    break;
                case '6':
                    b |= LA;
                    break;
                case '7':
                    b |= SI;
                    break;
                default:
                    return false;
            }
        } else return false;

    }
    accord.push_back(b);
    return true;
}

string getMelody (int note)
{
    string melody;
    if (note & DO) melody += "DO ";
    if (note & RE) melody += "RE ";
    if (note & MI) melody += "MI ";
    if (note & FA) melody += "FA ";
    if (note & SOL) melody += "SOL ";
    if (note & LA) melody += "LA ";
    if (note & SI) melody += "SI ";
    return melody;
}

int main() {
    cout << "=====Mechanical Piano. Never repeat the same note!=====\n\n";

    vector<int> notes;
    string accord;
    int accordCount = 0;

    do {
        cout << "Enter composition #" << (accordCount + 1) << endl;
        cin >> accord;
        if (!isAccordCorrect(accord, notes))
        {
            cerr << "Incorrect input. Try again." << endl;
            continue;
        }
        ++accordCount;
    } while (accordCount < 12);
    cout << "Melody has been successfully recorded." << endl;

    for (int i = 0 ; i < 12; ++i)
    {
        cout << getMelody(notes[i]) << "\n" ;
    }
}