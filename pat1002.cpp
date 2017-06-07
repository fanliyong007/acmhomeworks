#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
bool flag[1008];
double num[1008];               
int main()
{
    int count=0;
    while(cin>>count)
    {
        int x;
        double y;
        memset(flag,false,sizeof(flag));
        memset(num,0,sizeof(num));
        for(int i=1;i<=count;i++)
        {
            cin>>x>>y;
            num[x]+=y;
            flag[x]=true;
        }
        x=0;y=0;
        int count=0;
        cin>>count;
        for(int i=1;i<=count;i++)
        {
            cin>>x>>y;
            num[x]+=y;
            flag[x]=true;
        }
        int g=0;
        for(int i=1002;i>=0;i--)
        {
            if(flag[i]&&num[i]!=0)
                g++;
        }
        printf("%d",g);
        g=0;
        for(int i=1002;i>=0;i--)
        {
            if(flag[i]&&num[i]!=0)
                printf(" %d %.1f",i,num[i]);
        } 
        cout<<endl;
    }
    return 0;
}
