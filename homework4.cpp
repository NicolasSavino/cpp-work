/*
    Name: Nicolas Savino
    Course: CISC1600
    Assignment: Homework #4
*/

// Due Date: 07/28/2025

#include <iostream>
#include <iomanip> // Required for setw()

using namespace std;

double random(unsigned int& seed);

int main()
{
    unsigned int seed;
    int generated_number, count_of_fives = 0, numbers_on_line = 0;

    const int LOWER_BOUND = 5;
    const int UPPER_BOUND = 10;
    const int TARGET_VALUE = 5;
    const int TARGET_COUNT = 6;
    const int NUMBERS_PER_LINE = 10;
    const int FIELD_WIDTH = 3; // Width for each number column

    cout << "Please enter a non-negative integer for the seed: ";
    cin >> seed;
    cout << endl;

    while (count_of_fives < TARGET_COUNT)
    {
        generated_number = static_cast<int>(random(seed) * (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;

        // Use setw() to align numbers in columns
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

double random(unsigned int& seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;

    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

    return static_cast<double>(seed) / MODULUS;
}

/*
    Sample Output:

    Please enter a non-negative integer for the seed: 42

      8 10  5  7  9  6  8 10  5  7
      9  6  8 10  5  7  9  6  8 10
      5  7  9  6  8 10  5  7  9  6

    Program finished after generating 6 fives.
*/
