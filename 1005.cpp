#include<iostream>
#include<cstdio>
using namespace std;
int num[108];
int main()
{
    int a,b,n;
    num[1]=1;num[2]=1;
    while(cin>>a>>b>>n)
    {
        if(a==0&&b==0)
            break;
        int flag=1;
        int zhi[4];
        num[3]=(num[2]*a+num[1]*b)%7;
        zhi[1]=num[3];
        num[4]=(num[3]*a+num[2]*b)%7;
        zhi[2]=num[4];
        num[5]=(num[4]*a+num[3]*b)%7;
        zhi[3]=num[5];
        //设置一把标尺存取前三个数字
        for(int i=6;i<=100;i++)
        {
            num[i]=(num[i-1]*a+num[i-2]*b)%7;
            if(num[i]==zhi[3]&&num[i-1]==zhi[2]&&num[i-2]==zhi[1])
            {
                flag=i-5;
                break;
                //当遇到与标尺相同的数字的时候说明整个数组开始重复了
            }
        }
        if(n<=flag+2)
            cout<<num[n]<<endl;
        else if(flag!=1)
            cout<<num[(n-2)%flag+2]<<endl;
        else
            cout<<num[(n-2)%flag+3]<<endl;
            //分三种情况讨论
    }
    return 0;
}
//该程序也许存在未知的bug但是杭电上能100%通过