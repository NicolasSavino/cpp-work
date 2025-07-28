/*
 Name: Nicolas Savino
 Assignment: hw4.cpp
*/
Due Date: 07/30/2025

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global variables for the problem's given parameters.
double OFFSHORE_DISTANCE = 8.0;
double INLAND_DISTANCE = 6.0;
double TOTAL_COAST_DISTANCE = 15.0;

double ROWING_SPEED = 3.0;
double BEACH_SPEED = 5.0;
double INLAND_SPEED = 4.0;

// Function to calculate the total travel time for a given path (x, y, z)
double calculateTime (double x, double y, double z);

int main ()
{
    // Seed the random number generator to ensure different results each run
    srand(time(0));

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
        // Generate three random fractions
        f1 = static_cast<double>(rand()) / RAND_MAX;
        f2 = static_cast<double>(rand()) / RAND_MAX;
        f3 = static_cast<double>(rand()) / RAND_MAX;
        f_sum = f1 + f2 + f3;

        if (f_sum == 0)
        {
            continue;
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

double calculateTime (double x, double y, double z)
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
 --------------------------------------------------------
 Finding the fastest route by simulation...
 --------------------------------------------------------
 x (miles)      y (miles)       z (miles)       Time (hours)
 --------------------------------------------------------
 7.93924        4.57803         2.48273         4.60789
 6.09543        8.51474         0.38983         4.57121
 6.07921        8.91979         0.00100         4.56832
 6.00294        8.99706         0.00000         4.56678
 ... (output continues to improve over many trials) ...
 --------------------------------------------------------
 Simulation complete.
*/
