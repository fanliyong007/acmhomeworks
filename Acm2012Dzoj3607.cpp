#include<bits/stdc++.h>
using namespace std;
struct customer
{
    double time;
    double price;
};
int main()
{
    struct customer cs[1008];
    int T = 0;
    int n = 0;
    int pi[1008];
    int ti[1008];
    int sum = 0;
    scanf("%d", &T);
    while(T--)
    {
        memset(pi, 0, sizeof(pi));
        memset(ti, 0, sizeof(ti));
        scanf("%d", &n);
        for (int i = 0; i < n;i++)
            scanf("%d", &pi[i]);
        for (int i = 0; i < n;i++)
            scanf("%d", &ti[i]);
        for (int i = 0; i < n;i++)
        {
            
        }

        printf("%.06lf %.06lf", );
    }
    return 0;
}