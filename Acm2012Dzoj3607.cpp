#include<bits/stdc++.h>
using namespace std;
struct customer
{
    double time;
    double price;
};
int main()
{
    struct customer cs;
    struct customer tmp;
    int T = 0;
    int n = 0;
    int pi[1008];
    int ti[1008];
    int sum = 0;
    scanf("%d", &T);
    while(T--)
    {
        sum = 0;
        tmp.time = -1;
        cs.price = -1;
        memset(pi, 0, sizeof(pi));
        memset(ti, 0, sizeof(ti));
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            scanf("%d", &pi[i]);
        for (int i = 1; i <= n;i++)
            scanf("%d", &ti[i]);
        ti[0] = 0;
        for (int i = 1; i <= n;i++)
        {
            sum += pi[i];
            tmp.price = (double)sum / (double)i;
            if(tmp.time<ti[i]-ti[i-1])
            {
                tmp.time = ti[i] - ti[i - 1];
            }
            if(i==n)
            {
                if(tmp.price>cs.price)
                {
                    cs = tmp;
                }
                continue;
            }
            if(tmp.time<ti[i+1]-ti[i]&&tmp.price>cs.price)
            {
                cs = tmp;
            }
        }
        printf("%.06lf %.06lf\n",cs.time,cs.price);
    }
    return 0;
}