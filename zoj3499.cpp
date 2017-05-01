#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstdio>
using namespace std;
int main()
{
    int count;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        int n=0;
        cin>>n;
        if(n==1)
        {
            double x;
            cin>>x;
            printf("%.3f\n",x);
        }
        else if(n==2)
        {
            double x1=0,x2=0;
            cin>>x1>>x2;
            printf("%.3f\n",(x1+x2)/2);
        }
        else if(n%2==0)
        {
            double a[n];
            double Max=-999;
            double Min=999;
            double sum=0;
            for(int j=0;j<n;j++)
            {
                cin>>a[j];
                sum+=a[j];
                if(a[j]>Max)
                    Max=a[j];
                if(a[j]<Min)
                    Min=a[j];
            }
            printf("%.3f\n",(sum-Max-Min)/(n-2));
            memset(a,0,sizeof(a));
            Max=-999;
            Min=999;
            sum=0;
        }
        else
        {
            double a[n];
            for(int j=0;j<n;j++)
                cin>>a[j];
            sort(a,a+n);
            printf("%.3f\n",a[n/2]);
        }
    }
    return 0;
}