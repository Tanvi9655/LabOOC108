#include <iostream>
using namespace std;

class construct {
public:
    float area;

    // Default constructor (no parameters)
    construct() {
        area = 0;
    }

    // Parameterized constructor (two parameters)
    construct(int a, int b) {
        area = a * b;
    }

    // Method to display the area
    void disp() {
        cout << area << endl;
    }
};

int main() {
    // Constructor Overloading demonstration
    
    // Calls the default constructor (area initialized to 0)
    construct o;
    
    // Calls the parameterized constructor (area = 10 * 20)
    construct o2(10, 20);

    // Display values
    o.disp();   // Outputs: 0
    o2.disp();  // Outputs: 200

    return 0;
}
