#include<bits/stdc++.h>
#define ll long long
using namespace std;
int prime[108];
int countnum[108];
int n, m;
int g = 0;
int countx;
void initall()
{
    memset(prime, 0, sizeof(prime));
    memset(countnum, 0, sizeof(countnum));
    countx = 0;
    g = 0;
}
void dfs(int x,ll sum)
{
    if(x>=g)
    {
        countx++;
        return;
    }
    for (int i = 0; i <= countnum[x];i++)
    {
        if(i>0)
        {
            sum  *= prime[x];
        }
        if(sum>n)
            break;
        dfs(x + 1, sum);
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        initall();
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        int t = n;
        for (int i = 2; i*i <= n;i++)
        {
            if(t%i==0)
            {
                prime[g] = i;
                while(t%i==0)
                {
                    countnum[g]++;
                    t /= i;
                }
                countnum[g++] *= m;
            }
        }
        if(t>1)
        {
            prime[g] = t;
            countnum[g++] = m;
        }
        dfs(0,1);
        printf("%d\n", countx);
    }
    return 0;
}