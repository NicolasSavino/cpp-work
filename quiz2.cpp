/*
 Name: Nicolas Savino
 Assignment: quiz2.cpp
 Class: CISC1600
 Date: 07/30/2025
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* Global Variables */
const double ACC = 1e-6; /* Required accuracy constant for x and y */
double a;                /* Semi-major axis */
double b;                /* Semi-minor axis */
double x_coord;          /* Optimal x-coordinate */
double y_coord;          /* Optimal y-coordinate */
double max_area;         /* Maximum area */

/* Function Prototypes */
void getInput();
void calculateOptimalDimensions();
double calculateY(double x);
double getArea(double x);
void displayResults();

int main()
{
    getInput();
    calculateOptimalDimensions();
    displayResults();
    return 0;
}

void getInput()
{
    do
    {
        cout << "Enter the semi-major axis (a): ";
        cin >> a;
    } while (a <= 0);

    do
    {
        cout << "Enter the semi-minor axis (b): ";
        cin >> b;
    } while (b <= 0);
}

double calculateY(double x)
{
    if (a * a < x * x)
    {
        return 0.0;
    }
    return (b / a) * sqrt(a * a - x * x);
}

double getArea(double x)
{
    if (x < 0 || x > a)
    {
        return 0;
    }
    return 4.0 * x * calculateY(x);
}

void calculateOptimalDimensions()
{
    double left = 0;
    double right = a;

    /*
     * Perform a ternary search to find the value of x that maximizes the area.
     * The loop continues until the search interval is smaller than the required
     * accuracy (ACC), thus explicitly using the ACC constant in the computation.
    */
    while ((right - left) > ACC)
    {
        double m1 = left + (right - left) / 3.0;
        double m2 = right - (right - left) / 3.0;
        if (getArea(m1) < getArea(m2))
        {
            left = m1;
        }
        else
        {
            right = m2;
        }
    }

    /* The optimal x is the midpoint of the final interval */
    x_coord = (left + right) / 2.0;
    y_coord = calculateY(x_coord);
    max_area = getArea(x_coord);
}

void displayResults()
{
    cout << endl;
    /* Set output precision to 6 decimal places for all results */
    cout << fixed << setprecision(6);

    /* Use I/O manipulators for aligned output */
    cout << left << setw(7) << "x" << "= " << right << x_coord << endl;
    cout << left << setw(7) << "y" << "= " << right << y_coord << endl;
    cout << left << setw(7) << "area" << "= " << right << max_area << endl;
}

/*
Sample Output (with input validation):

Enter the semi-major axis (a): -5
Enter the semi-major axis (a): 0
Enter the semi-major axis (a): 3
Enter the semi-minor axis (b): -1
Enter the semi-minor axis (b): 2

x      = 2.121320
y      = 1.414214
area   = 12.000000
*/
