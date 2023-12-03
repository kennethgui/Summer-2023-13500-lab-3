/*
kenneth guillont
kenneth.guillont83@myhunter.cuny.edu
lab 3
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct BasinData {
    string date;
    double westBasin;
};

int main() {
    string startDate, endDate;
    cout << "Enter earlier date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter later date (MM/DD/YYYY): ";
    cin >> endDate;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);

    vector<BasinData> data;
    string line;

    while (getline(fin, line)) {
        istringstream iss(line);
        string date;
        string eastBasin;
        string westBasin;

        if (getline(iss, date, '\t') && getline(iss, eastBasin, '\t') && getline(iss, westBasin, '\t')) {
            if (date >= startDate && date <= endDate) {
                BasinData entry;
                entry.date = date;
                entry.westBasin = stod(westBasin);
                data.push_back(entry);
            }
        }
    }

    fin.close();

    cout << endl;
    for (int i = data.size() - 1; i >= 0; --i) {
        cout << data[i].date << " " << data[i].westBasin << " ft" << endl;
    }

    return 0;
}
}
