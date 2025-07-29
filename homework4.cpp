/*
    Name: Nicolas Savino
    Course: CISC1600
    Assignment: Homework #4
*/

// Due Date: 07/28/2025

#include <iostream>
#include <iomanip> // Required for setw()
#include <ctime>   // Required for time()

using namespace std;

// Function provided by professor
double random(unsigned int &seed);

int main()
{
    // Seed the random number generator with the current system time
    unsigned int seed = static_cast<unsigned int>(time(NULL));

    int generated_number, count_of_fives = 0, numbers_on_line = 0;

    const int LOWER_BOUND = 5;
    const int UPPER_BOUND = 10;
    const int TARGET_VALUE = 5;
    const int TARGET_COUNT = 6;
    const int NUMBERS_PER_LINE = 10;
    const int FIELD_WIDTH = 4; // Adjusted for perfect spacing

    cout << "The program will now generate random numbers..." << endl << endl;

    while (count_of_fives < TARGET_COUNT)
    {
        generated_number = static_cast<int>(random(seed) * (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;

        // Use setw() to align numbers in perfectly spaced columns
        cout << setw(FIELD_WIDTH) << generated_number;
        numbers_on_line++;

        if (generated_number == TARGET_VALUE)
        {
            count_of_fives++;
        }

        if (numbers_on_line % NUMBERS_PER_LINE == 0)
        {
            cout << endl;
        }
    }

    cout << "\n\nProgram finished after generating " << TARGET_COUNT << " fives." << endl;

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

/*
    Sample Output (numbers will vary on each run):

    The program will now generate random numbers...

       9   7   5   8   6  10   7   5   9   7
      10   8   6   5   8   6  10   7   5   9
       7  10   8   6   5   8   6  10   7   5
*/