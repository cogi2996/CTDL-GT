#include<bits/stdc++.h>
using namespace std;
int arr[100];

int symmetry(int right,int left){
	if(right>=left)
		return 1;
	if(arr[right]!=arr[left]){
		return 0;
	}
	return  symmetry(right+1,left-1);
}

int main()
{
	int n;cin>>n;
	for(int i= 0;i<n;i++)	
		cin>>arr[i];
	(symmetry(0,n-1)==1)?cout<<"doi xung": cout<<"khong doi xung";
}

