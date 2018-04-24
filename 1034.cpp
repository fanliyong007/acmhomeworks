#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N = 0;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;
        int *arr = new int[N+1];
        bool x = true;
        int step = 0;
        for (int i = 0; i < N;i++)
        {
            scanf("%d", &arr[i]);
        }
        while(true)
        {
            step++;
            x = true;
            int tmpA = arr[N-1]/2;
            int tmpB = 0;
            for (int i = 0; i < N;i++)
            {
                tmpB = arr[i];
                arr[i] = arr[i] / 2 + tmpA;
                if(arr[i]%2!=0)
                    arr[i]++;
                tmpA = tmpB / 2;
            }
            for (int i = 0; i < N-1;i++)
            {
                if(arr[i]!=arr[i+1])
                {
                    x = false;
                    break;
                }
            }
            if(x)
                break;
        }
        printf("%d %d\n", step, arr[0]);
        delete arr;
    }
    return 0;
}