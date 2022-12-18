    #include <iostream>
#include <cmath>

using namespace std;

// Function to calculate y^n using the factor method
int factorMethod(int y, int n)
{
    // Base case: if n is 0, y^n = 1
    if (n == 0)
        return 1;

    // Recursive case: if n is even, y^n = (y^(n/2))^2
    if (n % 2 == 0)
        return factorMethod(y, n / 2) * factorMethod(y, n / 2);

    // Recursive case: if n is odd, y^n = y * (y^((n-1)/2))^2
    else
        return y * factorMethod(y, (n - 1) / 2) * factorMethod(y, (n - 1) / 2);
}

int main()
{
    int y = 2, n = 13;

    cout << "y^n = " << factorMethod(y, n) << endl;

    return 0;
}