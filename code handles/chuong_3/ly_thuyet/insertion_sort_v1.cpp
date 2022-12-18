#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n){
	// duyet tu k = a[1]
	for(int i =  1;i< n;i++)
	{
		int key = a[i];
		int k = -1;
		// tim tu a[0] -> key so nao dau tien lon hon key
		for(int j = 0;j<i;j++)
		{
			if(key<a[j])
			{
				k  = j;
				break;	
			}
		}	
		// neu ton tai vi tri chen duoc
		if(k!=-1){
			// day tu [i -1  --> k ] sang phai 1 don vi
			for(int j = i-1;j>=k;j--)
				a[j+1] = a[j];
				// chen k  vao cho con trong
			a[k]  = key;
		}
	}
}

void xuat(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<< " ";
	}
}

int main()
{
	int a[]  ={5,4,1,2,6,4};
	int n = 6;
	insertion_sort(a,n);
	xuat(a,n);
}
