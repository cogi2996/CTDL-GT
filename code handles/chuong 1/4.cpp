#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n; // 1
	int a[n]; 
	for(int i = 0;i<n;i++){ // n+3
		cin>>a[i]; // 2n
	}
	sort(a,a+n); // O(nlogn)
	cout<<"Min array = "<<a[0]<<" \t Max array = "<<a[n-1]; //  3
	double s = 0; // 1
	for(int i  =0 ;i<n;i++) //n+3 
		s+=x; // 2n
	cout<<endl<<"Tong cac phan tu trong mang = "<<s;
	if(a[0]<0)	// 2
		cout<<endl<<"Phan tu am dau tien trong mang"<<a[0]; //1 
	else
		cout<<"\nKhong ton tai phan tu am trong mang";
	// do phuc tap O(max(1 , n+3 , 2n , nlogn , 3 , 1 , n+3 , 2n , 2 , 1) ~ O(nlogn)
}
