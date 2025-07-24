#include <iostream>

using namespace std;

int factorial(int n)
{
    int product = 1;

    if (n == 0)
    {
        return 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        product = product * i;
    }

    return product;
}

int main()
{
    int number;

    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
    }
    else
    {
        int result = factorial(number);
        cout << number << "! = " << result << endl;
    }

    return 0;
}
