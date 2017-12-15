#include<iostream>
#include<cstring>
using namespace std;
bool isprime(int num)
{
    bool flag = true;
    for(int k=num-1;k>1;k--)
    {
        if(num%k==0)
        {
            flag=false;
            break;
        }
    }
     return flag;
}
int main()
{
    int x=0;
 
    while(cin>>x)
    {
         for(int i=2;i<=x;i++)
         {
             if((x%i==0)&&isprime(i))
             {
                x/=i;
                if(x!=1)
                    cout<<i<<"*";
                else
                    cout<<i;    
                i=1;
             }
         }
         cout<<endl;
    }
    return 0;
}