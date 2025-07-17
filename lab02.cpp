#include <iostream>
#include <cmath> // for sqrt

using namespace std;

int main() {
    // Declare variables
    double a, b, c;
    double p, area;

    // Ask the user to enter the sides of the triangle
    cout << "Enter side a: ";
    cin >> a;

    cout << "Enter side b: ";
    cin >> b;

    cout << "Enter side c: ";
    cin >> c;

    // Calculate the semi-perimeter
    p = (a + b + c) / 2;

    // Use Heron's formula to calculate the area
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    // Display the area
    cout << "The area of the triangle is: " << area << endl;

    return 0;
}
