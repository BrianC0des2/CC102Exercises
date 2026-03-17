/**
 * AUTHOR: Bryan P. Saavedra
 * SECTION: BSCS 1B
 * DATE: 2026-03-17
 */

#include <iostream>
#include <vector>
using namespace std;

void analyzeGrades(double* grades, int students, int subjects) {
    vector<double> average;

    for (int i = 0; i < students; i++) {
        double sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += *(grades + i * 100 + j); 
        }
        average.push_back(sum / subjects);
    }

    int stud = 0;
    double highestGrade = average[0];
    for (int i = 0; i < students; i++) {
        if (highestGrade < average[i]) {
            highestGrade = average[i];
            stud = i;
        }
    }

    cout << "Students\t";
    for (int i = 0; i < subjects; i++) {
        cout << "Subject " << i + 1 << "\t";
    }
    cout << "Average\n";

    for (int i = 0; i < students; i++) {
        cout << i + 1 << "\t\t";
        for (int j = 0; j < subjects; j++) {
            cout << *(grades + i * 100 + j) << "\t\t";
        }
        cout << average[i] << "\n";
    }

    cout << "Student with the highest grade is student " << stud + 1;
    cout << " with the grade of " << highestGrade << "\n";
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of subjects: ";
    cin >> subjects;

    double grades[100][100];

    for (int i = 0; i < students; i++) {
    cout << "Grade for student " << i + 1<<endl;
        for (int j = 0; j < subjects; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}
