/**
 * AUTHOR: Bryan P. Saavedra
 * SECTION: BSCS 1B
 * DATE: 2026-04-27
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;



bool isPrime(int num){
    if (num < 2) return false;
    for (int i = 2; i < num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}





void getPrimes(string fileName, vector<int> &nums){
    fstream file;
    file.open(fileName, ios::in);
    string line;
    if (!file.is_open()) {
        cout << "Can't open the file";
        return;
    }
    while(getline(file, line)){
        if (line.empty()) continue;
        int n = stoi(line);
        if (isPrime(n)) { 
            nums.push_back(n);
        }
    }
    file.close();
}




int main() {
    string fileName = "NUMS.txt";    
    vector<int> nums;
    getPrimes(fileName, nums);
    cout << "Prime Numbers: " <<nums.size()<<endl; 

    return 0;
}

