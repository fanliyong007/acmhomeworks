//主要使用深度搜索+栈，原理和0-9输出全排列一样要注意答案是字典序靠后的所以使用栈
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int num,len;
string word;
char danci[200];
bool flag[200];//数组要开大否则有些答案计算不出来
stack<string>stk;
int change(char x){int a=(int)x-64;return a;}
int cp()
{
    int  sum=0;
    for(int i=0;i<5;i++) 
    {
        if((i+1)%2==0)
            sum-=(int)pow((double)change(danci[i]),i+1);
        else
            sum+=(int)pow((double)change(danci[i]),i+1);
    }
    return sum;
}
void dfs(int x)//深度搜索
{
    if(cp()==num)
    {
        string tmp;
        for(int i=0;i<5;i++)
            tmp+=danci[i];
        if(stk.empty())
            stk.push(tmp);
        else
        {
           string tmp2=stk.top();
           if((int)tmp[0]>(int)tmp2[0])
           {
               stk.pop();//把字典序在前面的踢掉
               stk.push(tmp);
           }
            
        }
        return;
    }
    for(int i=0;i<len&&x<5;i++)
    { 
        if(flag[i])
        {
            danci[x]=word[i];
            flag[i]=false;
            dfs(x+1);
            flag[i]=true;
        }
    }    
    return;
}
int main()
{
    
    while(true)
    {
        for(int i=0;i<200;i++)
        {
            danci[i]='\0';
            flag[i]=true;
        }
        cin>>num>>word;
        if(num==0&&word=="END") 
        {
            break;
        }
        len=word.length();
        char tmp;
        dfs(0);
        if(stk.empty())
        {
            cout<<"no solution"<<endl;//判断栈中是否存在元素如果不存在则说明没有答案
        }
        else
        {
            cout<<stk.top()<<endl;
        }
        while(!stk.empty())
            stk.pop();
    }
    return 0;
}