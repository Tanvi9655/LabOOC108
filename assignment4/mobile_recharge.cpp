#include <iostream>
using namespace std;

class MobileRecharge
{
    string number;
    float balance;

public:
    void accept()
    {
        cout << "Enter Mobile Number: ";
        cin >> number;

        cout << "Enter Balance: ";
        cin >> balance;
    }

    void recharge(float amount)
    {
        balance = balance + amount;
        cout << "Recharge successful." << endl;
    }

    void deduct(float amount)
    {
        balance = balance - amount;
        cout << "Amount deducted." << endl;
    }

    void display()
    {
        cout << "\nMobile Number: " << number << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    MobileRecharge m;

    m.accept();
    m.display();

    m.recharge(100);
    m.display();

    m.deduct(50);
    m.display();

    return 0;
}