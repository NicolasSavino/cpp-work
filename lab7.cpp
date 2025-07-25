/*
 * Name: Nicolas Savino
 * Assignment: lab7.cpp
 * Date: 07/24/2025
 *
 * Description: This program estimates the value of Pi using the Monte Carlo method.
 * It generates a large number of random points in a unit square and calculates
 * the ratio of points that fall within the inscribed quarter unit circle.
 * The value of Pi is then estimated using the formula: Pi = 4 * (points_in_circle / total_points).
 * The program uses a specific pseudo-random number generator as required.
*/

#include <iostream>
#include <iomanip>

// Global Constant
const int TOTAL_POINTS = 100000;

using namespace std;

// Function Prototypes
double random(unsigned int &seed);
double calculate_pi(int n, unsigned int &seed);

int main()
{
    // Initialize seed. We use its memory address to get a different
    unsigned int seed = 0;
    seed = (long unsigned int)&seed;

    // Call the function to calculate Pi
    double pi_estimate = calculate_pi(TOTAL_POINTS, seed);

    cout << endl;
    cout << "Total points = " << TOTAL_POINTS << endl;
    cout << fixed << setprecision(6);
    cout << "Pi estimate  = " << pi_estimate << endl;
    cout << endl;

    return 0;
}

/*
 * This function generates a pseudo-random double between 0.0 and 1.0.
 * It uses a linear congruential generator (LCG) algorithm. It takes an
 * initial seed by reference and updates it with each call, ensuring a
 * different sequence of numbers for subsequent calls.
*/
double random(unsigned int &seed)
{
    const int MODULUS    = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT  = 1;

    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

    return double(seed) / MODULUS;
}

/*
 * This function estimates the value of Pi using the Monte Carlo method.
 * It simulates throwing darts at a square board containing a quarter circle
 * by generating 'n' random points (x, y) and counting how many land inside
 * the circle. The formula Pi = 4 * (points_in_circle / total_points) is
 * then used for the estimation.
*/
double calculate_pi(int n, unsigned int &seed)
{
    int points_in_circle = 0;
    double x, y;

    for (int i = 0; i < n; ++i)
    {
        x = random(seed);
        y = random(seed);

        if ((x * x + y * y) <= 1)
        {
            points_in_circle++;
        }
    }

    return 4.0 * points_in_circle / n;
}

/*
 Sample Output:
 (Note: The estimated value of Pi will vary slightly with each run)

 /u/dsm/nsavino/class/cslu1600]$ ./lab7

 Total points = 100000
 Pi estimate  = 3.141600

 /u/dsm/nsavino/class/cslu1600]$
*/
