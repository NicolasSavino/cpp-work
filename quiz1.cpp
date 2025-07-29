/*
      Name: Nicolas Savino
Assignment: quiz1.cpp
 quiz1 date: 07/29/2025
*/

#include <iostream>

using namespace std;

// --- Global variables (doubles) ---
const double INITIAL_AREA = 4.0;
const double DECAY_FACTOR = 0.5;
const double TARGET_SUM   = 255.0 / 32.0;
double       current_area = INITIAL_AREA;
double       current_sum  = 0.0;

int main()
{
    int num_squares = 0;

    // --- Sum areas until target reached ---
    while (current_sum < TARGET_SUM)
    {
        current_sum  += current_area;
        current_area *= DECAY_FACTOR;
        num_squares++;
    }

    // --- Output result ---
    cout << "   Number of squares = " << num_squares << endl;
    cout << endl;

    return 0;
}

/*
Sample output:

   Number of squares = 8

*/
