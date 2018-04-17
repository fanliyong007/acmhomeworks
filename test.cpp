#include<bits/stdc++.h>
inline int fun(int a)
{
    int sum = 1;
    for(int j=2;j<=sqrt(a);j++)
    {
        if(a%j==0)
        {
            sum+=j;
            if(a/j!=j)sum+=a/j;
        }
    }
    return sum;
}
int main()
{
    int n = 0;
    while(scanf("%d", &n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int a=0;
            scanf("%d", &a);
            if(a!=1)
            {
                int sum=fun(a);
                printf("%d\n", sum);
            }
            else printf("0\n");	
        }
    }
    return 0;
}

