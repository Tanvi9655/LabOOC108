#include <iostream>
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
}