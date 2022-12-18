#include<bits/stdc++.h>
using namespace std;

void InterchangeSort(int a[],int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}


void xuat (int a[],int n)
{
	for(int i= 0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	int a[] = {1,5,4,7,12,7,3};
	InterchangeSort(a,7);
	xuat(a,7);
	
}
