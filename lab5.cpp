#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double heron(double a, double b, double c);

int main() 
{
    double a, b, c;

    do 
    {
        cout << "a=";
        cin >> a;
    } 
    while (a <= 0);

    do 
    {
        cout << "b=";
        cin >> b;
    } 
    while (b <= 0);

    do 
    {
        cout << "c=";
        cin >> c;
    } 
    while (a + b <= c || a + c <= b || b + c <= a || c <= 0);

    double area = heron(a, b, c);

    cout << fixed << setprecision(2);
    cout << "Area of triangle = " << area << endl;

    return 0;
}

double heron(double a, double b, double c) 
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
