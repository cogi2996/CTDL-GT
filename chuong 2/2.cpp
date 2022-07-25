#include<bits/stdc++.h>
using namespace std;
int arr[100];

int minArr(int n, int Min)
{
	if(n==1)
		return arr[0];
	int tempMin = minArr(n-1,Min);
	if(tempMin >= arr[n-1] )
		return arr[n-1];
	return tempMin;
}


int main()
{
	int n; cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int Min = arr[n-1];
	cout<<minArr(n,Min);
}
