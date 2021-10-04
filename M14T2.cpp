//
// Created by andrei1996 on 30/07/2021.
//

#include <iostream>
using namespace std;


int main () {
    char field[3][3];
    int colPos, rowPos;
    string winnerStr, winnerCol, winnerDiag;
    int playerNum = 1, moveCount = 0;
    bool winnerFlag = false, isXWinner = false, isOWinner = false;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j){
            field[i][j] = ' ';
        }
    }

    while (!winnerFlag && moveCount < 9) {
        char symbol;
        cout << "\nPlayer " << playerNum << ", your turn(format: row, column): ";
        cin >> rowPos >> colPos;
        if((colPos < 1 || colPos > 3) || (rowPos < 1 || rowPos > 3) || field[rowPos-1][colPos-1] != ' ') {
            cout << "Incorrect move, both coordinates must be in a range from 1 to 3 and cell must be empty!";
            continue;
        }

        if(playerNum == 1) symbol = 'X';
        else symbol = 'O';

        field[rowPos - 1][colPos - 1] = symbol;
        ++moveCount;

        for(int i = 0; i < 3 && !winnerFlag; ++i) {
            for (int j = 0; j < 3; ++j){
                if (field[i][j] != ' ') winnerStr += field[i][j];
                if (i == 0 && (j == 0 || j == 2)){
                    if (j == 0) {
                        for (int k = 0; k < 3; ++k) {
                            if(field[k][k] != ' ') winnerDiag += field[k][k];
                        }
                    } else {
                        for (int k = 0; k < 3; ++k) {
                            if(field[k][2 - k] != ' ') winnerDiag += field[k][2 - k];
                        }
                    }
                }
                if (winnerDiag == "XXX" || winnerDiag == "OOO") {
                    winnerFlag = true;
                    if(winnerDiag == "XXX") isXWinner = true;
                    else if(winnerDiag == "OOO") isOWinner = true;
                }
                winnerDiag = "";
                if (i == 0) {
                    for (int k = 0; k < 3; ++k) {
                        if (field[k][j] != ' ') winnerCol += field[k][j];
                    }
                }
                if(winnerCol == "XXX" || winnerCol == "OOO"){
                    winnerFlag = true;
                    if(winnerCol == "XXX") isXWinner = true;
                    else if(winnerCol == "OOO") isOWinner = true;
                }
                winnerCol = "";
            }
            if(winnerStr == "XXX" || winnerStr == "OOO"){
                winnerFlag = true;
                if(winnerStr == "XXX") isXWinner = true;
                else if(winnerStr == "OOO") isOWinner = true;
            }
            winnerStr = "";
        }

        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << field[i][j] << " ";
            }
            cout << endl;
        }

        if (playerNum == 1) ++playerNum;
        else --playerNum;
    }

    if(isXWinner) cout << "Player 1 won! Congrats!\n";
    else if(isOWinner) cout << "Player 2 won! Congrats!\n";
    else cout << "It's a draw!\n";
}