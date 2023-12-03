/*
kenneth guillont */

#include <cstdlib>
#include <climits>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
    }
    string junk;
    getline(fin, junk);

    double minStorage = numeric_limits<double>::max();
    double maxStorage = numeric_limits<double>::min();
    string line;

    while (getline(fin, line)) {
        istringstream iss(line);
        double storageLevel;
        if (iss >> storageLevel) {
            if (storageLevel < minStorage) {
                minStorage = storageLevel;
            }
            if (storageLevel > maxStorage) {
                maxStorage = storageLevel;
            }
        }
    }

    fin.close();

    if (minStorage == numeric_limits<double>::max() ||
        maxStorage == numeric_limits<double>::min()) {
        cout << "No storage data found." << std::endl;
    } else {
        cout << "Minimum storage in East basin: " << minStorage << " billion gallons" << endl;
        cout << "Maximum storage in East basin: " << maxStorage << " billion gallons" << endl;
    }

    return 0;
}
