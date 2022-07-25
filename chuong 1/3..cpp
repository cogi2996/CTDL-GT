#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	do{
		if(a==0){
			cout<<"Hay nhap a > 0"<<endl;
			cin>>a;
		}
	}
	while(a==0);

	double denta =  b*b - 4*a*c;
		if(denta>=0)
		{
			double x1 , x2;
			x1 =  (-b + sqrt(denta))/(2*a);
			x2 =  (-b - sqrt(denta))/(2*a);
			if(denta > 0)
				cout<<"x1 = "<<x1<<"\t x2 = "<<x2;
			else
				cout<<"x1 = x2 = "<<x1;
		}
		else if(denta<0)
		{
			cout<<"Phuong trinh vo nghiem";
		}

	
}
