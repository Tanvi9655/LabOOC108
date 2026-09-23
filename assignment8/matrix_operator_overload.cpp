#include <iostream>
using namespace std;

class Matrix
{
    int a[2][2];

public:
    void input()
    {
        cout << "Enter 4 elements: ";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> a[i][j];
    }

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    Matrix operator+(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                temp.a[i][j] = a[i][j] + m.a[i][j];

        return temp;
    }

    Matrix operator-(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                temp.a[i][j] = a[i][j] - m.a[i][j];

        return temp;
    }

    bool operator==(Matrix m)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (a[i][j] != m.a[i][j])
                    return false;

        return true;
    }
};

int main()
{
    Matrix m1, m2, sum, diff;

    cout << "Enter first matrix:\n";
    m1.input();

    cout << "Enter second matrix:\n";
    m2.input();

    sum = m1 + m2;
    diff = m1 - m2;

    cout << "\nAddition:\n";
    sum.display();

    cout << "\nSubtraction:\n";
    diff.display();

    if (m1 == m2)
        cout << "\nMatrices are equal.";
    else
        cout << "\nMatrices are not equal.";

    return 0;
}