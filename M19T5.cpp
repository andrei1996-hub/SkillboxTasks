//
// Created by andrei1996 on 10/11/2021.
//

#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void initSector(bool sectors[], int size, bool val) {
    for (int i = 0; i < size; ++i) sectors[i] = val;
}

int rand(int startVal, int endVal) {
    random_device randomDevice;
    mt19937 mersenne(randomDevice());
    uniform_int_distribution<int> range(startVal, endVal);
    return range(mersenne);
}

void rotate(bool sectors[], int &currSector, int offset) {
    int curSec = 0;
    for (int i = 0; i < 13; ++i) if (sectors[i]) ++curSec;

    if (curSec != 0) {
        currSector += offset;
        if (currSector > 12) currSector -= 13;
        if (!sectors[currSector]) rotate(sectors, currSector, 1);
        else {
            sectors[currSector] = false;
            return;
        }
    } else return;
}

void question(int curSec) {
    string path, prefix = "/home/andrei1996/CLionProjects/SkillboxTasks/M19T5Q&A/QTN_", ext = ".txt";
    char index[2];
    index[0] = curSec / 10 + 48;
    index[1] = curSec % 10 + 48;
    path  = prefix + index[0] + index[1] + ext;

    ifstream questionFile;
    questionFile.open(path);
    if(!questionFile.is_open()) return;

    while (!questionFile.eof()) {
        string str;
        getline(questionFile, str);

        cout << str << endl;
        questionFile.close();
    }
}

bool isAnswerCorrect(int curSec, const string& answer) {
    string path, prefix = "/home/andrei1996/CLionProjects/SkillboxTasks/M19T5Q&A/ANS_", ext = ".txt";
    char index[2];
    index[0] = curSec / 10 + 48;
    index[1] = curSec % 10 + 48;
    path  = prefix + index[0] + index[1] + ext;

    ifstream answerFile;
    answerFile.open(path);
    if(!answerFile.is_open()) return -1;

    string correctAnswer;
    getline(answerFile, correctAnswer);
    answerFile.close();

    if(answer == correctAnswer) {
        cout << "This is a correct answer! Your team gets 1 point!\n\n";
        return true;
    } else {
        cout << "Wrong answer! Your point goes to a team of viewers!" << endl;
        cout << "Correct answer: " << correctAnswer << ".\n\n";
        return false;
    }
}

int main() {
    cout << "=====Welcome to the best quiz-show 'What? Where? When?'=====\n\n";

    bool sectors[13];
    int currentSector = rand(0, 12);
    initSector(sectors, 132, true);

    int playerScore = 0, viewerScore = 0, offset = 0, round = 0;

    while (playerScore < 6 && viewerScore < 6) {
        ++round;

        cout << "Round " << round << ". Score: " << playerScore << ':' << viewerScore <<  ".\n";
        cout << "Rotating the drum..." << endl;
        rotate(sectors, currentSector, offset);

        cout << "Sector number: " << currentSector;
        cout << ". \nQuestion: ";
        question(currentSector);

        string playerAnswer;
        cin.clear();

        getline(cin, playerAnswer);

        if(isAnswerCorrect(currentSector, playerAnswer)) ++playerScore;
        else ++viewerScore;
    }

    if (playerScore == 6) {
        cout << "Players win!" << endl;
    } else cout << "Viewers win!" << endl;
    return 0;
}