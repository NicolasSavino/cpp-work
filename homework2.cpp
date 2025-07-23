#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double h;
    double r;
    double totalDistance;

    do
    {
        cout << "Enter the initial height (h > 0): ";
        cin >> h;
    }
    while (h <= 0);

    do
    {
        cout << "Enter the bouncing ratio (0 <= r < 1): ";
        cin >> r;
    }
    while (r < 0 || r >= 1);

    totalDistance = h;

    if (r > 0)
    {
        do
        {
            h = h * r;
            totalDistance = totalDistance + (h * 2);
        }
        while (h > 0);
    }

    cout << fixed << setprecision(4);
    cout << "\nTotal distance traveled: " << totalDistance << endl;

    return 0;
}
