#include<bits/stdc++.h>
using namespace std;

int a[100];
int findmax(int A[],int N,int start,int end){
    if(start - end == 0)    return A[start];
    int max1 = findmax(A,N/2,0,N/2);
    int max2  = findmax(A,N/2,N/2+1,N);
    if(max1>max2) return max1;
    return max2;
}
// 2 

int main(){
	int N ;
    cout<<"Nhap so luong phan tu cua mang: "; 
    cin>>N;
	int *A  =new int[N];
    for(int i= 0;i<N;i++)     
        cin>>A[i];
    cout<<"Phan tu lon nhat cua mang:" << findmax(A,N,0,N-1);
	delete []A;	
}