#include<iostream>
#include<cmath>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    freopen("hwss.txt","w",stdout);
    bool flag=true;
    stack<int>stk;
    queue<int>que;
    for(int i=0;i<100000000;i++)
    {
        for(int k=sqrt(i);k>0;k--)
        {
            if(i%k==0)
            {
                flag=false;
                break;
            }               
        }
        if(flag)
        {
            int copyone=i;
            int copytwo=i;
            while(copyone!=0&&copytwo!=0)
            {
                stk.push(copyone%10);
                copyone=copyone/10;
                que.push(copytwo%10);
                copytwo=copytwo/10;
            }
            while(!stk.empty())
            {
                if(stk.top()!=que.front())
                {
                    flag=false;
                    break;
                }
                stk.pop();
                que.pop();
            }
            while(!stk.empty())
            {
                stk.pop();
            }
            while(!que.empty())
            {
                que.pop();
            }
        }
        if(flag)
            cout<<i<<",";
        flag=true;
    }
    fclose(stdout);
    return 0;
}
