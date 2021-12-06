//
// Created by andrei1996 on 03/11/2021.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string filePath = "wordsM19T1.txt";
int main(){
    cout << "=====WordFinder=====\n\n";

    cout << "Enter the word: ";
    string wordToFind;
    cin >> wordToFind;

    ifstream wordsFile;
    vector<string> words;
    wordsFile.open(filePath);

    if (wordsFile.is_open()) {
        string curWord;
        while (!wordsFile.eof()) {
            wordsFile >> curWord;
            words.push_back(curWord);
        }
    } else {
        cerr << "File not found.\n";
        return 0;
    }

    int repCount = 0;
    for (int i = 0; i < words.size(); ++i){
        if (wordToFind == words[i]) ++repCount;
    }
    wordsFile.close();
    cout << "This word is written " << repCount << " times in this file.\n";
}