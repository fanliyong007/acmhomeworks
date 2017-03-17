//     周末
//     fly
// 三月春风又细雨;
// 我欲擼码到天明;
// 二友飞车嗨翻天;
// 唯有一人炮未归;
#include<iostream>
using namespace std;
void chuli(int t[])
{
    int up1=0,up2=0;
    int time[3];
    if((t[2]+t[5])>59)
    {
        up1=1;
        time[2]=t[2]+t[5]-60;
        if((t[1]+t[4]+1)>59)
        {
            up2=1;
            time[1]=t[1]+t[4]+up1-60;
            time[0]=t[0]+t[3]+up2;
        }
        else
        {
            time[1]=t[1]+t[4]+up1;
            time[0]=t[0]+t[3];
        }
    }
    else
    {
        time[2]=t[2]+t[5];
        if((t[1]+t[4])>59)
        {
            up2=1;
            time[1]=t[1]+t[4]-60;
            time[0]=t[0]+t[3]+up2;
        }
        else
        {
            time[1]=t[1]+t[4];
            time[0]=t[0]+t[3];
        }
    }
    for(int i=0;i<3;i++)
    {
        if(i!=2)
            cout<<time[i]<<" ";
        else
            cout<<time[i]<<endl;
    }

}
int main()
{
    int n=0;
    cin>>n;
    int time[n][6];
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<6;k++)
            cin>>time[i][k];
        chuli(time[i]);
    }
    return 0;
}
