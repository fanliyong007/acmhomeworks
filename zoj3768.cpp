#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>
using namespace std;
int num[20000];
int BinarySearch(int a[],int size,int p)
{
    int L=1;
    int R=size-1;
    while(L<=R)
    {
        int mid=L+(R-L)/2;
        if(p==a[mid])
            return mid;
        else if(p>a[mid])
            L=mid+1;
        else 
            R=mid-1;
    }
    return -1; 
}
void fun(int minnum)
{
        int p=BinarySearch(num,19000,minnum);
        if(p!=-1)
        {
            cout<<p<<" "<<endl;
            minnum=0;
        }
        else
        {
            for(int i=1;num[i]<minnum;i++)
            {
                int x=BinarySearch(num,19000,minnum-num[i]);
                if(x!=-1)
                {
                    cout<<i<<" "<<x<<endl;
                    minnum=0;
                
                }
            }
        }
        if(minnum!=0)
        {
            for(int i=1;num[i]<minnum;i++)
            {
                for(int k=1;num[k]<minnum;k++)
                {
                    int y=BinarySearch(num,19000,minnum-num[i]-num[k]);
                    if(y!=-1)
                        {
                            cout<<i<<" "<<y<<" "<<k<<endl;
                            minnum=0;
                        }
                }

            }
            
        }   
    
}

int main()
{
    int count;
    for(int i=1;i<19000;i++)
    {
        num[i]=num[i-1];
        num[i]+=i;
    }
    cin>>count;
    while(count--)
    {
        int n;
        cin>>n;
        fun(n);
    }
    return 0;
}