#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    string name, department;

    void getEmployee()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Department: ";
        cin >> department;
    }
};

class TeachingStaff : public Employee
{
public:
    string subject, qualification;

    void getTeaching()
    {
        getEmployee();

        cout << "Enter Subject: ";
        cin >> subject;
        cout << "Enter Qualification: ";
        cin >> qualification;
    }

    void display()
    {
        cout << "\n--- Teaching Staff ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Subject: " << subject << endl;
        cout << "Qualification: " << qualification << endl;
    }
};

class NonTeachingStaff : public Employee
{
public:
    string designation;
    int hours;

    void getNonTeaching()
    {
        getEmployee();

        cout << "Enter Designation: ";
        cin >> designation;
        cout << "Enter Working Hours: ";
        cin >> hours;
    }

    void display()
    {
        cout << "\n--- Non-Teaching Staff ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;
        cout << "Working Hours: " << hours << endl;
    }
};

int main()
{
    TeachingStaff t;
    NonTeachingStaff n;

    t.getTeaching();
    t.display();

    n.getNonTeaching();
    n.display();

    return 0;
}