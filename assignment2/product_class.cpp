#include <iostream>
using namespace std;

class Product
{
    int id, quantity;
    string name;
    float price, total;

public:

    void accept()
    {
        cout << "Enter Product ID: ";
        cin >> id;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Unit Price: ";
        cin >> price;
    }

    void calculate()
    {
        total = quantity * price;
    }

    void display()
    {
        cout << "\nProduct ID: " << id;
        cout << "\nProduct Name: " << name;
        cout << "\nQuantity: " << quantity;
        cout << "\nUnit Price: " << price;
        cout << "\nTotal Cost: " << total << endl;
    }
};

int main()
{
    Product p;

    p.accept();
    p.calculate();
    p.display();

    return 0;
}