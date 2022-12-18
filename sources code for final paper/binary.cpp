#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate y^n using the binary method
int binaryMethod(int y, int n)
{
    int result = 1;

    // While n is greater than 0
    while (n > 0)
    {
        // If n is odd, multiply result by y
        if (n % 2 == 1)
        {
            cout << "y^n = " << result << " * " << y << " = ";
            result *= y;
            cout << result << endl;
        }

        // Divide n by 2 and square y
        n /= 2;
        y *= y;

        cout << "n = " << n << ", y = " << y << endl;
    }

    return result;
}

int main()
{
    int y = 2, n = 13;

    cout << "y^n = " << binaryMethod(y, n) << endl;

    return 0;
}
