#include<bits/stdc++.h>
using namespace std;
// cach su dung de quy

int aPowN(int a,int n){
	if(n==0)
		return 1;
	if(n%2==0)
		return pow(aPowN(a,n/2),2);
	return pow(aPowN(a,(n-1)/2),2)*a;
}
int main()
{
	int n; cin>>n;
	int a; cin>>a;
	cout<<aPowN(a,n);
}
