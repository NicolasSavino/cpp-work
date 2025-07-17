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
        cout << "Error: 'a' cannot be zero in a quadratic equation." << endl;
    else 
    {
        discriminant = b*b - 4*a*c;
        if (discriminant > 0) 
        {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (discriminant == 0) 
        {
            x1 = -b / (2 * a);
            cout << "x1 = x2 = " << x1 << endl;
        }
        else
            cout << "No real roots" << endl;
    }

    return 0;
}
