#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a positive number: ";
    cin >> num;

    try {
        if (num < 0) {
            throw "Error: Number cannot be negative!";
        }
        cout << "You entered: " << num << endl;
    } 
    catch (const char* msg) {
        cerr << msg << endl;
    }
    return 0;
}
