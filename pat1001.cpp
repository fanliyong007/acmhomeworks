#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int sum=a+b;
        if(sum<=999&&sum>0||sum<=0&&sum>=-999)
            printf("%d\n",sum);
        else if(sum>999&sum<=999999||sum<-999&&sum>-999999)
        {
            if(sum>0)
            {
               printf("%d,%03d\n",sum/1000,sum%1000);
            }
            else
            {
                printf("%d,%03d\n",sum/1000,-sum%1000);
            }
        }
        else
        {
            if(sum>0)
                printf("%d,%03d,%03d\n",sum/1000000,sum/1000%1000,sum%1000);
            else
                printf("%d,%03d,%03d\n",sum/1000000,-sum/1000%1000,-sum%1000);    
        }
    }
    return 0;
}