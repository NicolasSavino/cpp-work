#include <iostream>
using namespace std;

int main() 
{
    double height, ratio, totalDistance = 0.0;
    const double SMALLEST_HEIGHT = 1e-6;

    cout << "Enter initial height of the bouncing ball (in meters): ";
    cin >> height;
    cout << "Enter the bouncing ratio: ";
    cin >> ratio;

    while (height > SMALLEST_HEIGHT) 
    {
        totalDistance += height;
        height *= ratio;
        totalDistance += 2 * height;
    }

    cout << "Total distance traveled: " << totalDistance << endl;
    return 0;
}
