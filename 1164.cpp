#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int x=0;
    bool prime[10000];
    memset(prime,true,sizeof(prime));
    for(int i=3;i<10000;i++)
    {
        for(int k=i-1;k>1;k--)
        {
            if(i%k==0)
            {
                prime[i]=false;
                break;
            }
        }
    }
    while(cin>>x)
    {
         for(int i=2;i<=x;i++)
         {
             if((x%i==0)&&prime[i])
             {
                x/=i;
                if(x!=1)
                    cout<<i<<"*";
                else
                    cout<<i;    
                i=2;
             }
         }
         cout<<endl;
    }
    return 0;
}