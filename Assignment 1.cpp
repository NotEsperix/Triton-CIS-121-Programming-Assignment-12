/******************************************
* Edgardo Richard Ventura                 *
* Week 12                                 *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
******************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <direct.h> 
using namespace std;

struct Student {
    string firstName;
    string lastName;
    float gpa;
};

/***************************************************
*             ~ Table of Etymology ~               *
* Student structure stores first name, last name,  *
* and GPA.                                         *
***************************************************/

// Function prototypes
vector<Student> readStudentsFromFile(const string& filename);
void displayStudents(const vector<Student>& students);
void displayStudentsReverse(const vector<Student>& students);

int main() {
    // This will print the working directory for debugging purposes
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");

    // Provide the full path to your data file
    vector<Student> students = readStudentsFromFile("C:\\Users\\event\\OneDrive\\Documents\\A - Education\\School Documents\\Records\\Computer Science\\CIS121\\.cpp Assignments\\Week 12\\DataFile.txt.txt");
    displayStudents(students);
    displayStudentsReverse(students);
    return 0;
}

vector<Student> readStudentsFromFile(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file at " << filename << endl;
        exit(1);
    }

    vector<Student> students;
    Student student;
    while (infile >> student.firstName >> student.lastName >> student.gpa) {
        students.push_back(student);
    }
    infile.close();
    return students;
}

void displayStudents(const vector<Student>& students) {
    cout << setprecision(2) << fixed;
    cout << "\nStudents' Information:\n";
    for (const Student& student : students) {
        cout << "First Name: " << setw(10) << student.firstName;
        cout << ", Last Name: " << setw(10) << student.lastName;
        cout << ", GPA: " << setw(4) << student.gpa << endl;
    }
}

void displayStudentsReverse(const vector<Student>& students) {
    cout << "\nStudents' Information in Reverse Order:\n";
    for (auto it = students.rbegin(); it != students.rend(); ++it) {
        cout << "First Name: " << setw(10) << it->firstName;
        cout << ", Last Name: " << setw(10) << it->lastName;
        cout << ", GPA: " << setw(4) << it->gpa << endl;
    }
}
