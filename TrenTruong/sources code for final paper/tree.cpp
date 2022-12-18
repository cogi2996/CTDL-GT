#include<bits/stdc++.h>
using namespace std;

int main()
{
    /** LINKU[j], LINKR[j] for 0 <= j <= 2^r;  
   point upwards and to the right, respectively,  
   if j is a number in the tree  
**/ 

int LINKU[2050]={0},k=0,LINKR[2050]={0},q,s,nm,m,i,n;   
LINKR[0]=1;   
LINKR[1]=0;   
//11 being number of level   
while (k < 9)   
{   
    n=LINKR[0];m=0;   
    do 
    {   
        q=0,s=n;   
        do 
        {   
            if (LINKU[n+s]==0)   
            {   
                if (q==0)   
                   nm=n+s;   
                LINKR[n+s]=q;   
                LINKU[n+s]=n;   
                q=n+s;   
            }   
            s=LINKU[s];   
        }while (s!=0);   
        if (q!=0)   
        {   
            LINKR[m]=q;   
            m=nm;   
        }   
        n=LINKR[n];   
    }while (n!=0);   
    LINKR[m]=0;   
    k=k+1;   
}
    cout<<nm;
}