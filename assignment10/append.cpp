#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string record;

    // 1. Append a new record
    ofstream fout("records.txt", ios::app);
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    
    cout << "Enter a new record to add: ";
    getline(cin, record);
    fout << record << endl;
    fout.close();
    cout << "Record added successfully!\n" << endl;

    // 2. Display all records
    ifstream fin("records.txt");
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "--- Current File Records ---" << endl;
    while (getline(fin, record)) {
        cout << record << endl;
    }
    fin.close();

    return 0;
}
