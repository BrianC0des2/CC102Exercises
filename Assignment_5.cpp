
/*
 * AUTHOR: Bryan P. Saavedra
 * SECTION: BSCS 1B
 * DATE: 2026-04-20
 */
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void createFile(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::out);
    if(myFile.is_open()){
        myFile << "One" << endl;
        myFile << "Two" << endl;
        myFile << "Three" << endl;
        myFile << "Four" << endl;
        myFile << "Five" << endl;
        myFile << "Six" << endl;
        myFile.close();
    }
}

vector<string> readFile(string fileName){ 
    fstream myFile;
    vector<string> unsortedTexts;
    myFile.open(fileName, ios::in);
    string line;
    if(myFile.is_open()){
        while(getline(myFile, line)) {
            unsortedTexts.push_back(line);
        }
        myFile.close();
    }
    return unsortedTexts;
}

string sortText(string fileName){
    vector<string> newSortedTexts = readFile(fileName);
    sort(newSortedTexts.begin(), newSortedTexts.end(), [](string a, string b){
        return a[0] < b[0];
    });
    string contents = "";
    for (auto &text : newSortedTexts) {
        contents += text+"\n";
    }
    return contents;
}


void makeNewFile(string fileName, string newFileName){
    fstream myFile;
    myFile.open(newFileName, ios::out);
    if(myFile.is_open()){
        myFile << sortText(fileName);
        myFile.close();
    }
}

int main() {
    string fileName = "original.txt";
    string newFileName = "sorted.txt";
    createFile(fileName);
    makeNewFile(fileName, newFileName);
    return 0;
}
