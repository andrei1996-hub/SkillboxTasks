//
// Created by andrei1996 on 08/07/2021.
//
#include <iostream>
using namespace std;

int elementCount (string str, char ch)
{
    int elCounter = 0;
    for(int i = 0; i < str.length(); ++i) {
        if (str[i] == ch) ++elCounter;
    }
    return elCounter;
}

bool isCorrectInput (string str)
{
    if (str.length() != 9) return false;
    for (int i = 0;i < str.length(); ++i) {
        if (str[i] != 'O' && str[i] != 'X' && str[i] != '.') return false;
    }
    return true;
}
char getElement(int row, int col, string str) {
    return str[row * 3 + col];
}

string getRow(int rowPos, string str) {
    return str.substr(rowPos * 3, 3);
}

string getCol(int colPos, string str) {
    return  (str.substr(colPos, 1) + str[colPos+3] + str[colPos+6]);
}

string getDiagonal( char dir, string str) {
    string diag;
    if (dir == '>') for (int i = 0 ; i <= 2; ++i) diag += getElement(i , i, str);
    else if (dir == '<') for (int i = 0 ; i <= 2; ++i) diag += getElement(i , (2 - i), str);

    return diag;
}

int gameConfAnalyze(string row1, string row2, string row3){
    string diag1, diag2;
    int xInLine = 0, oInLine = 0;
    string rowConcat = row1 + row2 + row3;
    int xCount = elementCount(rowConcat, 'X');
    int oCount = elementCount(rowConcat, 'O');
    int dotCount = elementCount(rowConcat, '.');

    if (!isCorrectInput(rowConcat)) {
        cout << "Incorrect.\n";
        return 0;
    }

    if (xCount - oCount > 1) {
        cout << "Incorrect.\n";
        return 0;
    } else if (oCount - xCount > 0) {
        cout << "Incorrect.\n";
        return 0;
    } else {
        diag1 = getDiagonal('>', rowConcat);
        diag2 = getDiagonal('<', rowConcat);

        if  (diag1 == "XXX" && xCount - oCount <= 1) ++xInLine;
        else if (diag1 == "OOO" && oCount - xCount <=0) ++oInLine;

        if  (diag2 == "XXX" && xCount - elementCount(rowConcat, 'O') <= 1) ++xInLine;
        else if (diag2 == "OOO" && oCount - xCount <= 0) ++oInLine;

        for (int i = 0; i < 3; ++i) {
            if (getRow(i, rowConcat) == "XXX" && xCount - oCount <= 1) ++xInLine;
            else if(getRow(i, rowConcat) == "OOO" && oCount - xCount <= 0) ++oInLine;
        }

        for (int i = 0; i < 3; ++i) {
            if (getCol(i, rowConcat) == "XXX" && xCount - oCount <= 1) ++xInLine;
            else if (getCol(i, rowConcat) == "OOO" && oCount - xCount <= 0) ++oInLine;
        }
    }

    if (xInLine == 0 && oInLine == 0 && dotCount > 0) cout << "Nobody.\n";
    else if (xInLine == 1 && oInLine == 1 ) cout << "Incorrect.\n";
    else if (xInLine == 1 &&  oInLine == 0) {
        bool isExclusiveSituation = row1 == "XXX" && row2[0] == 'X' && row3[0] == 'X';
        if (xCount - oCount == 1 || isExclusiveSituation) cout << "Petya won.\n";
        else cout << "Incorrect.\n";
    }
    else if (oInLine == 1 && xInLine == 0) {
        if (xCount == oCount) cout << "Vanya won.\n";
        else cout << "Incorrect.\n";
    }
    else if (xInLine > 1) cout << "Incorrect.\n" << endl;
    else if (oInLine > 1) cout << "Incorrect.\n" << endl;
    else  cout  << "Nobody.\n" << endl;
    return 0;
}

int main() {
    string row1, row2, row3;
    cout << "=====Tic-Tac-Toe configuration analyzer=====\n\n";

    cout << "Enter the game configuration:\n";
    cin >> row1 >> row2 >> row3;

    gameConfAnalyze(row1, row2, row3);
}

