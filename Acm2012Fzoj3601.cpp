#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    scanf("%d", &T);
    while(T--)
    {
        int n = 0, m = 0, q = 0;
        char *tmp = new char[21];
        scanf("%d %d %d", &n, &m, &q);
        string *ans = new string[q];
        int mancount = n + m;
        for (int i = 0; i < mancount;i++)
        {
            int count = 0;
            scanf("%s",tmp);
            scanf("%d", &count);
            for (int j = 0; j < count;j++)
            {
                scanf("%s", tmp);
            }
        }
        for (int i = 0; i < q;i++)
        {

        }
        delete tmp;
    } 
    return 0;
}
