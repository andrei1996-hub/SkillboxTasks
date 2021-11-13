//
// Created by andrei1996 on 03/11/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

const char* filePath = "/home/andrei1996/CLionProjects/SkillboxTasks/wordsM19T1.txt";
int main(){
    cout << "=====WordFinder=====\n\n";

    cout << "Enter the word: ";
    string wordToFind;
    cin >> wordToFind;

    ifstream wordsFile;
    string words[30];
    int wordCount = 0;
    wordsFile.open(filePath);
    while (!wordsFile.eof()) {
        wordsFile >> words[wordCount];
        ++wordCount;
    }

    int repCount = 0;
    for (int i = 0; i < wordCount; ++i){
        if (wordToFind == words[i]) ++repCount;
    }
    wordsFile.close();
    cout << "This word is written " << repCount << " times in this file.\n";
}