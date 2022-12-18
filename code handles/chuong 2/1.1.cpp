#include<bits/stdc++.h>
using namespace std;

int tong(int n)
{
	if(n==1)
		return 1;
	return n+ tong (n-1);
}
// de quy tuyen tinh
int main()
{
	int n;cin>>n;
	cout<<tong(n);
}
