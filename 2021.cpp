#include<iostream>
using namespace std;
int zhexian(int x)
{
    int count=0;
    while(x!=0)
    {
        if(x>=100)
        {
            count++;
            x-=100;
        }
        else if(x<100&&x>=50)
        {
            count++;
            x-=50;
        }
        else if(x<50&&x>=10)
        {
            count++;
            x-=10;
        }
        else if(x<10&&x>=5)
        {
            count++;
            x-=5;
        }
        else if(x<5&&x>=2)
        {
            count++;
            x-=2;
        }
        else
        {
            count++;
            x-=1;
        }
    }
    return count;
}
int main()
{
    int n=0;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        int sum=0;
        int money[n];
        for(int i=0;i<n;i++)
        {
            cin>>money[i];
            money[i]=zhexian(money[i]);
        }
        for(int i=0;i<n;i++)
        {
            sum+=money[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}