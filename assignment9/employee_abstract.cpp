#include <iostream>
using namespace std;

// Base class
class Employee
{
    
protected:
    double salary;

public:
    Employee(double s)
    {
        salary = s;
    }
    virtual double calculateBonus() = 0;
    
};

// Manager class
class Manager : public Employee
{
public:
    Manager(double s) : Employee(s) {}

    double calculateBonus() override
    {
        return salary * 0.20;
    }
};

// Developer class
class Developer : public Employee
{
public:
    Developer(double s) : Employee(s) {}

    double calculateBonus() override
    {
        return salary * 0.10;
    }
};

int main()
{
    Manager manager(50000);
    Developer developer(40000);

    Employee *e;

    // Manager bonus
    e = &manager;
    cout << "Manager Bonus: " << e->calculateBonus() << endl;

    // Developer bonus
    e = &developer;
    cout << "Developer Bonus: " << e->calculateBonus() << endl;

    return 0;
}