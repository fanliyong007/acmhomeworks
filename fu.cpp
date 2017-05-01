#include<iostream>
#include<algorithm>
#include<cstring>
#include<memory.h>
short num[100010];
using namespace std;
int main()
{
    int count=0;
    int n=0;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>count;
        for(int i=0;i<count;i++)
        {
            cin>>num[i];
        }
        bool flag[count];
        int Max=-9999;
        int maxnum=0;
        int sum=0;
        int temp=0;
        memset(flag,true,sizeof(flag));
        while(true)
        {
           
            temp=maxnum;
            for(int i=0;i<count;i++)
            {
                if(num[i]>Max&&flag[i])
                {
                    Max=num[i];
                    maxnum=i;
                }
            }
            flag[maxnum]=false;
            if(maxnum<count-1)
                flag[maxnum+1]=false;
            if(maxnum>0)
                flag[maxnum-1]=false;
            if(temp==maxnum)
                break;
            else
            {
                sum+=Max;
                Max=-9999;
            }
        }
        cout<<sum<<endl;
        
    }
    return 0;
}