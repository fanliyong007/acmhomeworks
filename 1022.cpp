#include<iostream>
#include<stack>
#include<cstring>
using namespace  std;
void fan(string a,string b,int cs)
{
    stack<char>stk;
    const char*achar=a.c_str();
    const char*bchar=b.c_str();
    bool flag1[cs]={true};
    bool flag3[cs]={true};
    bool flag2=true;
    int x=0;
    for(int i=0;i<cs;i++)
    {
        stk.push(achar[i]);
        if(stk.top()==bchar[x])
        {
            stk.pop();
            flag1[i]=false;
            flag3[i]=true;
            x++;
        }
    }
    for(int j=x;j<cs;j++)
    {
        if(stk.top()==bchar[j])
        {
            stk.pop();
            flag1[j]=true;
            flag3[j]=false;
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
        for(int k=0;k<cs;k++)
        {
            if(flag1[k])
                cout<<"in"<<endl;
            else
                cout<<"out"<<endl;
        }    
        for(int l=0;l<cs;l++)
        {
            if(flag3[l])
                cout<<"in"<<endl;
            else
                cout<<"out"<<endl;
        }    
    }
}
int main()
{
    int n;
    string astring;
    string bstring;
    while(cin>>n)
    {
        cin>>astring;
        cin>>bstring;
        fan(astring,bstring,n);
        cout<<"FINISH"<<endl;
    }
    return 0;
}