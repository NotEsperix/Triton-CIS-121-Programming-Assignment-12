/******************************************
* Edgardo Richard Ventura                 *
* Week 12                                 *
* Assignment 3                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
******************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <direct.h> // Include for _getcwd on Windows
using namespace std;

struct Employee {
    string firstName;
    string lastName;
    double salary;
};

/***************************************************
*            ~ Table of Employment ~               *
* Employee structure stores first name, last name, *
* and salary.                                      *
***************************************************/

// Function prototypes
vector<Employee> readEmployeesFromFile(const string& filename);
void displayEmployees(const vector<Employee>& employees);
void searchEmployeeByLastName(const vector<Employee>& employees);

int main() {
    // This will print the working directory for debugging purposes
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");

    // Assume the data file is in the same directory as the executable
    vector<Employee> employees = readEmployeesFromFile("Empldata.txt.txt");
    displayEmployees(employees);
    searchEmployeeByLastName(employees);
    return 0;
}

vector<Employee> readEmployeesFromFile(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << ".\n";
        exit(1);
    }

    vector<Employee> employees;
    Employee employee;
    while (infile >> employee.firstName >> employee.lastName >> employee.salary) {
        employees.push_back(employee);
    }
    infile.close();
    return employees;
}

void displayEmployees(const vector<Employee>& employees) {
    cout << setprecision(2) << fixed;
    cout << "\nEmployees' Information:\n";
    for (const Employee& employee : employees) {
        cout << "First Name: " << setw(10) << employee.firstName;
        cout << ", Last Name: " << setw(10) << employee.lastName;
        cout << ", Salary: $" << setw(8) << employee.salary << endl;
    }
}

void searchEmployeeByLastName(const vector<Employee>& employees) {
    string searchLastName;
    cout << "Enter last name, ctl+z to stop: ";
    while (cin >> searchLastName) {
        bool found = false;
        for (const Employee& employee : employees) {
            if (employee.lastName == searchLastName) {
                cout << "First Name: " << setw(10) << employee.firstName;
                cout << ", Last Name: " << setw(10) << employee.lastName;
                cout << ", Salary: $" << setw(8) << employee.salary << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << searchLastName << " not found." << endl;
        }
        cout << "Enter last name, ctl+z to stop: ";
    }
    cout << "Goodbye. Have a nice day." << endl;
}
