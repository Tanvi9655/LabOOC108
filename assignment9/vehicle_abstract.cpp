#include <iostream>
using namespace std;

// Abstract class
class Vehicle
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

// Derived class Car
class Car : public Vehicle
{
public:
    void start() override
    {
        cout << "Car starts with a key." << endl;
    }

    void stop() override
    {
        cout << "Car stops using brakes." << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle
{
public:
    void start() override
    {
        cout << "Bike starts with a self-start button." << endl;
    }

    void stop() override
    {
        cout << "Bike stops using brakes." << endl;
    }
};

int main()
{
    Car car;
    Bike bike;

    // Runtime polymorphism
    Vehicle *v;

    v = &car;
    v->start();
    v->stop();

    v = &bike;
    v->start();
    v->stop();

    return 0;
}