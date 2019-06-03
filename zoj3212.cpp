#include<bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int flag=(n-2)*(m-2)-k;
        int tmp=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i<=n-1&&j<=m-1&&flag!=0&&j>1)
                {
                    printf("%d",tmp);
                    printf((j==m?"":" "));
                    tmp++;
                    flag--;
                }
                else
                {
                    printf("0");
                    printf((j==m?"":" "));
                }
            }
            printf("\n");
        }
    }
    return 0;
}