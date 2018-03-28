#include<bits/stdc++.h>  
using namespace std;
struct talk
{
    int left;
    int right;
};
int main()
{
    int n = 0;//聊天的天数
    int m = 0;//友情值要求的天数
    int x = 0;//A给B发的信息条数
    int y = 0;//B给A发的信息条数
    int t = 0;//测试用例个数
    long long int sum = 0;//最后结果
    struct talk one[101];
    struct talk two[101];
    int maxl = 0;
    int minr = 0;
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        scanf("%d %d %d %d", &n, &m, &x, &y);
        for (int i = 0; i < x;i++)
            scanf("%d %d", &one[i].left, &one[i].right);
        for (int i = 0; i < y;i++)
            scanf("%d %d", &two[i].left, &two[i].right);
        for (int i = 0; i < x;i++)
            for (int j = 0; j < y;j++)
            {
                if(one[i].right>two[j].left)
                {
                    maxl = max(one[i].left,two[j].left);
                    minr = min(one[i].right, two[j].right);
                    if(minr-maxl+1>=m)
                        sum += minr - maxl - m + 2;
                }
            }
        printf("%lld\n", sum);
    }
    return 0;
}
