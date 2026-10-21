#include <iostream>   
#include <exception>   
using namespace std;   

class MyException : public exception {   
public:   
    // FIXED: Removed the stray textbook watermark line
    // OPTIMIZATION: Replaced deprecated 'throw()' with 'noexcept'
    const char * what() const noexcept   
    {   
        return "Attempted to divide by zero!\n";   
    }   
};   

int main()   
{   
    try   
    {   
        int x, y;   
        cout << "Enter the two numbers : \n";   
        cin >> x >> y;   
        
        if (y == 0)   
        {   
            MyException z;   
            throw z;   
        }   
        else   
        {   
            // OPTIMIZATION: Cast to double if you want decimal results
            cout << "x / y = " << static_cast<double>(x) / y << endl;   
        }   
    }   
    catch(const exception& e)   // GOOD PRACTICE: Catch by const reference
    {   
        cout << e.what();   
    }   
    return 0;
}
