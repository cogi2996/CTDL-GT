#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {6,7,8,9};
	for(int x:{1,2,3,4,5}) 
		cout<<x<<" ";
	cout<<endl;
	int s = 0;
	for(int x:a){
		cout<<x<<" ";
	}
	cout<<endl;
	// co the thay int tren thanh auto
	for(auto x: a){
		cout<<x<<" ";
	}
}
