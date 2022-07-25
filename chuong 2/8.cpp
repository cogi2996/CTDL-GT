#include<bits/stdc++.h>
using namespace std;
int arr[15][15] = {0};
int nguoc[15] = {0},xuoi[15] = {0},cot[8] = {0},hang[8] ={0};
int res = 0;
void Try(int i)
{
	for(int j =1;j<=8;j++){
		if(!nguoc[i-j+8]&&!xuoi[i+j-1]&&!cot[j]&& !hang[i])
		{
			arr[i][j]= nguoc[i-j+8] = xuoi[i+j-1] = cot[j]=hang[i]=1;
			res++;
			if(res==7){
				for(int i1  = 1;i1<=8;i1++)
				{
						for(int j1  =1;j1<=8;j1++)
					{
						cout<<arr[i1][j1]<< " ";
					}
						cout<<endl;
				}
				exit(0);
			}
			else
				{
					Try(i+1);	
				}
				arr[i][j]= nguoc[i-j+8] = xuoi[i+j-1] = cot[j]=hang[i]=0;
				res--;
		
		}
	}
}
int main()
{
	Try(1);
}
