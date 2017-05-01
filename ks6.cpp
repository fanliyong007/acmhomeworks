#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include<cstring>
#include<stack>
using namespace std;
void fun(int x[])
{
    stack<int>stk;
    int num2[5];
    memset(num2,0,sizeof(num2));
    for(int i=1;i<=4;i++)
    {
        if(x[i]!=0)
            stk.push(x[i]);
    }
    if(!stk.empty())
    {
        num2[4]=stk.top();
        stk.pop();
    }
    int g=4;
    while(!stk.empty())
    {
        if(stk.top()==num2[g])
        {
            num2[g]+=stk.top();
            stk.pop();
            if(!stk.empty())
            {
                g--;
                num2[g]=stk.top();
                stk.pop();
            }
        }
        else
        {
            g--;
            num2[g]=stk.top();
            stk.pop();
        }
    }
    for(int i=1;i<=4;i++)
        cout<<num2[i]<<" ";
    cout<<endl;


}
int main()
{
    int num[5];
    while(true)
    {
        for(int i=1;i<=4;i++)
            cin>>num[i];
        // if(num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0)
        //     cout<<"0 "<<"0 "<<"0 "<<"0"<<endl;
        // else
            fun(num);
    }
    return 0;
}