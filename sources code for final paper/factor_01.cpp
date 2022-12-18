#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate y^n using the factor method
int factorMethod(int y, int n, string prefix, int result)
{
    // While n is greater than 0
    while (n > 0)
    {
        // If n is odd, multiply result by y
        if (n % 2 == 1)
        {
            cout << prefix << "S(" << n << "," << y << ") = " << result << " * " << y << " = ";
            result *= y;
            cout << result << endl;
        }

        // Divide n by 2 and square y
        n /= 2;
        y *= y;

        prefix += "\t";
    }

    return result;
}

int main()
{
    int y = 2, n = 13;

    cout << "S(" << n << ",1) = " << factorMethod(y, n, "", 1) << endl;

    return 0;
}



//The binary method and the factor method are actually the same algorithm, just with different names. Both methods use the same identity to calculate y^n by repeatedly dividing n by 2 and squaring y until n becomes 0. If n is odd, both methods multiply the result by y before dividing n by 2.

//The difference between the two methods is in how they approach the problem. The binary method uses a loop to iteratively divide n by 2 and square y until n becomes 0, while the factor method uses a recursive function to break the problem down into smaller subproblems and solve them recursively. However, both methods use the same identity to calculate y^n and both have the same time complexity of O(log n).

//I hope this clears things up! Let me know if you have any other questions.