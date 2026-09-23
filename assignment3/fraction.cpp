#include <iostream>
using namespace std;

class Fraction
{
    int num, den;

public:
    void accept()
    {
        cout << "Enter numerator: ";
        cin >> num;

        cout << "Enter denominator: ";
        cin >> den;
    }

    void add(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.den + f2.num * f1.den;
        den = f1.den * f2.den;
    }

    void subtract(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.den - f2.num * f1.den;
        den = f1.den * f2.den;
    }

    void display()
    {
        cout << num << "/" << den << endl;
    }
};

int main()
{
    Fraction f1, f2, sum, diff;

    cout << "Enter first fraction:\n";
    f1.accept();

    cout << "Enter second fraction:\n";
    f2.accept();

    sum.add(f1, f2);
    diff.subtract(f1, f2);

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}