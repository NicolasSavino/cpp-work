#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, discriminant, x1, x2;

    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "Error: 'a' cannot be zero in a quadratic equation." << endl;
    }
    else
    {
        discriminant = b*b - 4*a*c;

        if (discriminant < 0)
        {
            cout << "No real roots exist." << endl;
        }
        else
        {
            if (b != 0 && b*b > 20 * (4*a*c))
            {
                x1 = (-b - (b / abs(b)) * sqrt(discriminant)) / (2 * a);
                x2 = c / (a * x1);
            }
            else
            {
                if (discriminant == 0)
                {
                    x1 = -b / (2 * a);
                    x2 = x1;
                }
                else
                {
                    x1 = (-b + sqrt(discriminant)) / (2 * a);
                    x2 = (-b - sqrt(discriminant)) / (2 * a);
                }
            }
            
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }

    return 0;
}
