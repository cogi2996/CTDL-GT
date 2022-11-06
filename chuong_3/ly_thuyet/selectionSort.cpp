#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int a[],int n)
{
	for(int i = 0;i<n-1;i++)
	{ 
		int minPos =  i;
		for(int j = i+1;j<n;j++)
			if(a[j]<a[minPos])
				minPos = j;
		if(i!=minPos)	
			swap(a[minPos] , a[i]);
	}
}

void xuat (int a[],int n)
{
	for(int i =0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	int a[] = {2,1,3,2,4,6,6};
	SelectionSort(a,7);
	xuat(a,7);
	
}
