#define debug
#define LOCAL
#include<bits/stdc++.h>
using namespace std;
set<int> st[58];
void cal(const int a,const int b)
{
    int tmp=st[a].size();
    #ifdef debug
        printf("a=%d b=%d\n",a, b);
    #endif
    for (set<int>::iterator i = st[b].begin(); i != st[b].end();i++)
    {
        if(st[a].count(*i)==0)
        {
            tmp++;
        }
    }
    double nc = st[a].size() + st[b].size() - tmp;
    double nt = tmp;
    #ifdef debug
        printf("tmpa=%d tmpb=%d tmp=%d\n", st[a].size(), st[b].size(),tmp);
        printf("nc=%lf nt=%lf\n", nc, nt);
    #endif
    printf("%.2lf\%\n",nc/nt*100);
}
int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            st[i].insert(tmp);
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        cal(a-1,b-1);
    }
    #ifdef LOCAL
    system("pause");
    #endif
    return 0;
}