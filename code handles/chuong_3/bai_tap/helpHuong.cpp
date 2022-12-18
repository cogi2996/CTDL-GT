#include<bits/stdc++.h>
using namespace std;
string inS;
int n, a[100];
int countAttack = 0, countDefense = 0;
string x = "attack",y = "defense";
int checkAttack(string ans,string checkStr)
{
	int i = ans.size();
	while(--i>=0)
	{
		if(ans[i]<='Z'&&ans[i]>='A')
			ans[i] = ans[i] + ' ';
	}
	i = 0;
	while((checkStr[i] == ans[i]|| checkStr[i] == (ans[i] - ' '))&&i<checkStr.size())
	{
		i++;
	}
	return i == checkStr.size();
}

int TRY(int k)
{
	if(k==n)
	{
		string ans;
		for(int i= 0;i<n;i++)
		{
			if(a[i]==1)
			{
				ans.push_back(inS[i]);
			}
		}
		
		if(ans.size()==x.size()&&checkAttack(ans,x)){
			countAttack++;
		}
		if(ans.size()==y.size()&&checkAttack(ans,y))
			countDefense++;
		
	}
	else
	{
		for(int i= 0;i<=1;i++)
		{
			a[k]  = i;
			TRY(k+1);
		}
	}
}

int main()
{
	getline(cin,inS);
	n = inS.size();
	TRY(0);
	cout<<countAttack<<" "<<countDefense;
	
}
