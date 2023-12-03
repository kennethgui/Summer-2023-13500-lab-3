/*
Kenneth Guillont
Kenneth.guillont83@myhunter.cuny.edu
assignment: 3LA
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1);}

    string junk; getline(fin, junk);

    cout << "Enter date: ";
    string in_date; cin >> in_date;
    bool found = false;

    string date; double eastSt;
    
    while(fin >> date >> eastSt){
        if (date == in_date) {
        found = true;
        }
        break;
}
        fin.close();

    if (found == true) {
        cout << "East basin storage: " << eastSt << " billion gallons" << endl;
        }

    return 0;
}