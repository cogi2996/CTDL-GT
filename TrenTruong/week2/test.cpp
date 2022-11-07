#include<bits/stdc++.h>
using namespace std;

void Nhap(int &N,int *a)
{
	cout<<"Nhap so luong phan tu cua mang";
    cin>>N;
	for(int i= 0;i<N;i++){
		cin>>a[i];
	}
}

int FindMax(int *a,int N,int start ,int end)
{   
    if(start-end ==0)
        return a[start];
    int max1 =  FindMax(a,N/2,0,N/2);
    int max2 = FindMax(a,N/2,N/2 + 1,N);
    if(max1>max2)
        return max1;
    return max2;
}

int main(){
	int N  =2;
    int a[29];
	Nhap(N,a);
    cout<<"Phan tu lon nhat cua mang:" << FindMax(a,N,0,N-1);
}