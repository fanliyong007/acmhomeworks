#include<bits/stdc++.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    while(n--)
    {
        int num = 0, left = 0, right = 0, across = 0, upright = 0, tmp = 0;
        bool flag = true;
        scanf("%d %d %d %d", &across, &upright, &left, &right);
        if (left > right)
        {
            flag = false;
        }
        for (int i = 0; i < upright;i++)
        {
            for (int j = 0; j < across;j++)
            {
                scanf("%d", &tmp);
                if(flag)
                {
                    if(tmp<left||tmp>right)
                    {
                        num++;
                    }
                }
            }
        }
        if(flag)
        {
            printf("%d\n", num);
        }
        else
        {
            printf("No Solution\n");
        }
    }
}