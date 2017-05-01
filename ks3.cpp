#include <iostream>
#include <cstdio>
#include<cstring>
#include <memory.h>
using namespace std;
bool two(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%2;
        x/=2;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool three(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%3;
        x/=3;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool four(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%4;
        x/=4;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool five(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%5;
        x/=5;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool six(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%6;
        x/=6;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool seven(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%7;
        x/=7;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool eight(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%8;
        x/=8;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool nine(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%9;
        x/=9;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
bool ten(int x)
{
    bool flag=true;
    int num[30];
    int g=0;
    int z=0;
    while(x)
    {
        z=x%10;
        x/=10;
        num[g]=z;
        g++;
    }
    
    if(num[0]==0)
    {
        for(int i=1,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=0,j=g-1;i<=j;i++,j--)
        {
            if(num[i]!=num[j])
            {
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}
int main()
{
    bool biaoji[10010];
    int s=0,n=0;
    memset(biaoji,false,sizeof(biaoji));
    for(int i=0;i<10010;i++)
    {
        if(three(i)||two(i)||four(i)||five(i)||six(i)||seven(i)||eight(i)||nine(i)||ten(i))
        {
            biaoji[i]=true;
        }
    }
    while(cin>>n>>s)
    {
        for(int i=s+1;i<=s+n;i++)
        {
            if(biaoji[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
}
