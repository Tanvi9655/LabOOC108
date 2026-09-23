#include <iostream>
using namespace std;

class Patient
{
    string name;
    int age;
    float charges;

public:
    void registerPatient()
    {
        cout << "Enter Patient Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;
    }

    void calculateCharges()
    {
        charges = 500;
    }

    void display()
    {
        cout << "\nPatient Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Consultation Charges: Rs. " << charges << endl;
    }
};

int main()
{
    Patient p;

    p.registerPatient();
    p.calculateCharges();
    p.display();

    return 0;
}