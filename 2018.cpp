#include<iostream>
using namespace std;
int main()
{
    int n=0;
    while(true)
    {
        cin>>n;
        int a[n+1];
        if(n==0)
            break;
        for(int i=0;i<n+1;i++)
            a[i]=0;
        a[1]=1;
        a[2]=2;
        a[3]=3;
        a[4]=4;
        if(n<=4)
            cout<<a[n]<<endl;
        else
        {
            for(int i=5;i<=n;i++)
            {
                a[i]=a[i-1]+a[i-3];
            }
            cout<<a[n]<<endl;
        }
    }
    return 0;
}
