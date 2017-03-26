//bfs输入一个1-9的数字打印齐全排列
#include<iostream>
#include<queue>
#include<string>
#include <sstream>
using namespace std;
queue<string>que;
bool cmpstr(string a,char b)
{
    int count=a.length();
    bool flag=false;
    for(int i=0;i<count;i++)
    {
        if(a[i]==b)
        {
            flag=true;
            break;
        }
        else
        {
            flag=false;
        }
    }
    return flag;
}
string inttostring(int a)
{
    stringstream ss;
    string x="";
    ss<<a;
    ss>>x;//把int转string
    return x;
}
void bfs(int n)
{
    string qhead="";
    int s=0;
    string u="";
    for(int i=1;i<=n;i++)
    {
        que.push(inttostring(i));
    }
    while(!que.empty())
    {
        qhead=que.front();
        que.pop();
        for(int i=1;i<=n;i++)
        {
            if(cmpstr(qhead,inttostring(i)))
            {
                continue;
            }
            u=qhead+inttostring(i);
        }
        if(u.length()==n)
        {
            cout<<u<<endl;
            s++;
        }
        else
        {
            que.push(u);
        }
    }
    cout<<"共生产："<<s<<endl;
}
int main()
{
    int n=0;
    cin>>n;
    bfs(n);
    return 0;
}
