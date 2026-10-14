#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open the source file for reading
    ifstream source("sample.txt");
    if (!source) {
        cerr << "Error: Source file could not be opened!" << endl;
        return 1;
    }

    // Open/Create the destination file for writing
    ofstream destination("copy.txt");
    if (!destination) {
        cerr << "Error: Destination file could not be created!" << endl;
        source.close();
        return 1;
    }

    // Copy the entire file content using stream buffers
    destination << source.rdbuf();

    cout << "File copied successfully from 'sample.txt' to 'copy.txt'!" << endl;

    // Close both files
    source.close();
    destination.close();

    return 0;
}
