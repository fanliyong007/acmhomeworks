#include<iostream>
#include<cstdio>
#include<string.h>   

int city=0,road=0,begin=0,end=0,tmp=0,shortist=999;       
int cityroad[500][500];
int man[500];
bool book[500][500];
bool flag=false;


void dfs(int start,int stop)
{
    if(stop==end&&cityroad[start][stop]!=-1)
    {
        tmp+=cityroad[start][stop];
        flag=true;
        return;
    }
    
    

}

int main()
{
    while(scanf("%d%d%d%d",&city,&road,&begin,&end)!=EOF)
    {
        int cityone=0,citytwo=0;
        shortist=999,tmp=0,flag=false;
        memset(cityroad,-1,sizeof(cityroad));
        memset(book,false,sizeof(book));
        for(int j=0;j<city;j++)
            scanf("%d",&man[j]);
        for(int j=0;j<road;j++)
        {
            scanf("%d%d",&cityone,&citytwo);
            scanf("%d",&cityroad[cityone][citytwo]);
        }
        for(int i=0;i<city&&i!=begin;i++)
        {
            dfs(begin, i);
            if(tmp<shortist&&flag)
                shortist=tmp;
        }
        
    }

    return 0;
}