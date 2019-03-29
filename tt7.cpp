#define debug
#include<bits/stdc++.h>
using namespace std;
int n, k, m;
double vis[10010];
 
int main()
{
    while(~scanf("%d%d%d", &n, &k, &m))
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i < n;i ++)
        {
            int a[100];
            for(int j = 0;j < k;j ++)
                scanf("%d", &a[j]);
            sort(a, a + k);
            double sum = 0;
            for(int j = 1;j < k - 1;j ++)
                sum += a[j];
            vis[i] = sum / ((k - 2) * 1.0);
        }
        sort(vis, vis + n);
        for(int i = n - m; i < n - 1;i ++)
            printf("%.3f ", vis[i]);
        printf("%.3f\n", vis[n - 1]);
    }
    #ifdef debug
        system("pause");
    #endif
    return 0;
}