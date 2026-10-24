#include <iostream>
#include <fstream>  // 1. Required header for File Handling
using namespace std;

class Employee     //Class (Encapsulation)
{
public:
    int id;    //Data members
    string name;
    float salary;
    string dept;  

    Employee()    //Default Constructor
    {
        id = 0;
        name = "Unknown";
        salary = 0.0;
        dept = "Unknown";
    }

    Employee(int empId, string empName, float empSalary, string empDept)    //Parameterized Construtcor
    {
        id = empId;
        name = empName;
        salary = empSalary;
        dept = empDept;
    }

    void accept()    //Member function
    {
        cout << "[Input] Enter Employee ID: ";
        cin >> id;
        cout << "[Input] Enter Employee Name: ";
        cin >> name;
        cout << "[Input] Enter Employee Basic Salary: ";
        cin >> salary;

        // 2. Automatically save Employee details upon console input  //file writing mode
        ofstream file("records.txt", ios::app); 
        if (file.is_open()) {
            file << "Employee | ID: " << id << " | Name: " << name 
                 << " | Dept: " << dept << " | Salary: Rs. " << salary << "\n";
            file.close();
            cout << "[File] Employee data automatically saved to records.txt\n";
        }
    }

    void accept(int empId, string empName, float empSalary, string empDept)  //function overloading
    {
        id = empId;
        name = empName;
        salary = empSalary;
        dept = empDept;   

        // 3. Automatically save overloaded details when called directly in code
        ofstream file("records.txt", ios::app);
        if (file.is_open()) {
            file << "Employee (Updated) | ID: " << id << " | Name: " << name 
                 << " | Dept: " << dept << " | Salary: Rs. " << salary << "\n";
            file.close();
            cout << "[File] Overloaded Employee data saved to records.txt\n";
        }
    }

    void display() 
    {
        cout << "--- Employee Details ---\n";
        cout << "ID        : " << id << "\n"
             << "Name      : " << name << "\n"
             << "Department: " << dept << "\n"
             << "Salary    : Rs. " << salary << "\n"
             << "------------------------\n";
    }

    ~Employee() //Destructor
    {
    }
};

// Derived Class implementing public inheritance
class Manager : public Employee    //single level inheritence
{
public:
    float bonus;

    Manager() : Employee()  //constructor chaining
    {
        bonus = 0.0;
    }

    // 4. Automatically save Parameterized Manager creation
    Manager(int empId, string empName, float empSalary, string empDept, float mgrBonus)
        : Employee(empId, empName, empSalary, empDept)   //parameterized constructor chaining
    {
        bonus = mgrBonus;

        ofstream file("records.txt", ios::app);
        if (file.is_open()) {
            file << "Manager (Init) | ID: " << id << " | Name: " << name 
                 << " | Dept: " << dept << " | Salary: Rs. " << salary << " | Bonus: Rs. " << bonus << "\n";
            file.close();
            cout << "[File] Parameterized Manager saved to records.txt\n";
        }
    }

    void acceptManager() 
    {
        accept(); // Reuses base Employee accept() (Saves ID, Name, Salary automatically)
        cout << "[Input] Enter Manager Bonus: ";
        cin >> bonus;

        // 5. Automatically append the Manager's bonus field to the file
        ofstream file("records.txt", ios::app);
        if (file.is_open()) {
            file << "Manager Bonus Update | ID: " << id << " | Bonus: Rs. " << bonus 
                 << " | Total Pay: Rs. " << (salary + bonus) << "\n";
            file.close();
            cout << "[File] Manager bonus details updated in records.txt\n";
        }
    }

    void displayManager() 
    {
        cout << "--- Manager Details ---\n";
        cout << "ID        : " << id << "\n"
             << "Name      : " << name << "\n"
             << "Department: " << dept << "\n"
             << "Salary    : Rs. " << salary << "\n"
             << "Bonus     : Rs. " << bonus << "\n"
             << "Total Pay : Rs. " << (salary + bonus) << "\n";
        cout << "-----------------------\n";
    }

    ~Manager() 
    {
    }
};

// Global function declared outside the class
void department(Employee &e)   
{
    cout << "[Input] Enter Employee's Department: ";
    cin >> e.dept;
}

int main()
{
    cout << "=========================================\n";
    cout << "        STAGE 1: TESTING EMPLOYEE        \n";
    cout << "=========================================\n\n";

    cout << ">> Setting up Employee e2...\n";
    Employee e2; 
    department(e2);
    e2.accept(); // Prompts user, reads input, and writes to file
    
    cout << "\n>> Displaying e2 details:\n";
    e2.display();

    cout << "\n>> Overloading e2 details with new data...\n";
    e2.accept(102, "Atharv", 55000, "CSE"); // Updates data and writes to file
    
    cout << "\n>> Displaying updated e2 details:\n";
    e2.display();

    cout << "\n=========================================\n";
    cout << "         STAGE 2: TESTING MANAGER        \n";
    cout << "=========================================\n\n";

    cout << ">> Displaying Parameterized Manager (m1):\n";
    Manager m1(201, "Zubiya", 90000, "IT", 15000); // Automatically saves upon initialization
    m1.displayManager();

    cout << "\n>> Setting up a new Manager (m2) via console...\n";
    Manager m2;
    department(m2); 
    m2.acceptManager(); // Prompts user, reads input, and writes both base + bonus data to file
    
    cout << "\n>> Displaying Custom Manager (m2):\n";
    m2.displayManager();

    return 0;
}
