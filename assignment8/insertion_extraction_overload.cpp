#include <iostream>
using namespace std;

class Student
{
    int roll;
    string name;

public:
    friend istream& operator>>(istream &in, Student &s)
    {
        cout << "Enter Roll No: ";
        in >> s.roll;

        cout << "Enter Name: ";
        in >> s.name;

        return in;
    }

    friend ostream& operator<<(ostream &out, Student &s)
    {
        out << "\nRoll No: " << s.roll;
        out << "\nName: " << s.name;

        return out;
    }
};

int main()
{
    Student s;

    cin >> s;
    cout << s;

    return 0;
}