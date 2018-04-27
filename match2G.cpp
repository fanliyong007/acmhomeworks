#include<bits/stdc++.h>
using namespace std;
int id[100008];
int countx;
void UF(int N)
{
    countx = N;
    for (int i = 0; i < N;i++)
        id[i] = i;
}
int find(int p)
{
    while(p!=id[p])
        p = id[p];
    return p;
}
bool con(int p,int q)
{
    return find(p) == find(q);
}
void link(int p,int q)
{
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot==qRoot)
        return;
    id[pRoot] = qRoot;
    countx--;
}
int main()
{
    int t = 1;
    int N = 0, M = 0;
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        char op;
        int a = 0, b = 0;
        UF(N);
        printf("Case %d:\n", t);
        for (int i = 0; i < M;i++)
        {
            scanf("%c", &op);
            printf("%c", op);
            if(op=='M')
            {
                scanf("%d %d", &a, &b);
                link(a, b);
            }
            if(op=='Q')
            {
                scanf("%d", &a);
                int fri = 0;
                for (int i = 0; i <= N;i++)
                {
                    if(con(a,i))
                        fri++;
                }
                printf("%d\n", fri);
            }
        }
        printf("\n");
        t++;
    }
}