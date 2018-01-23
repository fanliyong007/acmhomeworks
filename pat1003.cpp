#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include <cmath>


int city = 0, road = 0, begin = 0, end = 0, teams=0,cnt=0;
long long shortist = LLONG_MAX;;
int cityroad[501][501];
int man[501];
bool book[501];

void dfs(int where,int tmp,int weight)
{
    if(where==end)
    {
        if(tmp>shortist)
            return;
        if(tmp<shortist)
        {
            cnt=1;
            teams=weight;
            shortist=tmp;
        }
        else
        {
            cnt++;
            if(teams<weight)
                teams=weight;
        }
        return;
    }
    if(tmp>shortist)
        return;
    for (int i = 0; i < city ;i++)
    {
        if(book[i]||cityroad[where][i]==-1)
            continue;
        book[i] = true;
        dfs(i, tmp+cityroad[where][i],weight+man[i]);
        book[i] = false;
    }
    
}

int main()
{
    while(scanf("%d%d%d%d", &city, &road, &begin, &end)!=EOF)
    {
        int cityone = 0, citytwo = 0;
        shortist = LLONG_MAX, teams = 0,cnt=0;
        memset(book, false, sizeof(book));
        memset(cityroad, -1, sizeof(cityroad));
        for (int j = 0; j < city; j++)
            scanf("%d", &man[j]);
        for (int j = 0; j < road; j++)
        {
            scanf("%d%d", &cityone, &citytwo);
            scanf("%d", &cityroad[cityone][citytwo]);
            cityroad[citytwo][cityone] = cityroad[cityone][citytwo];
        }     
        book[begin] = true;
        dfs(begin, 0,man[begin]);
        book[begin] = false;
        printf("%d %d\n", cnt, teams);
    }
    return 0;
}