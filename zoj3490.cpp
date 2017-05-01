#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
char x[100000];
void fun(int y)
{
    if(!searchgo(x[y]))
    {
        x[y]=change(x[y]);
        fun(y-1);
    }
    else
    {
        x[y]=change(x[y]);
        cout<<x;
    }
    //  if(y==0)
    // {
    //             int k=strlen(x);
    //             for(int i=k;i>0;i--)
    //             {
    //                 x[i+1]=x[i];
    //             }
                
    // }
    // if(x[y]=='z'||x[y]=='Z'||x[y]=='9')
    // {
    //     if(x[y]=='z')
    //     {
    //         x[y]='a';
    //         int z=y-1;
    //         fun(z);
    //     }
    //     else if(x[y]=='Z')
    //     {
    //         x[y]='A';
    //         int z=y-1;
    //         fun(z);
    //     }
    //     else if(x[y]=='9')
    //     {
    //         x[y]='0';
    //         int z=y-1;
    //         fun(z);
    //     }
    // }
    // else
    // {         
    //     cout<<x<<endl;
    // }
}
int main()
{
    int count=0;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cin>>x;
        int cishu=0;
        cin>>cishu;
        int lt=strlen(x-1);
        for(int j=1;j<=cishu;j++)
            fun(lt);
    }
    return 0;
}