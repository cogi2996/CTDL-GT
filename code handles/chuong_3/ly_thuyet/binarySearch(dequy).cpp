#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int min,int max,int x){
	if(min>max)
		return -1;
	else
	{
		int mid =  (min + max )/2;	
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			binarySearch(a,min,mid-1,x);
		else
			binarySearch(a,mid+1,max,x);
	}
}

int main(){
	int a[] = {1,2,45,123,4,6,3};
	sort(a,a+7);
	for(auto x:a)
		cout<<x<< " ";
	cout<<endl;
	cout<<binarySearch(a,0,6,3);
}
