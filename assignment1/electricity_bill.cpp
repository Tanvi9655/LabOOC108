#include <iostream>
using namespace std;

int main()
{
    string name;
    int units;
    float bill;

    cout << "Enter Consumer Name: ";
    cin >> name;

    cout << "Enter Units Consumed: ";
    cin >> units;

    if (units <= 100)
        bill = units * 5;
    else if (units <= 200)
        bill = 100 * 5 + (units - 100) * 7;
    else if (units <= 300)
        bill = 100 * 5 + 100 * 7 + (units - 200) * 10;
    else
        bill = 100 * 5 + 100 * 7 + 100 * 10 + (units - 300) * 12;

    cout << "\nConsumer Name: " << name;
    cout << "\nUnits Consumed: " << units;
    cout << "\nTotal Bill: Rs. " << bill << endl;

    return 0;
}