//注意元素5 12342 24321
#include<iostream>
#include<stack>
#define max 100
using namespace std;
void fan(char achar[],char bchar[],int cs)
{
    int flag[max];
    for(int j=0;j<cs*2;j++)
        flag[j]=true;
    int x=0,y=0,z=0;
    stack<char>stk;
    while(x<=cs)
    {
        if(stk.empty())//第一次是空栈所以压入
        {
            stk.push(achar[x]);
            x++;z++;
        }
        if(!stk.empty()&&stk.top()==bchar[y])//如果最顶上元素等于bchar[y]的元素
        {
            stk.pop();
            flag[z]=false;
            y++;z++;
        }
        if(!stk.empty()&&stk.top()!=bchar[y])
        {
            stk.push(achar[x]);
            x++;z++;
        }   
    }
    if(stk.empty())
    {
        cout<<"Yes."<<endl;
        for(int i=0;i<cs*2;i++)
        {
            if(flag[i])
                cout<<"in"<<endl;
            else
                cout<<"out"<<endl;
        }
    }
    else
        cout<<"No."<<endl;
}
int main()
{
    int n=0;
    while(cin>>n)
    {
        char a[n];
        char b[n];
        cin>>a>>b;
        fan(a,b,n);
        cout<<"FINISH"<<endl;
    }
}