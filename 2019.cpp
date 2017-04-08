#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n=0,m=0;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            continue;
        int num[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
        }
        num[n]=m;
        sort(num,num+(n+1));
        for(int i=0;i<=n;i++)
        {
            if(i==n)
                cout<<num[i]<<endl;
            else
                cout<<num[i]<<" ";
        } 
    }
    return 0;
}