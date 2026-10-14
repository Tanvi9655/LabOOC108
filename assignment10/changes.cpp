#include <iostream>
#include <fstream> // Required for ifstream, ofstream, and fstream classes
#include <string>

using namespace std;

int main() {
    string line;

    // ----------------------------------------
    // 1. WRITING CONTENT TO A FILE
    // ----------------------------------------
    ofstream fout;
    
    // Opens file in overwrite mode by default. 
    // Use fout.open("sample.txt", ios::app) to append instead.
    fout.open("sample1.txt",ios::app); 

    // Check if the file opened successfully
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "Enter text to write to the file (Type '-1' on a new line to stop):" << endl;

    // Loop to read from standard input and write to the file
    while (fout) {
        getline(cin, line);

        // Press "-1" to exit the writing loop
        if (line == "-1") {
            break;
        }

        // Write the line into the file
        fout << line << endl;
    }

    // Close the output file stream
    fout.close();

    // ----------------------------------------
    // 2. READING CONTENT FROM A FILE
    // ----------------------------------------
    ifstream fin;
    
    // Opens file in read mode (ios::in) by default
    fin.open("sample1.txt"); 

    // Check if the file exists and opened successfully
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\n--- Reading Content from 'sample.txt' ---" << endl;

    // Execute a loop until EOF (End of File) is reached
    while (getline(fin, line)) {
        // Print line read from the file to the console
        cout << line << endl;
    }

    // Close the input file stream
    fin.close();

    return 0;
}
