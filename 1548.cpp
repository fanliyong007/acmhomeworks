#include<bits/stdc++.h>
using namespace std;
int N=0,A = 0, B = 0;
bool arrive = false;
bool flag[208];
struct fl
{
    int now;
    int ki;
    int goUp;
    int goDown;
    int step;
}node[208];
void bfs()
{
    node[A].step = 0;
    queue<fl> que;
    que.push(node[A]);
    while(!que.empty())
    {
        struct fl tmp = que.front();
        que.pop();
        if(tmp.now==B)
        {
            arrive = true;
            break;
        }
        if(tmp.goUp!=-1&&flag[tmp.now]==false)
        {
            que.push(node[tmp.goUp]);
            node[tmp.goUp].step = (node[tmp.goUp].step)>=(node[tmp.now].step + 1)?(node[tmp.now].step + 1):(node[tmp.goUp].step);
        }
        if(tmp.goDown!=-1&&flag[tmp.now]==false)
        {
            que.push(node[tmp.goDown]);
            node[tmp.goDown].step = (node[tmp.goDown].step)>=(node[tmp.now].step + 1)?(node[tmp.now].step + 1):(node[tmp.goDown].step);
        }
        flag[tmp.now] = true;
    }
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        arrive = false;
        if(N==0)
            break;
        scanf("%d %d", &A, &B);
        for (int i = 1; i <= N;i++)
        {
            scanf("%d", &node[i].ki);
            flag[i] = false;
            node[i].now = i;
            node[i].step = 99999;
            if(node[i].now + node[i].ki>N)
            {
                node[i].goUp = -1;
            }
            else
            {
                node[i].goUp = node[i].now + node[i].ki;
            }
            if(node[i].now - node[i].ki<0)
            {
                node[i].goDown = -1;
            }
            else
            {
                node[i].goDown = node[i].now - node[i].ki;
            }
        }
        bfs();
        if(arrive)
        {
            printf("%d\n", node[B].step);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}