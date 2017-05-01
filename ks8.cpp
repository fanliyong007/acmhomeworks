#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <stack>
using namespace std;
long long prime[20000];
bool isbeishu[20000];
int mk()
{
    memset(isbeishu,false,sizeof(isbeishu));	
	int count=0;//当前有多少素数
		for(int i=2;i<=20000;i++)
		{
			if(isbeishu[i]==false)
			{
				prime[count]=i;
				count++;
			}
			
			for(int j=0;j<count && i*prime[j]<=100; j++)
			{
				isbeishu[i*prime[j]]=true;//当前素数的倍数标记上去
				if(i%prime[j]==0)
				{
					break;//如果i是素数的倍数那么就停止
				}
			}
		}
}
int main()
{
    mk();
    stack<int> stn;
    stack<int> stm;
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        stm.clear();
        int h=0;
        for(h;h<20000;h++)
        {
            if(!isbeishu[h])
            {
                while(1)
                {
                    if(m%prime[h]==0)
                    {
                        stm.push(prime[h]);
                        m=m/prime[h];
                    }
                    else if(m%prime[h]!=0)
                    {
                        break;
                    }
                }
            }
            if(m==1)
            {
                break;
            }
        }

        stn.clear();
        h=0;
        for(h;h<20000;h++)
        {
            if(!isbeishu[h])
            {
                while(1)
                {
                    if(n%prime[h]==0)
                    {
                        stn.push(prime[h]);
                        n=n/prime[h];
                    }
                    else if(m%prime[h]!=0)
                    {
                        break;
                    }
                }
            }
            if(n==1)
            {
                break;
            }
        }
        int si=stm.size();
        for(int i=0;i<si;i++)
        {
            if(stn.top()==stm.top())
            {
                stn.pop();
                stm.pop();
            }
            if(stn.top()>stm.top())
            {
                stn.pop();
            }
        }
        if(stm.empty())
        {
            cout<<"yes"<<endl;
        }
        else
            cout<<"gg"<<endl;
    }
    
    return 0;
}