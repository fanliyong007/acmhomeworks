#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
bool flag[50008];
int n=0;
struct ck
{
    int x;
    int y;
    int count=0;
};
void chuli(ck x[])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&x[j].x>=x[i].x&&x[j].x<=x[i].y)
                x[i].count++;
            if(i!=j&&x[j].y>=x[i].x&&x[j].y<=x[i].y)
                x[i].count++;
        }
    }
    int countmax;
    while(true)adsf
    {
        countmax=-999;
        for(int i=1;i<=n;i++)
            if(x[i].count>countmax&&(!flag[i]))
            {
                countmax=x[i].count;
                //cout<<"countmax"<<countmax<<endl;
            }
        if(countmax<=3)
            break;
        for(int k=1;k<=n;k++)
            if(x[k].count==countmax)
            {
               // cout<<"one"<<endl;
                flag[k]=true;
                for(int l=1;l<=n;l++)
                    x[l].count=0;
                for(int i=1;i<=n;i++)
                    {
                        //cout<<"two"<<endl;
                    for(int j=1;j<=n;j++)
                        {
                            //cout<<"three"<<endl;
                            if(!flag[i]&&!flag[j])
                            {
                                if(i!=j&&x[j].x>=x[i].x&&x[j].x<=x[i].y)
                                    x[i].count++;
                                if(i!=j&&x[j].y>=x[i].x&&x[j].y<=x[i].y)
                                    x[i].count++;
                            }
                        }
                    }
            }
    for(int i=1;i<=n;i++)
    {
        cout<<"x[i].x="<<x[i].x<<" x[i].y="<<x[i].y<<" x[i].count="<<x[i].count<<endl;
    }
             cout<<"end"<<endl; 
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(flag,false,sizeof(flag));
        scanf("%d",&n);
        ck num[n+1];
        for(int i=1;i<=n;i++)
            scanf("%d%d",&num[i].x,&num[i].y);
        chuli(num);
        int cishu[50000];
        int cs=0;
        for(int i=1;i<=n;i++)
            if(flag[i])
            {
                cishu[cs]=i;
                cs++;
            }
        printf("%d\n",cs);
        for(int i=0;i<=n;i++)
            if(cishu[i]!=0)
                printf("%d ",cishu[i]);
        printf("\b\n");

    }
    cin.get();cin.get();
    return 0;
}