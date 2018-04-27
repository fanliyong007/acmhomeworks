#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
#define LEN 1000005

int prime[MAX];//存储的都是素数，递增的
bool isp[MAX];//是否是素数的倍数，默认不是
bool isprime[LEN];
int countx=0;//用来计数当前找到第几个素数了，素数的总个数
void doprime()
{
	memset(isp,false,sizeof(isp));
	for(int i=2;i<MAX;i++)//从2到Max一个一个筛选
	{
		if(isp[i]==false)//如果i不是素数的倍数（是素数）
		{
			prime[countx]=i;//prime存储找到第count个素数
			countx++;
		}
		//针对当前的i，用已经找到的count个素数去做筛选
		for(int j=0;j<countx&& i*prime[j]<MAX;j++)
		{
			isp[i*prime[j]]=true;
			if(i%prime[j]==0)//如果i能整除这个素数就退出
			{
				break;
			}
		}
	}
}
void fun()
{
	memset(isprime,true,sizeof(isprime));
	for(int i=0;i<countx;i++)
	{
		for(int j=1;j<LEN;j++)
		{
			if(j>1&&j*prime[i]<LEN)
				isprime[j*prime[i]]=false;
            if(j*prime[i]>LEN)
                break;
        }
	}
}
int main()
{
    int n;
    doprime();
    fun();
    while(cin>>n)
    {
        if(n%2!=0)
        {
            cout << "No" << endl;
            continue;
        }
        if(isprime[n/2])
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}