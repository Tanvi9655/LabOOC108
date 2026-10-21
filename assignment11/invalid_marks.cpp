#include <iostream>
#include <exception>
using namespace std;

// Custom exception class
class InvalidMarksException : public exception {
public:
    const char* what() const noexcept {
        return "Error: Marks must be strictly between 0 and 100!";
    }
};

int main() {
    int marks;
    cout << "Enter exam marks (0-100): ";
    cin >> marks;

    try {
        if (marks < 0 || marks > 100) {
            throw InvalidMarksException();
        }
        cout << "Marks accepted: " << marks << endl;
    } 
    catch (const InvalidMarksException& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
