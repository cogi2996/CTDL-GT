#include<bits/stdc++.h>
using namespace std;

void insert_value(int key ,int i,int a[],int n)
{
	int j ;
	for( j = i -1;j >=0;j--)
	{
		if(a[j]>key)
			a[j+1]  = a[j];
		else	
			break;
	}
	if(j != i -1 )
		a[j+1]  = key;
}

void insertion_sort_v2(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		insert_value(a[i],i,a,n);
	}
}

void xuat ( int a[],int n)
{
	for(int i = 0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	int a[]  ={5,4,1,2,6,4};
	int n = 6;
	insertion_sort_v2(a,n);
	xuat(a,n);
}
