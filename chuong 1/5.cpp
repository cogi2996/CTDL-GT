#include<bits/stdc++.h>
using namespace std;
int giaiThua_i(int n,int kq)
{
	if(n==1)
		return kq;
	return giaiThua_i(n-1,kq*n);
}

int giaiThua(int n){
	if(n==0)
		return 1;
	return giaiThua_i(n,1);
}

int main()
{
	int n,kq ;	 cin>>n;
	cout <<(kq = giaiThua(n));
}
