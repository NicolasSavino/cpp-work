/*
 Name: Nicolas Savino
 Assignment: hw5.cpp
 Due Date: 07/30/2025
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate the total travel time for a given path (x, y, z)
double calculateTime (double x, double y, double z);

int main ()
{
    // Seed the random number generator to ensure different results each run
    srand(time(0));

    // Variables to store the components of the path
    double x, y, z;

    // Variables for generating random fractions
    double f1, f2, f3, f_sum;

    // Variables to track the current time and the minimum time found so far
    double currentTime = 0.0;
    // Initialize minTime to a very large value to ensure the first calculation is smaller
    double minTime = 1000.0; 

    // Define the number of trials for the simulation.
    // A larger number increases the chance of finding a better result.
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
        // Generate three random fractions between 0.0 and 1.0
        f1 = static_cast<double>(rand()) / RAND_MAX;
        f2 = static_cast<double>(rand()) / RAND_MAX;
        f3 = static_cast<double>(rand()) / RAND_MAX;
        f_sum = f1 + f2 + f3;

        // Avoid division by zero, though it's highly unlikely
        if (f_sum == 0)
        {
            continue;
        }

        // Calculate x, y, and z based on the random fractions.
        // This method ensures x + y + z always equals 15.
        x = 15.0 * (f1 / f_sum);
        y = 15.0 * (f2 / f_sum);
        z = 15.0 * (f3 / f_sum);

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
    // Time rowing from Boat to C: distance / speed = sqrt(8^2 + x^2) / 3
    double timeRowing = sqrt(64.0 + x * x) / 3.0;

    // Time running on beach from C to D: distance / speed = y / 5
    double timeOnBeach = y / 5.0;

    // Time running inland from D to Hotel: distance / speed = sqrt(6^2 + z^2) / 4
    double timeInland = sqrt(36.0 + z * z) / 4.0;

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
