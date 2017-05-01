#include <iostream>
#include <cstdio>
#include <memory.h>
#include<algorithm>
using namespace std;
int nummax(int x)
{
    return x%10>x/10?x%10:x/10;
}
int nummin(int x)
{
    return x%10>x/10?x/10:x%10;
}
int compare(const void*a,const void*b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    if(nummax(x)>nummax(y))
    {   
        return -1;
    }
    else if(nummax(x)==nummax(y))
    {
        if(nummin(x)>nummin(y))
            return -1;
        else
            return 1;
   }
   else
        return 1;
}
int main()
{
    int num[100];
    for(int i=1;i<=25;i++)
        {
            cin>>num[i];
        }
    qsort(num,26,sizeof(int),compare);
    for(int i=25;i>=1;i--)
    {
        if(num[i]<10)
            cout<<"0"<<num[i]<<" ";
        else
            cout<<num[i]<<" ";
    }
    cin.get();cin.get();
    return 0;
}