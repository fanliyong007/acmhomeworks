#include<stdio.h>
#include<cstring>
#define MAX 50000
#define LEN 1100005

int l,r;
int prime[MAX];//存储的都是素数，递增的
bool isp[MAX];//是否是素数的倍数，默认不是
bool isprime[LEN];
int count=0;//用来计数当前找到第几个素数了，素数的总个数
void doprime()
{
	memset(isp,false,sizeof(isp));
	for(int i=2;i<MAX;i++)//从2到Max一个一个筛选
	{
		if(isp[i]==false)//如果i不是素数的倍数（是素数）
		{
			prime[count]=i;//prime存储找到第count个素数
			count++;
		}
		//针对当前的i，用已经找到的count个素数去做筛选
		for(int j=0;j<count&& i*prime[j]<MAX;j++)
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
	memset(isprime,false,sizeof(isprime));
	for(int i=0;i<count;i++)
	{
		int low=(l-1)/prime[i]+1;
		int high=r/prime[i];
		for(int j=low;j<=high;j++)
		{
			if(j>1)
				isprime[j*prime[i]-l]=true;
		}
	}
}
int main()
{			
	doprime();
	while(scanf("%d %d",&l,&r)!=EOF)
	{
		int pmax=-1;//最大间隔 
		int pmin=999999999;//最小间隔 
		int minl=0;//最小间隔右值 
		int minr=0;//最大间隔右值
		int flag = -1;
		if(l==1)
			l=2;
		fun();
		//for(ll i=0;i<l+100;i++)
		//	prllf("isprime[%d]=%d\n",i,isprime[i]);
		for(int i=0;i<=r-l;i++)
		{
			if(!isprime[i])
			{
				if(flag!=-1)
				{
					int x = i - flag;
					if(x>pmax)
					{
						pmax = x;
						minr = i + l;
					}
					if (x < pmin)
					{
						pmin = x;
						minl = i + l;
					}
					flag = -1;
				}
				if(i+l!=1)
					flag = i;
			}
		}
		if(pmax==-1||pmin==999999999)
			printf("There are no adjacent primes.\n");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n",minl-pmin,minl,minr-pmax,minr);
		
	}
	return 0;
}