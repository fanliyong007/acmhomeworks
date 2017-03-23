//dfs输入一个1-9的数字打印齐全排列
#include<iostream>
using namespace std;
int n=0;
int a[10],b[10];
void dfs(int step)//当前在第几个位置
{
    // int a[10],b[10];
    if(step==n+1)//前n个数字已经放好
    {
        for(int i=1;i<=n;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
        return;
    }//每次都从1-n逐步尝试
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)//这个数字是否用过
        {
            a[step]=i;//没用过，这个位置就放i
            b[i]=1;//标识i已经被用过，防止再用
            dfs(step+1);//放好这个数字后，下一个数字，展开是一个数
            b[i]=0;//回溯，当满足一种全排列后，下一个尝试
        }
    }
    return;
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}
