#include <iostream>
#include <fstream>   // For File Handling (ifstream, ofstream)
#include <string>
#include <stdexcept> // For Try-Catch block exceptions

using namespace std;

// ==========================================
// 1. BASE CLASS
// ==========================================
class Person {
protected:
    string name;

public:
    // Simple Constructor
    Person(string n) {
        name = n;
        cout << "[Base Constructor] Person " << name << " created." << endl;
    }

    // Virtual Destructor
    virtual ~Person() {
        cout << "[Base Destructor] Person " << name << " destroyed." << endl;
    }

    // 2. VIRTUAL FUNCTION
    virtual void displayInfo() {
        cout << "Name: " << name << " (General Person)" << endl;
    }
};

// ==========================================
// 3. INHERITANCE (Employee inherits from Person)
// ==========================================
class Employee : public Person {
private:
    int id;
    double salary;

public:
    // Simple Constructor (Calls the base constructor first)
    Employee(string n, int i, double s) : Person(n) {
        id = i;
        salary = s;
        cout << "[Derived Constructor] Employee data loaded." << endl;
    }

    // Destructor
    ~Employee() {
        cout << "[Derived Destructor] Employee data cleared." << endl;
    }

    // Overriding Virtual Function
    void displayInfo() override {
        cout << "ID: " << id << " | Name: " << name << " | Salary: $" << salary << endl;
    }

    // 4. FUNCTION OVERLOADING
    // Version 1: Adds a flat bonus
    void updateSalary(double bonus) {
        salary = salary + bonus;
    }

    // Version 2: Adds a percentage hike
    void updateSalary(int percentage) {
        salary = salary + (salary * percentage / 100);
    }

    // 5. FILE HANDLING: WRITING INITIAL DATA
    static void saveAllToFile(string filename, Employee* arr[], int count) {
        ofstream outFile(filename);

        // 6. TRY-CATCH BLOCK
        try {
            if (!outFile) {
                throw runtime_error("Error: Could not open file for writing!");
            }

            for (int i = 0; i < count; i++) {
                outFile << arr[i]->id << " " << arr[i]->name << " " << arr[i]->salary << endl;
            }

            outFile.close();
            cout << "\nSuccessfully saved " << count << " employee(s) to '" << filename << "'." << endl;
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }

    // 5 (Cont.). FILE HANDLING: APPEND A SINGLE RECORD
    static void appendToFile(string filename, int inputId, string inputName, double inputSalary) {
        ofstream outFile(filename, ios::app); 

        try {
            if (!outFile) {
                throw runtime_error("Error: Could not open file to add new record!");
            }

            outFile << inputId << " " << inputName << " " << inputSalary << endl;
            outFile.close();
            cout << "\nSuccessfully added your new record to the file!" << endl;
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }

    // 5 (Cont.). FILE HANDLING: READING COMBINED OUTPUTS
    static void readAllFromFile(string filename) {
        ifstream inFile(filename);

        try {
            if (!inFile) {
                throw runtime_error("Error: Could not open file for reading!");
            }

            cout << "\n===============================" << endl;
            cout << "     CURRENT COMPANY RECORDS   " << endl;
            cout << "===============================" << endl;
            
            int fileId;
            string fileName;
            double fileSalary;

            while (inFile >> fileId >> fileName >> fileSalary) {
                cout << "ID: " << fileId << " | Name: " << fileName << " | Salary: $" << fileSalary << endl;
            }
            cout << "===============================" << endl;

            inFile.close();
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }
};

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    cout << "--- Creating Multiple Employees ---" << endl;
    int totalCount = 3;
    Employee* empList[3];

    // Simple assignments matching your expected values
    empList[0] = new Employee("Alice", 101, 55000);
    empList[1] = new Employee("Bob", 102, 66000);
    empList[2] = new Employee("Charlie", 103, 70000);

    cout << "\n--- Updating Salaries ---" << endl;
    // (Kept empty to replicate your console dump timeline precisely)

    cout << "\n--- Displaying Employee Info via Polymorphism ---" << endl;
    for (int i = 0; i < totalCount; i++) {
        empList[i]->displayInfo();
    }

    string dbFile = "company_records.txt";
    Employee::saveAllToFile(dbFile, empList, totalCount);

    // Prompting for user's explicit record (e.g. Tanvi)
    int newId;
    string newName;
    double newSalary;

    cout << "\n--- Add Your Own New Employee Record ---" << endl;
    cout << "Enter Employee ID (Number): ";
    cin >> newId;
    cout << "Enter Employee Name (Single Word): ";
    cin >> newName;
    cout << "Enter Employee Salary (Number): ";
    cin >> newSalary;

    // Append record and read everything back layout
    Employee::appendToFile(dbFile, newId, newName, newSalary);
    Employee::readAllFromFile(dbFile);

    // Destructors running on cleanup 
    cout << "\n--- Cleaning up Memory ---" << endl;
    for (int i = 0; i < totalCount; i++) {
        delete empList[i];
    }

    return 0;
}
