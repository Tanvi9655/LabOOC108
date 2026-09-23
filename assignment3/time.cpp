#include <iostream>
using namespace std;

class Time
{
    int h, m, s;

public:
    void accept()
    {
        cout << "Enter hours: ";
        cin >> h;

        cout << "Enter minutes: ";
        cin >> m;

        cout << "Enter seconds: ";
        cin >> s;
    }

    void add(Time t1, Time t2)
    {
        s = t1.s + t2.s;
        m = t1.m + t2.m;
        h = t1.h + t2.h;

        if (s >= 60)
        {
            s = s - 60;
            m++;
        }

        if (m >= 60)
        {
            m = m - 60;
            h++;
        }
    }

    void display()
    {
        cout << "Resultant Time: "
             << h << ":" << m << ":" << s << endl;
    }
};

int main()
{
    Time t1, t2, t3;

    cout << "Enter first time:\n";
    t1.accept();

    cout << "\nEnter second time:\n";
    t2.accept();

    t3.add(t1, t2);

    cout << "\n";
    t3.display();

    return 0;
}