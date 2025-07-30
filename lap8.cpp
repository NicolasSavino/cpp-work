/*
      Name: Nicolas Savino
Assignment: lab8.cpp
 lab8 date: 07/29/2025
*/

#include <iostream>
#include <iomanip>
#include <cmath>      // for fabs

using namespace std;

const double ACC  = 1e-6;
const double INCR = 1e-9;
const double PI   = 3.1415926535;

void enter_large_r(double & r);
double small_r(double large_r);

int main()
{
    double large_r, s_r;

    enter_large_r(large_r);
    s_r = small_r(large_r);

    cout << endl;
    cout << fixed << setprecision(5);
    cout << "Large radius: " << setw(12) << large_r << endl;
    cout << "Found small r:" << setw(12) << s_r << endl;
    cout << endl;

    return 0;
}

void enter_large_r(double & r)
{
    do
    {
        cout << "Enter large radius (r > 0): ";
        cin  >> r;
    }
    while (r <= 0);
}

double small_r(double large_r)
{
    double larger_area = PI * large_r * large_r;

    double r           = 0.0;
    double small_area  = 0.0;

    do
    {
        r += INCR;
        small_area = PI * r * r;
    }
    while (fabs(larger_area - 2.0 * small_area) > ACC);

    return r;
}
