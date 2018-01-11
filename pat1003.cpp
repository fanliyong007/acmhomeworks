#include<iostream>
#include<cstdio>
#include<string.h>

int city = 0, road = 0, begin = 0, end = 0, tmp = 0, shortist = 999,teams=0;
int cityroad[500][500];
int man[500];
bool book2[500];
bool book[500];
bool flag=false;

void dfs(int start,int stop)
{
    if(stop==end&&cityroad[start][stop]!=-1)
    {
        tmp+=cityroad[start][stop];
        flag = true;
        for (int i = 0; i < city;i++)
            if(book[i])
                book2[i]= true;
        return;
    }
    for (int i = 0; i < city ;i++)
    {
        if(book[i] == true||cityroad[stop][i]==-1||i==start)
            continue;
        book[i] = true;
        tmp += cityroad[stop][i];
        teams += man[stop];
        dfs(stop, i);
        teams -= man[stop];
        book[i] = false;
    }
}

int main()
{
    while(scanf("%d%d%d%d",&city,&road,&begin,&end)!=EOF)
    {
        int cityone=0,citytwo=0;
        shortist=999,teams=0;
        memset(book,false,sizeof(book));
        memset(book2,false,sizeof(book2));
        memset(cityroad,-1,sizeof(cityroad));
        for(int j=0;j<city;j++)
            scanf("%d",&man[j]);
        for(int j=0;j<road;j++)
        {
            scanf("%d%d",&cityone,&citytwo);
            scanf("%d",&cityroad[cityone][citytwo]);
        }
        teams += man[begin];
        teams += man[end];       
        for(int i=0;i<city;i++)
        {
            if(cityroad[begin][i]==-1)
                continue;
            tmp = 0;
            flag = false;
            book[i] = true;
            dfs(begin, i);
            if (tmp < shortist && flag)
            {
                shortist=tmp;
            }  
        }
        for (int i = 0; i < city; i++)
            if(book2[i]&&i!=begin&&i!=end)
                teams += man[i];
        printf("%d %d\n", shortist, teams);
    }
    return 0;
}