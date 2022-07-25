#include<bits/stdc++.h>
using namespace std;

void quick_sort(int a[],int left ,int right)
{
	// co mot gia tri
	if(left>=right) return;
	else if( left+1 == right) 
	{
		if(a[left]>a[right])
			swap(a[left],a[right]);
	}
	else
	{
		int pivot = a[right];
		int L = left - 1;
		for(int i = left ;i<right;i++)
		{
			if(a[i]<= pivot)
			{
				L++;
				swap(a[L],a[i]);
			}
		}
		swap(a[L+1],a[right]);
		quick_sort(a,left,L);
		quick_sort(a,L + 2,right);
	}			

}

void xuat(int a[],int n)
{
	for(int i = 0;i<n;i++)
		cout<<a[i]<<' ';
}
int main()
{
	int a[] = {4,2,56,6,2,8,1};
	int  n = 7;
	quick_sort(a,0,n-1);
	xuat(a,n);
}
