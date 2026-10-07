//+ operator//
#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;

    // Default constructor
    Distance()
    {
        feet = 0;
        inch = 0;
    }

    // Parameterized constructor
    Distance(int f, int i)
    {
        feet = f;
        inch = i;
    }

    // Overloading + operator
    Distance operator+(Distance &d2)
    {
        Distance d3;
        cout<< "I am from operator"<<d2.feet;
        d3.feet = feet + d2.feet;
        d3.inch = inch + d2.inch;
        
        return d3;
    }
};

int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;

    d3 = d2+d1;

    cout << "\nTotal Feet & Inches: "
         << d3.feet << "'" << d3.inch;

    return 0;
}

/*#include <iostream>
using namespace std;

class MyClass
{
    int value;

public:

    MyClass(int v)
    {
        value = v;
    }

    bool operator==(MyClass &obj)
    {
        return value == obj.value;
    }

    bool operator!=(MyClass &obj)
    {
        return value != obj.value;
    }

    bool operator<(MyClass &obj)
    {
        return value < obj.value;
    }

    bool operator>(MyClass &obj)
    {
        return value > obj.value;
    }

    bool operator<=(MyClass &obj)
    {
        return value <= obj.value;
    }

    bool operator>=(MyClass &obj)
    {
        return value >= obj.value;
    }
};

int main()
{
    MyClass obj1(20);
    MyClass obj2(20);

    if (obj1 == obj2)
        cout << "obj1 is equal to obj2" << endl;

    if (obj1 != obj2)
        cout << "obj1 is not equal to obj2" << endl;

    if (obj1 < obj2)
        cout << "obj1 is less than obj2" << endl;

    if (obj1 > obj2)
        cout << "obj1 is greater than obj2" << endl;

    if (obj1 <= obj2)
        cout << "obj1 is less than or equal to obj2" << endl;

    if (obj1 >= obj2)
        cout << "obj1 is greater than or equal to obj2" << endl;

    return 0;
}*/