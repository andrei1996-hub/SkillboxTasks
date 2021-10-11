#include <iostream>
using namespace std;

bool isCorrectCoordsInput(int row, int col) {
    return (row >= 0 && row < 10 && col >= 0 && col < 10);
}

bool initField(char m[10][10]) {
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j) m[i][j] = ' ';
    }
    return true;
}

char getCharAt(char field[10][10],int row, int col) {
    if (isCorrectCoordsInput(row, col)){
        if (field[row][col] == '#') return '#';
        if (field[row][col] == 'X') return 'X';
        if (field[row][col] == '*') return '*';
        if (field[row][col] == ' ') return ' ';
    }
    return false;
}


void display(char field[10][10]) {
    cout << "\n  0 1 2 3 4 5 6 7 8 9\n";
    for(int i = 0; i < 10; i++){
        cout << i << '|';
        for(int j = 0; j < 10; j++){
            cout  << field[i][j] << "|";
        }
        cout << endl;
    }
}

void displayFields(char field[10][10], char winfieldEnemy[10][10]) {
    for(int i = 0; i < 10; ++i){
        cout << "|";
        for(int j = 0; j < 10; ++j){
            cout << field[i][j] << '|';
        }
        cout << "   |   |";
        for (int j = 0; j < 10; ++j){
            cout << winfieldEnemy[i][j] << "|";
        }
        cout << "\n";
    }
}

bool isPossibleToSet(char field[10][10], int startRow, int startCol, int endRow, int endCol) {
    int row = (startRow < endRow ? startRow : startCol);
    int col = (startCol < endCol ? startCol : endCol);
    for (int i = col; i <= col + abs(endCol - startCol); ++i){
        for (int j = row; j <= row + abs(endRow - startRow); ++j){
            if (field[i][j] != ' ') return false;
        }
    }
    return true;
}

void inputCoords(int& row, int& col) {
    while (true) {
        cin.clear();
        cin >> row >> col;
        if (isCorrectCoordsInput(row, col)) break;
        else {
            cout << "\nInput error. Try again.\n";
            continue;
        }
    }
}

bool isAttackSuccessful(char field[10][10], char attackedField[10][10] , int rowAttacked, int colAttacked) {
    char d = getCharAt(field, rowAttacked, colAttacked);
    if (d == '#') {
        attackedField[rowAttacked][colAttacked] = 'X';
        field[rowAttacked][colAttacked] = ' ';
        cout << "Shot!\n";
        return true;
    } else if (d == ' ') {
        attackedField[rowAttacked][colAttacked] = '*';
        cout << "Off target.\n";
        field[rowAttacked][colAttacked] = '*';
        return false;
    } else if (d == '*' || d == 'X') {
        cout << "You have already attacked this point.\n";
        inputCoords(rowAttacked, colAttacked);
        isAttackSuccessful(field, attackedField, rowAttacked, colAttacked);
    }
    return false;
}

bool isFleetDestroyed(char field [10][10]) {
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (field [i][j] == '#') return false;
        }
    }
    return true;
}

bool isShipSizeCorrect(int startRow, int startCol, int endRow, int endCol, int typeShip) {
    if ((typeShip == abs(endRow - startRow) + 1 && startCol == endCol) ||
    (typeShip == abs(endCol - startCol) + 1 && startRow == endRow)) return true;
    return false;
}

