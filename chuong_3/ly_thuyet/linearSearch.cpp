#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int x)
{
	for(int i = 0;i<7;i++)
		if(a[i]==x)
			return i;
	return -1;
}
int main(){
	int a[] = {1,2,45,123,4,6,3};
	cout<<linearSearch(a,45);
}
