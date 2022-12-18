#include<bits/stdc++.h>
using namespace std;
int combination(int n,int k){
	if(k==0||n==k)
		return 1;
	return combination(n-1,k-1) + combination(n-1,k);
}
int main()
{
	int n; cin>>n;
	int k; cin>>k;
	cout<<combination(n,k);
}
