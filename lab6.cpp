#include <iostream>
#include <ctime>

using namespace std;

const int MIN_SIDE_LENGTH = 1;
const int MAX_SIDE_LENGTH = 10;
const int MINIMUM_AREA = 10;
const int RANGE_SIZE = MAX_SIDE_LENGTH - MIN_SIDE_LENGTH + 1;

double random(unsigned int & seed);

int main()
{
    unsigned int seed = time(0);
    int a;
    int b;

    cout << "Finding a rectangle with an area of at least " << MINIMUM_AREA << "..." << endl;

    do
    {
        a = int(random(seed) * RANGE_SIZE) + MIN_SIDE_LENGTH;
        b = int(random(seed) * RANGE_SIZE) + MIN_SIDE_LENGTH;
    }
    while ((a * b) < MINIMUM_AREA);

    cout << "------------------------------------------------" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "area = " << (a * b) << endl;
    cout << "------------------------------------------------" << endl;

    return 0;
}

double random(unsigned int & seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;

    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

    return double(seed) / MODULUS;
}
