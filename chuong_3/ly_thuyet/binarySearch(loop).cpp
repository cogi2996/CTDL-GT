#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int min,int max,int x)
{
	while(max>=min){
		int mid  = (max + min) /2;
		if(a[mid]  == x)
			return mid;
		if(a[mid]>x)
			max = mid -1;
		if(a[mid] <x)
			min = mid +1;
	}
	return -1;
}
int main(){
	int a[] = {1,2,45,123,4,6,3};
	sort(a,a+7);
	for(auto x:a)
		cout<<x<< " ";
	cout<<endl;
	cout<<binarySearch(a,0,6,3);
}
