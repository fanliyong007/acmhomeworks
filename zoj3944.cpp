#include<iostream>
#include<memory.h>
using namespace std;
char man[1000][1000];
int h,w;
bool check(int x,int y)
{
    if(x>=1&&y+1>=1&&x<=h&&y+1<=w&&man[x][y+1]=='O')return true;
    if(x+1>=1&&y+1>=1&&x+1<=h&&y+1<=w&&man[x+1][y+1]=='|')return true;
    if(x+1>=1&&y>=1&&x+1<=h&&y<=w&&man[x+1][y]=='/')return true;
    if(x+1>=1&&y+2>=1&&x+1<=h&&y+2<=w&&man[x+1][y+2]=='\\')return true;
    if(x+2>=1&&y>=1&&x+2<=h&&y<=w&&man[x+2][y]=='(')return true;
    if(x+2>=1&&y+2>=1&&x+2<=h&&y+2<=w&&man[x+2][y+2]==')')return true;
    return false;
}
int main()
{
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>h>>w;
        int sum=0;
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                cin>>man[i][j];
        for(int i=-1;i<=h;i++)
            for(int j=-1;j<=w;j++)
                if(check(i,j))
                    sum++;
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}