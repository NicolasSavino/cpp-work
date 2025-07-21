#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    double height = 0.0, ratio = 0.0, totalDistance = 0.0;

    cout << "Enter the initial height of the bouncing ball: ";
    cin >> height;

    cout << "Enter the bouncing ratio: ";
    cin >> ratio;

    if (height <= 0) 
    {
        cout << "\nError: Height must be a positive number." << endl;
        return 1;
    }

    if (ratio < 0 || ratio >= 1) 
    {
        cout << "\nError: The ratio must be between 0 and 1." << endl;
        return 1;
    }

    totalDistance = height;
    
    while ((height * ratio) > 1e-12) 
    {
        height *= ratio;
        totalDistance += 2 * height;
    }

    cout << fixed << setprecision(4);
    cout << "\nTotal distance traveled: " << totalDistance << " units" << endl;

    return 0;
}
