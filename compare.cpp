/*
kenneth guillont
kenneth.guillont83@myhunter.cuny.edu
lab 3
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string startDate, endDate;
    cout << "Enter starting date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter ending date (MM/DD/YYYY): ";
    cin >> endDate;

    ifstream fin("Current_Reservoir_Levels.tsv");
    string line;
    bool withinInterval = false;

    while (getline(fin, line)) {
        istringstream iss(line);
        string date;
        string eastBasin;
        string westBasin;

        if (getline(iss, date, '\t') && getline(iss, eastBasin, '\t') && getline(iss, westBasin, '\t')) {
            if (date == startDate) {
                withinInterval = true;
            }

            if (withinInterval) {
                cout << date << " ";
                if (eastBasin > westBasin) {
                    cout << "West" << endl;
                } else if (eastBasin < westBasin) {
                    cout << "East" << endl;
                } else if (eastBasin == westBasin) {
                    cout << "Equal" << endl;
                }
            }

            if (date == endDate) {
                break;
            }
        }
    }

    fin.close();

    return 0;
}
