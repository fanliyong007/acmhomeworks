#include<iostream>
#include<stack>
#include<cstring>
#define max 100
using namespace  std;
void fan(char achar[],char bchar[],int cs)
{
    stack<char>stk;
    bool flag1[max];
    bool flag2=true;
    int x=0;
    int y=0;
    for(int l=0;l<cs*2;l++)
        flag1[l]=true;//初始化所有元素为进
    for(int i=0;i<cs;i++)
    {
        stk.push(achar[i]);//把元素压进来
        if(stk.top()==bchar[x]&&(i!=cs-1))//如果顶层元素与序列b的首位元素相同那么把它弹出去，并标记此元素为进出
        {
            stk.pop();
            x++;//此值用于标记进出元素位置
            y++;
            flag1[y]=false;
            y++;
        }
        else
        {
            y++;//否则就定位到下一个元素
        }
    }
    for(int j=x;j<cs;j++)
    {
        if(bchar[j]==stk.top())//如果现在顶层元素与序列b剩下的元素相同那么弹出并且标记出去
        {
            stk.pop();
            flag1[y]=false;
            y++;
        }
        else
        {
            flag2=false;
            break;
        }
    }
    if(flag2==false)
    {
        cout<<"No."<<endl;
    }
    else
    {
        cout<<"Yes."<<endl;
        for(int k=0;k<cs*2;k++)
        {
            if(flag1[k])
               cout<<"in"<<endl;
            else
                cout<<"out"<<endl;   
        }                   
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        char a[n];
        char b[n];
        cin>>a;
        cin>>b;
        fan(a,b,n);
        cout<<"FINISH"<<endl;
    }
    return 0;
}