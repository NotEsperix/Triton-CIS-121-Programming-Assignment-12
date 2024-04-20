/******************************************
* Edgardo Richard Ventura                 *
* Week 12                                 *
* Assignment 2                            *
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

struct City {
    string name;
    int population;
};

// Function prototypes
vector<City> readCitiesFromFile(const string& filename);
void displayCities(const vector<City>& cities);
void searchCity(const vector<City>& cities);

int main() {
    // This will print the working directory for debugging purposes
    char buffer[1024];
    if (_getcwd(buffer, sizeof(buffer)) != NULL)
        cout << "Current working directory: " << buffer << endl;
    else
        perror("getcwd() error");

    // Correct the file name as per the user's directory content
    vector<City> cities = readCitiesFromFile("Population.txt.txt"); // Assuming the .txt is doubled as shown in previous error outputs
    displayCities(cities);
    searchCity(cities);
    return 0;
}

vector<City> readCitiesFromFile(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    vector<City> cities;
    City city;
    string line;
    while (getline(infile, line)) {
        size_t tabPos = line.find('\t');
        if (tabPos != string::npos) {
            city.name = line.substr(0, tabPos);
            city.population = stoi(line.substr(tabPos + 1));
            cities.push_back(city);
        }
    }
    infile.close();
    return cities;
}

void displayCities(const vector<City>& cities) {
    cout << "\nList of Cities and Populations:\n";
    for (const City& city : cities) {
        cout << city.name << " has a population of " << city.population << endl;
    }
}

void searchCity(const vector<City>& cities) {
    string cityName;
    cout << "\nEnter city name, ctl+z to stop: ";
    while (cin >> cityName) {
        bool found = false;
        for (const City& city : cities) {
            if (city.name == cityName) {
                cout << cityName << " has a population of " << city.population << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << cityName << " not found" << endl;
        }
        cout << "Enter city name, ctl+z to stop: ";
    }
    cout << "Goodbye. Have a nice day.\n";
}
