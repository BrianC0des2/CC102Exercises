/*
 * AUTHOR: Bryan P. Saavedra
 * SECTION: BSCS 1B
 * DATE: 2026-04-20
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void createFile(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::out);
    if(myFile.is_open()){
        myFile << "Red" << endl;
        myFile << "Yellow" << endl;
        myFile << "Green" << endl;
        myFile << "Violet" << endl;
        myFile << "Blue" << endl;
        myFile.close();
    }
}

string readFile(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);
    string content = "";
    string line;
    if(myFile.is_open()){
        while(getline(myFile, line)) {
            content += line + "\n";
        }
        myFile.close();
    }
    return content;
}

void makeCopy(string fileName, string newFileName){
    fstream myFile;
    myFile.open(newFileName, ios::out);
    if(myFile.is_open()){
        myFile << readFile(fileName);
        myFile.close();
    }
}

int main() {
    string fileName = "color.txt";
    string copyOfFileName = "color_copy.txt";
    createFile(fileName);
    makeCopy(fileName, copyOfFileName);
    return 0;
}
