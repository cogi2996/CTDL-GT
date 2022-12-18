#include<iostream>
using namespace std;
// cach khong su dung de quy
int main()
{
	int n; cin>>n;
	int a; cin>>a;
	int kq  =1;
	for(int i = 1;i<=n;i++)
		kq = kq*a;
	cout<<kq;
}
