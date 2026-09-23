#include <iostream>
using namespace std;

class LibraryBook
{
    string book;
    int status;

public:
    void issue()
    {
        status = 1;
        cout << "Book issued successfully." << endl;
    }

    void returnBook()
    {
        status = 0;
        cout << "Book returned successfully." << endl;
    }

    void display()
    {
        cout << "Book Name: " << book << endl;

        if (status == 1)
            cout << "Status: Issued" << endl;
        else
            cout << "Status: Available" << endl;
    }

    void accept()
    {
        cout << "Enter Book Name: ";
        cin >> book;
        status = 0;
    }
};

int main()
{
    LibraryBook b;

    b.accept();
    b.display();

    b.issue();
    b.display();

    b.returnBook();
    b.display();

    return 0;
}