bool isFleetSet (char field[10][10], int shipSize, int shipCount) {
    string numEnding;
    char ch;
    bool isSizeValid;
    int startRow, startCol;
    int endRow, endCol;
    switch (shipCount) {
        case 0:
            numEnding = "st";
            break;
        case 1:
            numEnding = "nd";
            break;
        case 2:
            numEnding = "rd";
            break;
        case 3:
            numEnding = "th";
            break;
        default:
            return false;
    }
    if (shipSize == 1) {
        cout << "Set " << shipCount+1 << numEnding << " single-decked ship: " ;
        while (true) {
            inputCoords(startRow, startCol);
            ch = getCharAt(field, startRow, startCol);
            if (ch == ' ') {
                field[startRow][startCol] = '#';
                return true;
            } else {
                cout << "This position is occupied or coords input sequence is wrong.\n";
                cout << "Try again, or enter coords vice versa.\n";
            }
        }

    } else if (shipSize >= 2 && shipSize <= 4) {
        cout << "Set " << shipCount+1 << numEnding << ' ' << shipSize << "-decked ship:" ;
        while (true) {
            inputCoords(startRow, startCol);
            inputCoords(endRow, endCol);
            isSizeValid = isShipSizeCorrect(startRow, startCol, endRow, endCol, shipSize);
            if (isSizeValid && isPossibleToSet(field, startRow, startCol, endRow, endCol)) {
                int x = startRow < endRow ? startRow : endRow;
                int y = startCol < endCol ? startCol : endCol;
                if (startRow == endRow) {
                    for (int i = y; i <= shipSize + y - 1; ++i) field[startRow][i] = '#';
                    return true;
                } else if (startCol == endCol) {
                    for (int j = x; j <= shipSize + x - 1; ++j) field[j][startCol] = '#';
                    return true;
                } else {
                    cout << "Incorrect position. Try again.\n";
                    continue;
                }
            } else if (!isPossibleToSet(field, startRow, startCol, endRow, endCol)){
                cout << "This position is occupied or coords input sequence is wrong.\n";
                cout << "Try again, or enter coords vice versa.\n";
            } else {
                cout << "Incorrect position. Try again.\n";
            }
        }
    }
    return false;
}

bool setFleet(char field[10][10]) {
    int shipSize, shipCount;
    bool isSet;
    for (shipSize = 1; shipSize <= 4; ++shipSize) {
        for (shipCount = 0; shipCount <= 4 - shipSize; ++shipCount){
            isSet = isFleetSet(field, shipSize, shipCount);
            display(field);
        }
    }
    return isSet;
}

int main() {
    bool shotFlag1, shotFlag2 = true;
    int  rowShot, colShot;
    char player1field[10][10];
    char player2field[10][10];
    char player1attackedField[10][10];
    char player2attackedField[10][10];
    initField(player1field);
    initField(player2field);
    initField(player1attackedField);
    initField(player2attackedField);

    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "------88888----888888----8888-----------********----****-----*******---*******---***------*****-----\n";
    cout << "-----888-888---888-------8888-----------***--***----*****------***-------***-----***------***-------\n";
    cout << "-----888-------888-------88888----------***--***----**-**------***-------***-----***------***-------\n";
    cout << "------888------88888----888-88----------*******-----**-**------***-------***-----***------****-----\n";
    cout << "-------8888----88888----888-88----------***--***---***-**------***-------***-----***------****------\n";
    cout << "---------888---888------888-88----------***--***---***-***-----***-------***-----***------***-------\n";
    cout << "----888--888---888-----88888888---------***--***---*******-----***-------***-----***------***-------\n";
    cout << "-----8888888---888888--888--888---------********--***--***-----***-------***-----******---*****-----\n";
    cout << "----------------------------------------------------------------------------------------------------\n";

    cout << "\nPlayer 1, set your fleet: " << endl;
    setFleet(player1field);
    cout << "\nPlayer 2, set your fleet: " << endl;
    setFleet(player2field);
    while (!isFleetDestroyed(player2field) && !isFleetDestroyed(player1field)) {
            display(player1attackedField);
            cout << "Player 1, enter attack coordinates: ";
            inputCoords(rowShot,colShot);
            shotFlag1 = isAttackSuccessful(player2field, player1attackedField, rowShot, colShot);
            if (isFleetDestroyed(player2field)) {
                cout << "Player 1 won!\n";
                displayFields(player1field, player2field);
                break;
            }
            if (shotFlag1) continue;
            else {
                while (shotFlag2) {
                    display(player2attackedField);
                    cout << "Player 2, enter attack coordinates: \n";
                    inputCoords(rowShot, colShot);
                    shotFlag2 = isAttackSuccessful(player1field, player2attackedField, rowShot, colShot);
                    if (isFleetDestroyed(player1field)) {
                        cout << "Player 2 won!\n";
                        displayFields(player1field, player2field);
                        break;
                    }
                }
                if (isFleetDestroyed(player1field)) break;
            }
    }
}