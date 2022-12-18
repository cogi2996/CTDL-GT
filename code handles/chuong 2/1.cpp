#include<bits/stdc++.h>
using namespace std;

int tong(int n,int kq){
	if(n==0)
		return kq;
	return tong(n-1,kq + n-1);
	
}
// cach dung de quy duoi
int main()
{
	int n,kq; cin>>n;
	cout<<tong(n,n);
}
