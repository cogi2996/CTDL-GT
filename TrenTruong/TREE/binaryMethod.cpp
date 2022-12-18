#include <bits/stdc++.h>
using namespace std;

int binary(int x,int n)
{
    if (n==1)
       return x;
    if (n%2==0)
    {
       int t=binary(x,n/2);
       return t*t;
    }
    else
        return x*binary(x,n-1);
}

int main()
{
    cout<<binary(2,5);

}