#include<stdio.h>
#define size 100008
int main()
{
    int T = 0;
    while(scanf("%d",&T)!=EOF)
    {
        for (int j = 1; j <= T;j++)
        {
            int N = 0;
            scanf("%d", &N);
            int digital[size];
            int pos = 1, pos1 = 1, pos2 = 1;
            long long max = -999999, sum = 0;
            for (int i = 1; i <= N; i++)
            {
                scanf("%d", &digital[i]);
                sum += digital[i];
                if(sum>max)
                {
                    max = sum;
                    pos1 = pos;
                    pos2 = i;
                }
                if(sum<0)
                {
                    pos = i + 1;
                    sum = 0;
                }
            }
            printf("Case %d:\n", j);
            printf("%lld %d %d\n",max,pos1,pos2);
            if(j!=T)
                printf("\n");
        }
    }
    return 0;
}