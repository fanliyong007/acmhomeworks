#include<iostream>
using namespace std;
int num[10],flag[10],n;
void dfs(int step)
{
    if(step==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<num[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            num[step]=i;
            flag[i]=1;
            dfs(step+1);
            flag[i]=0;
        }
    }
    return;  
}
int main()
{
    cin>>n;
    dfs(1);
    cin.get();cin.get();
    return 0;
}
