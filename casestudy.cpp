#include <iostream>
using namespace std;

class Library {
    int id;
    string name;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Book Name: ";
        cin >> name;
        cout << "Book Added Successfully!\n";
    }

    void displayBook() {
        cout << "\nBook ID: " << id;
        cout << "\nBook Name: " << name << endl;
    }
};

int main() {
    Library l;
    int choice;

    do {
        cout << "\n--- Library Management System ---";
        cout << "\n1. Add Book";
        cout << "\n2. Display Book";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.addBook();
                break;

            case 2:
                l.displayBook();
                break;

            case 3:
                cout << "Thank You!";
                break;

            default:
                cout << "Invalid Choice!";
        }
    } while (choice != 3);

    return 0;
}