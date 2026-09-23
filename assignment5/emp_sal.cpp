#include <iostream>
using namespace std;

class Employee
{
    int id;
    string name;
    float basic, hra, da, gross;

public:

    // Constructor
    Employee(int i, string n, float b)
    {
        id = i;
        name = n;
        basic = b;

        hra = basic * 0.20;
        da = basic * 0.10;
        gross = basic + hra + da;
    }

    void display()
    {
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basic;
        cout << "\nHRA: " << hra;
        cout << "\nDA: " << da;
        cout << "\nGross Salary: " << gross << endl;
    }

    // Destructor
    ~Employee()
    {
        cout << "\nEmployee object destroyed.";
    }
};

int main()
{
    Employee e(101, "Tanvi", 20000);

    e.display();

    return 0;
}