#include<iostream>
#include<memory.h>
//ʹ��g++������������������<cstring>��<string.h> 
#include<algorithm>
#define Max 108
using namespace std;
int n=0;
int num[Max][Max];
int maxnum[Max][Max];
int maxsum(int x,int y)
{
    if(maxnum[x][y]!=-1)
        return maxnum[x][y];
    if(x==n)
    {
        maxnum[x][y]=num[x][y];
    }
    else
    {
        maxnum[x][y]=max(maxsum(x+1,y+1),maxsum(x+1,y))+num[x][y];
    }
    return maxnum[x][y];
}
int main()
{
   
        cin>>n;
        memset(maxnum,-1,sizeof(maxnum));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>num[i][j];
        cout<<maxsum(1,1)<<endl;
  
    return 0;
}
