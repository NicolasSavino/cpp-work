#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double a, b, c, discriminant, x1, x2;

    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;

    if (a == 0) 
    {
        cout << "Error: 'a' cannot be zero in a quadratic equation." << endl;
        return 1;
    }

    discriminant = b*b - 4*a*c;

    if (discriminant < 0)
    {
        cout << "No real roots exist." << endl;
    }
    else 
    {
        if (b*b >= 10 * (4*a*c))
        {
            x1 = (-b - copysign(1.0, b) * sqrt(discriminant)) / (2 * a);
            x2 = c / (a * x1);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else 
        {
            if (discriminant == 0)
            {
                x1 = -b / (2 * a);
                cout << "x1 = x2 = " << x1 << endl;
            }
            else
            {
                x1 = (-b + sqrt(discriminant)) / (2 * a);
                x2 = (-b - sqrt(discriminant)) / (2 * a);
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
        }
    }

    return 0;
}
