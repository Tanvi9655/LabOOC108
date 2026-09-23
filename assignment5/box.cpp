#include <iostream>
using namespace std;

class Box
{
    int length, width, height;

public:

    // Default constructor
    Box()
    {
        length = 1;
        width = 1;
        height = 1;
    }

    // Parameterized constructor
    Box(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }

    // Copy constructor
    Box(Box &b)
    {
        length = b.length;
        width = b.width;
        height = b.height;
    }

    void display()
    {
        cout << "\nLength: " << length;
        cout << "\nWidth: " << width;
        cout << "\nHeight: " << height;
        cout << "\nVolume: " << length * width * height << endl;
    }

    // Destructor
    ~Box()
    {
        cout << "\nBox object destroyed.";
    }
};

int main()
{
    Box b1;              // Default constructor
    Box b2(10, 5, 2);    // Parameterized constructor
    Box b3(b2);          // Copy constructor

    cout << "\nBox 1:";
    b1.display();

    cout << "\nBox 2:";
    b2.display();

    cout << "\nBox 3:";
    b3.display();

    return 0;
}