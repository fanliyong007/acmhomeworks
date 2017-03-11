#include <iostream>
using namespace std;
int a[1000001];
int main()
{
	int n,m,i,temp,num,max;
    while(cin>>n>>m)
	{
		memset(a,0,sizeof(a));//第二次输入时，不清空数组，前一次的值会存在
		temp=-1;
        max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);   //cin>>num;  用cin超时
			a[num+500000]=1;
            if(num>temp)
			{
				temp=num;
				max=temp+500000;
			}
		}
		while(m)
		{
			if(a[max]==1)
			{
				cout<<max-500000;
                m--;
				if(m==0) 
				{
					break;
				}
				else
					cout<<" ";
			}
		max--;
		}
		cout<<endl;
	}
	return 0;
}