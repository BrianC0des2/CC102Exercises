/**
 * Author: Bryan P. Saavedra
 * Section: BSCS 1B
 * Created: 2026-02-20
 */

#include <iostream>
#include <vector>
using namespace std;




// Function to Handle Invalid Input (Y/N)
char getValidYesOrNo(string str, char y, char n){
    char value;
    do {
        cout << str;
        cin >> value;
        if (value != y && value != n)
            cout << "\nInvalid Input! Please enter a letter between " << y << " and " << n << ".\n";
    } while (value != n && value != y);
    return value;
}




// Function to Calcalulate and Output the Average and also the Quizzez Per Student 
void averageCalc(vector<vector<double>> studentTable, int students, int  quizzesPerStudent){
    vector<double> ave;
    // This is wher the calculations done
    for(int i = 0; i < students; i++){
        double sum = 0;  
        for(int j = 0; j < quizzesPerStudent; j++){
            sum += studentTable[i][j];
        }
        ave.push_back(sum/quizzesPerStudent);
    }
    // This is where will be the output shown
    cout << "Student\t";
    for(int i = 0; i < quizzesPerStudent; i++){
        cout << "   Q"<<i+1<<"   ";
    }
    cout << "Average"<<endl;
    cout <<"-----------------------------------------------------"<<endl;

    for(int i = 0; i < students; i++){
        cout << i+1 <<"\t   "; 
        for(int j = 0; j < quizzesPerStudent; j++){
            cout <<studentTable[i][j]<<"\t   ";
        }
        cout << ave[i];
        cout <<endl;
    }
}


int main() {
    char choice;
    do{
        system("cls");
        int numOfStudents, numOfQuizzes;

        cout << "Enter number of students: ";
        cin >> numOfStudents;
        cout << "Enter number of quizzes: ";
        cin >> numOfQuizzes;


        vector table(numOfStudents, vector<double>(numOfQuizzes, 0));
        // Get the Quizzes and store it to the table
        for(int i = 0; i < numOfStudents; i++){
            cout << "Enter Scores for Student "<<i+1<<endl;
            for(int j = 0; j < numOfQuizzes; j++){
                cout << "Enter Score "<<j+1 <<": ";
                cin >> table[i][j];
            }
        }

        averageCalc(table, numOfStudents, numOfQuizzes);
        
        choice = getValidYesOrNo("\nDo you want to run the program again? : ", 'y', 'n');
        
    }while(tolower(choice) == 'y');
    return 0;
}

