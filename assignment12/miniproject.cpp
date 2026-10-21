#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

// ==========================================
// 1. EXCEPTION HANDLING
// ==========================================
class InvalidSalaryException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Salary amount cannot be negative!";
    }
};

// ==========================================
// 2. BASE CLASS (Abstraction & Virtual Functions)
// ==========================================
class Employee {
protected:
    // Data Members
    int id;
    string name;

public:
    // Constructor
    Employee(int empId = 0, string empName = "") : id(empId), name(empName) {}

    // Virtual Destructor (Good practice for inheritance)
    virtual ~Employee() {}

    // Member Functions
    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name;
    }

    // Pure virtual function if we wanted an abstract class, 
    // but a regular virtual function allows flexible runtime overriding.
    virtual double calculateTotalPay() const {
        return 0.0;
    }

    // Helper functions for File handling
    int getId() const { return id; }
    string getName() const { return name; }
};

// ==========================================
// 3. INHERITANCE (Derived Class)
// ==========================================
class FullTimeEmployee : public Employee {
private:
    // Derived class data member
    double baseSalary;

public:
    // Constructor initializing both base and derived attributes
    FullTimeEmployee(int empId = 0, string empName = "", double salary = 0.0) 
        : Employee(empId, empName) {
        
        // 4. THROWING EXCEPTION FOR VALIDATION
        if (salary < 0) {
            throw InvalidSalaryException();
        }
        baseSalary = salary;
    }

    // 5. VIRTUAL FUNCTION OVERRIDING (Polymorphism)
    void display() const override {
        Employee::display(); // Call base display
        cout << " | Base Salary: ₹" << baseSalary 
             << " | Total Pay: ₹" << calculateTotalPay() << endl;
    }

    double calculateTotalPay() const override {
        return baseSalary;
    }

    // 6. FUNCTION OVERLOADING (Compile-time Polymorphism)
    // Overload 1: Calculate bonus by a flat amount
    double calculateBonus(double flatAmount) {
        return flatAmount;
    }

    // Overload 2: Calculate bonus by a percentage of base salary
    double calculateBonus(int percentage) {
        return baseSalary * (percentage / 100.0);
    }
    
    double getSalary() const { return baseSalary; }
};

// ==========================================
// 7. FILE I/O OPERATIONS
// ==========================================
void saveEmployeeToFile(const FullTimeEmployee& emp, const string& filename) {
    // Open file in Append mode
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    // Write data separated by spaces or newlines
    outFile << emp.getId() << "\n" << emp.getName() << "\n" << emp.getSalary() << "\n";
    outFile.close();
    cout << "Employee data saved to file successfully!\n";
}

void readEmployeesFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "No existing data records found (or file missing)." << endl;
        return;
    }

    cout << "\n--- Fetching Records From File ---" << endl;
    int id;
    string name;
    double salary;

    // Read blocks of data sequentially until end-of-file
    while (inFile >> id) {
        inFile.ignore(); // Clean up newline before reading string
        getline(inFile, name);
        inFile >> salary;

        // Reconstruct object from data stream
        try {
            FullTimeEmployee temp(id, name, salary);
            temp.display();
        } catch (const exception& e) {
            cout << "Corrupted entry skipped. " << e.what() << endl;
        }
    }
    inFile.close();
}

// ==========================================
// 8. MAIN EXECUTION ENGINE
// ==========================================
int main() {
    string filename = "employees.txt";
    int choice;

    while (true) {
        cout << "\n===== EMPLOYEE MINI-PROJECT SYSTEM =====" << endl;
        cout << "1. Add New Employee Record\n";
        cout << "2. View All Employee Records\n";
        cout << "3. Exit\n";
        cout << "Enter selection: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Terminating application. Goodbye!" << endl;
            break;
        }

        if (choice == 1) {
            int id;
            string name;
            double salary;

            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore(); // Clear buffer newline
            cout << "Enter Employee Name: ";
            getline(cin, name);
            cout << "Enter Base Salary: ";
            cin >> salary;

            // 9. TRY-CATCH EXCEPTION BLOCK
            try {
                // Instantiating object will trigger validation check
                FullTimeEmployee emp(id, name, salary);
                
                // Showcasing functional overloading inside code logic
                cout << "Projected Flat Bonus (₹5000): ₹" << emp.calculateBonus(5000.0) << endl;
                cout << "Projected Performance Bonus (10%): ₹" << emp.calculateBonus(10) << endl;
                
                // Commit to storage file
                saveEmployeeToFile(emp, filename);
            } 
            catch (const InvalidSalaryException& e) {
                // Catches the specific domain error gracefully
                cerr << "\n[ALERT] " << e.what() << " Record discarded.\n" << endl;
            }
            catch (const exception& e) {
                // Catch-all for any other unanticipated standard exceptions
                cerr << "An unexpected error occurred: " << e.what() << endl;
            }
        } 
        else if (choice == 2) {
            readEmployeesFromFile(filename);
        } 
        else {
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }

    return 0;
}
