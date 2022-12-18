#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the result of a number raised to a power
// using the square and multiply algorithm
long long squareAndMultiply(long long a, long long b, long long m)
{
    long long result = 1;
    a %= m;

    // Repeatedly square the number and multiply by the original
    // number whenever the power being calculated is odd
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % m;

        b = b >> 1;
        a = (a * a) % m;
    }

    return result;
}

int main()
{
    long long a = 2, b = 10, m = 100;
    cout << "Result of " << a << "^" << b << " mod " << m << ": ";
    cout << squareAndMultiply(a, b, m) << endl;

    return 0;
}
