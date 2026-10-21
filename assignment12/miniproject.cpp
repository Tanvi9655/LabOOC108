#include <iostream>
using namespace std;

class Employee      //1.Class
{
    public:
    int id;
    string name;
    float salary;
    string dept;  // access given to method department which is declared outside the class

    Employee()   //Default Constructor
    {
        id=0;
        name="Unknown";
        salary=0.0;
        dept="Unknown";
        
        cout<<"Default Constructor is called\n";
        cout<<"Department: "<<dept
        <<"| ID: "<<id
        <<"| Name: "<<name
        <<"| Salary: Rs. "<<salary<<endl;
        cout << "\n------------------------------------------------\n\n";
    }

    Employee(int empId,string empName,float empSalary,string empDept)   //Parameterized constructor
    {
        
        cout<<"Parameterized Constructor called:\n";
        id=empId;
        name=empName;
        salary=empSalary;
        dept=empDept;

        cout<<"Department: "<<dept
        <<"| ID: "<<id
        <<"| Name: "<<name
        <<"| Salary: Rs. "<<salary<<endl;

        cout << "\n------------------------------------------------\n\n";
    }
    void accept()    //2.Member-Function
    {
        cout<<"Enter Employee ID:";
        cin>>id;

        cout<<"Enter Employee Name:";
        cin>>name;

        cout<<"Enter Employee Basic Salary:";
        cin>>salary;
    }

    void display() 
    {
        cout << "Department: " << dept
         << " | Id: " << id
         << " | Name: " << name 
         << " | Salary: "<<salary<<endl;

        cout << "\n------------------------------------------------\n\n";
    }

    ~Employee()
    {
        cout<<"Destructor Called clearing data of name:"<<name<<endl;
        cout << "\n------------------------------------------------\n\n";
    }
};

void department(Employee &e)   //method declare and initialize outside the class
{
    cout<<"Enter Employee's Department:";
    cin>>e.dept;
}

int main()
{
    Employee e;   //Object of default constructor
    Employee e1(101,"Tanvi",50000,"CSE");  //Object of parameterized constructor
    Employee e2;  //simple object
    department(e2);
    e2.accept();
    e2.display();

    return 0;
}