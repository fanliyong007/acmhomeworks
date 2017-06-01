    
//19的迭代比较多所以单单深搜会超时，所以要减枝
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
int num;
int g=1;
int x[21];
int fss[]={0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1};
//做一个判断素数的数组
bool flag[21];
using namespace std;
bool ceshi()
{
    bool flag2=true;
    for(int i=2;i<=num;i++)
    {   
        int z=x[i-1]+x[i];
        if(fss[z]==1)
        {
            flag2=false;
            break;
        }
    }
    if(fss[(x[1]+x[num])]==1)
        flag2=false;
    return flag2;
}
void dfs(int k)
{
    if(ceshi()&&k==num+1)
    {
        for(int i=1;i<=num;i++)
        {
            if(i!=num)
                printf("%d ",x[i]);
            else
                printf("%d\n",x[i]);
        }
        return;
    }
    for(int i=2;i<=num;i++)
    {
        if(flag[i])
        {
            flag[i]=false;
            x[k]=i;
            if(fss[x[k]+x[k-1]]==0)//对超出范围的减枝即前后想加不是素数的
                dfs(k+1);
            flag[i]=true;
        }
    }
    return;
}
int main() 
{   
    while(scanf("%d",&num)!=EOF)
    {
        memset(x,0,sizeof(x));
        memset(flag,true,sizeof(flag));
        x[1]=1;
        printf("Case %d:\n",g);
        dfs(2);
        printf("\n");
        g++;
    }
    return 0;
}