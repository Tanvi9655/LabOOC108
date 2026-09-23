#include <iostream>
using namespace std;

class Employee
{
    int id;
    string name, department;
    float salary;

public:

    void accept()
    {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Basic Salary: ";
        cin >> salary;
    }

    void calculate()
    {
        salary = salary * 12;
    }

    void display()
    {
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name;
        cout << "\nDepartment: " << department;
        cout << "\nAnnual Salary: " << salary << endl;
    }
};

int main()
{
    Employee e;

    e.accept();
    e.calculate();
    e.display();

    return 0;
}