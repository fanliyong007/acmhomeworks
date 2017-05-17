#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int num,sum,len;
string word;
char danci[6];
bool flag[6];
int change(char x)
{
    int a=(int)x-64;
    return a; 
}
long cp(char x[])
{
    long  sum=1;
    
    return sum;
}
void dfs(int x)
{
    if(cp(danci)==num)
    {
        cout<<danci<<endl;
    }
    else 
    {
        for(int i=1;i<len&&x<=5;i++)
        { 
            if(flag[i])
            {
                flag[i]=false;
                danci[x]=word[i];
                dfs(x+1);
                flag[i]=true;
            }  
        } 
    }
}
int main()
{
    
    while(true)
    {
        cin>>num>>word;
        if(num==0&&word=="END") 
        {
            cout<<"no solution";
            break;
        }
        len=word.length();
        dfs(1);
        for(int i=0;i<=5;i++)
        {
            danci[i]='\0';
            flag[i]=true;
        }
        sum=0;
    }
    return 0;
}