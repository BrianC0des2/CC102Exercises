/**
 * AUTHOR: Bryan P. Saavedra
 * SECTION: BSCS 1B
 * DATE: 2026-03-17
 */

#include <vector>
#include <iostream>
using namespace std;




struct student{
    int studentID;
    string name;
    string course;
    double gpa;
};

bool idExist(int i,vector<student> students, int noOfStudents){
    for (int j = 0; j < noOfStudents; j++) {
        if (i != j && students[i].studentID == students[j].studentID) {
            return true;
        } 
    }
    return false;
}


void input(int noOfStudents, vector<student>& students){
    for (int i = 0; i < noOfStudents; i++) {
        bool exist;
        cout << "Student "<<i+1<<endl;

        do {
            cout << "Enter Student Id: ";
            cin >> students[i].studentID;
            cin.ignore();
            if (idExist(i,students,noOfStudents)) {
                cout << "Student ID already Exist"<<endl;
            }
        }while(idExist(i, students, noOfStudents));

        cout << "Enter Student Name: ";
        getline(cin, students[i].name);
        cout << "Enter Student Course: ";
        getline(cin, students[i].course);
        cout <<"Enter Student GPA: ";
        cin >> students[i].gpa;
        cin.ignore();
        cout <<endl;
    }
}



void display(vector<student>& student, int noOfStudents){
    cout <<"\nID"<<"\t"<<"Name"<<"\t"<<"Course"<<"\t"<<"GPA"<<"\t"<<"Academic Standing"<<endl;
    for (int i = 0; i < noOfStudents; i++) {
        string academicStanding;
        if (student[i].gpa >= 90 && student[i].gpa <= 100) {
            academicStanding = "Exellent";
        }
        else if (student[i].gpa >= 80 && student[i].gpa <= 89) {
            academicStanding = "Very Good"; 
        }
        else if (student[i].gpa >= 70 && student[i].gpa <= 79) {
            academicStanding = "Good";
        }
        else if (student[i].gpa >= 60 && student[i].gpa <= 69) {
            academicStanding = "Passing";
        }
        else {
            academicStanding = "Failed";
        }
        cout << student[i].studentID <<"\t"<<student[i].name <<"\t"<< student[i].course << "\t"<<student[i].gpa << "\t" << academicStanding<<endl;

    } 
}


int main() {
    int noOfStudents;

    cout << "Enter number of students: ";
    cin >> noOfStudents;
    vector<student> students(noOfStudents);
    input(noOfStudents, students);
    display(students, noOfStudents);


    return 0;
}

