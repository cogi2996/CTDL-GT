#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[],int n,int x)
{
	int i = 0;
	do
	{
		if(a[i]==x)
			return i;
	}
	while(a[i++]!= x&&i<n);
	return -1;
}


int main ()
{
	int a[]   = {1,24,3,4,5,3};
	int n = 6;
	int x; cin>>x;
	cout<<linear_search(a,n,x);
}
