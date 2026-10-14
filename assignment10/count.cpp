#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("sample.txt");
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    string word;
    char ch;

    // Count characters and lines
    while (fin.get(ch)) {
        characters++;
        if (ch == '\n') lines++;
    }

    // Reset file pointers to the beginning to count words
    fin.clear();
    fin.seekg(0, ios::beg);

    while (fin >> word) {
        words++;
    }

    fin.close();

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << characters << endl;

    return 0;
}
