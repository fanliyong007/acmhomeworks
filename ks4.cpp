#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int gold[100009];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int count=1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&gold[i]);
            for(int j=0;j<i;j++)
            {
                if(gold[i]==gold[j])
                {
                    count++;
                }
            }
            
        }
        printf("%d\n",count);
    }
    return 0;
}