#include<iostream>
using namespace std;
int a[10],book[10],n;
void dfs(int step)
{
    int i;
    if(step==n+1)
    {
        for(int i=1;i<=n;i++)
            cout<<a[i];
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}
int main()
{
    while(true)
    {
        cin>>n;
        dfs(1);
        n=0;
    }
    return 0;
}