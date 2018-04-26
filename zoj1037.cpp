#include<bits/stdc++.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t;i++)
    {
        int m = 0, n = 0;
        scanf("%d %d", &m, &n);
        printf("Scenario #%d:\n", i);
        printf("%d.", m * n);
        if(m%2&&n%2)
            printf("41");
        else
        {
            printf("00");
        }
        printf("\n\n");
    }
    return 0;
}