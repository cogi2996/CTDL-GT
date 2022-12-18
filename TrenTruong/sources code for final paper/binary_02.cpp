#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate y^n using the binary method
int binaryMethod(int y, int n)
{
    // Base case: if n is 0, y^n = 1
    if (n == 0)
        return 1;

    // Recursive case: if n is even, y^n = (y^(n/2))^2
    if (n % 2 == 0)
    {
        cout << "y^n = y^(" << n << "/2) * y^(" << n << "/2)" << endl;
        return binaryMethod(y, n / 2) * binaryMethod(y, n / 2);
    }

    // Recursive case: if n is odd, y^n = y * (y^((n-1)/2))^2
    else
    {
        cout << "y^n = y * y^((" << n << "-1)/2) * y^((" << n << "-1)/2)" << endl;
        return y * binaryMethod(y, (n - 1) / 2) * binaryMethod(y, (n - 1) / 2);
    }
}

int main()
{
    int y = 2, n = 13;

    cout << "y^n = " << binaryMethod(y, n) << endl;

    return 0;
}