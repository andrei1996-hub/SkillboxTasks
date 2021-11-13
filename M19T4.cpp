//
// Created by andrei1996 on 08/11/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "=====PNG-file detector=====\n\n";

    string path;
    ifstream pngFile;
    cout << "Enter the full path to the file to analyze: ";
    cin >> path;

    if (path.substr(path.length()-4, 4) != ".png"){
        cerr << "This file is not \".png\" file.\n";
        return 0;
    }
    pngFile.open(path, ios::binary);

    if(pngFile.is_open()){
        char arr[4];
        while (pngFile.tellg() < 4){
            pngFile.read(arr, sizeof(arr));
        }
        if (arr[0] == -119 && arr[1] == 'P' && arr[2] == 'N' && arr[3] == 'G'){
            cout << "This is a valid \".png\" file." << endl;
        } else cout << "This is not a \".png\" file." << endl;
    } else {
        cerr << "File not found.\n";
    }

    pngFile.close();
}