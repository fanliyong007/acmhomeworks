#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int num,len;
string word;
char danci[6]={0};
bool flag[6];
int change(char x){int a=(int)x-64;return a;}
int cp()
{
    int  sum=0;
    for(int i=0;i<5&&danci[i]!='\0';i++) 
    {
        if(i%2==0)
            sum-=(int)pow((double)change(danci[i]),i+1);
        else
            sum+=(int)pow((double)change(danci[i]),i+1);
    }
    return sum;
}
void dfs(int x)
{
    if(cp()==num)
    {
        for(int i=0;i<5;i++)
            cout<<danci[i];
        cout<<endl;
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
        for(int i=0;i<5;i++)
        {
            danci[i]='\0';
            flag[i]=true;
        }
        cin>>num>>word;
        if(num==0&&word=="END") 
        {
            cout<<"no solution";
            break;
        }
        len=word.length();
        dfs(0);
    }
    return 0;
}