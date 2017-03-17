#include<iostream>
#include<cstring>
using namespace std;
bool panduan(string a)
{
    bool x=true;
    const char* wenzi=a.c_str();
    int count=strlen(wenzi);
    for(int i=0,j=count-1;i<count,j>0;i++,j--)
    {
        if(wenzi[i]==wenzi[j])
            x=true;
        else
        {
            x=false;
            break;
        }
    }
    return x;
}
int main()
{
    int n;
    cin>>n;
    string word[n];
    bool flag[n];
    for(int i=0;i<n;i++)
        cin>>word[i];
    for(int i=0;i<n;i++)
        flag[i]=panduan(word[i]);
    for(int i=0;i<n;i++)
    {
        if(flag[i])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }    
    return 0;
}