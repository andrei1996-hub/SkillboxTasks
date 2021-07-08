//
// Created by andrei1996 on 08/07/2021.
//
#include <iostream>
using namespace std;

string caesar_encrypt(string str, int shiftKey) {
    char currentChar;
    int alphabetCount = 0;
    if (shiftKey > 0) {
        for (int i = 0; i < shiftKey; ++i) {
            if (i % 26 == 0) ++alphabetCount;
        }
        shiftKey -= alphabetCount * 26;
    } else if (shiftKey < 0) {
        for (int i = 0; i > shiftKey; --i) {
            if (i % 26 == 0) ++alphabetCount;
        }
        shiftKey += alphabetCount * 26;
    }
    for(int i = 0; i < str.length(); ++i) {
        currentChar = str[i];
        if(currentChar >= 'a' && currentChar <= 'z') {
            currentChar += shiftKey;
            str[i] = currentChar;
            if(currentChar > 'z'){
                currentChar -=  'z' - 'a' + 1;
                str[i] = currentChar;
            }
            else if(currentChar < 'a') {
                currentChar += 'Z' - 'A' + 1;
                str[i] = currentChar;
            }
        }
        else if(currentChar >= 'A' && currentChar <= 'Z') {
            currentChar += shiftKey;
            str[i] = currentChar;
            if(currentChar > 'Z') {
                currentChar -= 'Z' - 'A' + 1;
                str[i] = currentChar;
            }
            else if (currentChar < 'A') {
                currentChar += 'z' - 'a' + 1;
                str[i] = currentChar;
            }
        }
    }
    return str;
}

string caesar_decrypt (string str, int shiftKey) {
    return caesar_encrypt(str, -shiftKey);
}

int main() {
    string text;
    int encryptKey;
    cout << "=====Caesar's cipher encryptor/decryptor=====\n\n";

    cout << "Enter a text to encrypt: ";
    getline(cin, text);
    cout << "Enter the encryption key: ";
    cin >> encryptKey;

    string encryptedText = caesar_encrypt(text, encryptKey);
    cout << "\nEncrypted text: " << encryptedText;
    cout << "\nDecrypted text: " << caesar_decrypt(encryptedText, encryptKey);
}
