/*
 Name: Nicolas Savino
 Assignment: quiz3.cpp
 Class: CISC1600
 Date: 08/01/2025
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Prototypes
double f(double x);
double find_root();

int main()
{
    cout << "C++ Root Finding Program" << endl;
    cout << "Function: f(x) = 2 * e^(-x) * sin(3x)" << endl;
    cout << "---------------------------------------" << endl;

    // Call the function that performs the root finding algorithm
    double root = find_root();

    // Check if the root finding was successful before printing the result
    if (root != -1.0)
    {
        cout << "A root was found at x = " << fixed << setprecision(8) << root << endl;
        cout << "The value of the function at this root is f(x) = " << f(root) << endl;
    }

    return 0;
}

// Implements the mathematical function f(x) = 2 * e^(-x) * sin(3x).
double f(double x)
{
    return 2.0 * exp(-x) * sin(3.0 * x);
}

// Finds a root of the function f(x) using the bisection method.
double find_root()
{
    // Define constants for the search in ALL_CAPS as per formatting rules.
    const double SEARCH_MIN = 0.0;
    const double SEARCH_MAX = 5.0;
    const double TOLERANCE = 0.00001;
    const double STEP = 0.1;

    double x_left = -1.0;
    double x_right = -1.0;

    // Step 1: Find an initial interval [x_left, x_right]
    // We start at a point slightly greater than 0 to avoid the trivial root at x=0.
    for (double current_x = SEARCH_MIN + 0.01; current_x < SEARCH_MAX; current_x += STEP)
    {
        if (f(current_x) * f(current_x + STEP) < 0)
        {
            x_left = current_x;
            x_right = current_x + STEP;
            break; // Found an interval, exit the loop
        }
    }

    // Check if we successfully found an interval
    if (x_left == -1.0)
    {
        cout << "Error: Could not find a valid starting interval." << endl;
        return -1.0; // Return an error value
    }

    // Step 2 & 3: Repeatedly bisect the interval
    double x_mid = (x_left + x_right) / 2.0;

    // Loop until the value at x_mid is close to 0
    while (fabs(f(x_mid)) > TOLERANCE)
    {
        // If the sign change is between x_left and x_mid, move the right boundary
        if (f(x_left) * f(x_mid) < 0)
        {
            x_right = x_mid;
        }
        // Otherwise, move the left boundary
        else
        {
            x_left = x_mid;
        }

        // Recalculate the midpoint for the new, smaller interval
        x_mid = (x_left + x_right) / 2.0;
    }

    return x_mid;
}

/*
Sample output:

$ ./a.out
C++ Root Finding Program
Function: f(x) = 2 * e^(-x) * sin(3x)
---------------------------------------
A root was found at x = 1.04719755
The value of the function at this root is f(x) = -0.00000197

*/
