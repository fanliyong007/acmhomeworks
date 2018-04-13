#include<bits/stdc++.h>
int arr[1008];
double ans[1008];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int man = 0, gold = 0, count=0;
        double sum = 0;
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        scanf("%d %d %d", &man, &gold, &count);
        for (int i = 0; i < man;i++)
            scanf("%d", &arr[i]);
        for (int i = 0; i < 100;i++)
        {
            for (int j = 0; j < man;j++)
            {
                ans[j] += gold * 1.0 / arr[j];
                sum += ans[j];
            }
            gold=
            sum = 0;
        }
    }
    return 0;
}