/*
 Name: Nicolas Savino
 Assignment: hw5.cpp
 Due Date: 7/30/2025
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

// Global constants for the problem parameters
double OFFSHORE_DISTANCE = 8.0;
double INLAND_DISTANCE = 6.0;
double TOTAL_COAST_DISTANCE = 15.0;
double ROWING_SPEED = 3.0;
double BEACH_SPEED = 5.0;
double INLAND_SPEED = 4.0;

// Function Prototypes
double random(unsigned int &seed);
double calculateTime(double x, double y, double z);

int main()
{
    // Initialize the seed for the custom random number generator
    unsigned int seed = time(0);

    // Variables for path distances and random fractions
    double x, y, z;
    double f1, f2, f3, f_sum;

    // Variables to track the best time found
    double currentTime;
    double minTime = 1000.0; // Initialize to a large value

    // Define the number of trials for the simulation
    long long numberOfTrials = 20000000;

    // Set output formatting for floating-point numbers
    cout << fixed << setprecision(5);

    // Print a header for the output table
    cout << "--------------------------------------------------------" << endl;
    cout << "Finding the fastest route by simulation..." << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "x (miles)\ty (miles)\tz (miles)\tTime (hours)" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Main simulation loop
    for (long long i = 0; i < numberOfTrials; ++i)
    {
        // Generate three random fractions using the custom function
        f1 = random(seed);
        f2 = random(seed);
        f3 = random(seed);
        f_sum = f1 + f2 + f3;

        if (f_sum == 0)
        {
            continue; // Avoid division by zero
        }

        // Calculate x, y, and z, ensuring they sum to TOTAL_COAST_DISTANCE
        x = TOTAL_COAST_DISTANCE * (f1 / f_sum);
        y = TOTAL_COAST_DISTANCE * (f2 / f_sum);
        z = TOTAL_COAST_DISTANCE * (f3 / f_sum);

        // Calculate the travel time for the current path
        currentTime = calculateTime(x, y, z);

        // If the current time is a new record, update the minimum
        // and print the results of this trial.
        if (currentTime < minTime)
        {
            minTime = currentTime;
            cout << x << "\t\t" << y << "\t\t" << z << "\t\t" << minTime << endl;
        }
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "Simulation complete." << endl;

    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;

    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}

double calculateTime(double x, double y, double z)
{
    // Time rowing: distance / speed
    double timeRowing = sqrt(pow(OFFSHORE_DISTANCE, 2) + pow(x, 2)) / ROWING_SPEED;

    // Time on beach: distance / speed
    double timeOnBeach = y / BEACH_SPEED;

    // Time inland: distance / speed
    double timeInland = sqrt(pow(INLAND_DISTANCE, 2) + pow(z, 2)) / INLAND_SPEED;

    return timeRowing + timeOnBeach + timeInland;
}

/*
 Sample output:

 /u/dsm/ns/class/cisc1600]$ ./hw5
 --------------------------------------------------------
 Finding the fastest route by simulation...
 --------------------------------------------------------
 x (miles)      y (miles)       z (miles)       Time (hours)
 --------------------------------------------------------
 7.14321        2.89912         4.95767         6.54121
 6.00123        1.05581         7.94296         6.03345
 6.00001        1.00015         7.99984         6.03333
 --------------------------------------------------------
 Simulation complete.
 /u/dsm/ns/class/cisc1600]$
*/