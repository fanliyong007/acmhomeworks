#include<bits/stdc++.h>
using namespace std;
struct bomb
{
    int dis;
    int btn[5];
}mybomb[5];
int main()
{
    int t=0;
    cin>>t;
    int dis[8];
    int btn[8][8];     
    while(t--)
    {
        for(int i=1;i<=5;i++)
        {
            cin>>mybomb[i].dis;
            for(int j=1;j<=4;j++)
            {
                cin>>mybomb[i].btn[j];
            }
        }
        for(int i=1;i<=5;i++)
        {
            if(mybomb[i].dis==1)
            {
                //好累啊不想模拟了
            }
        }
    }
    return 0;
}