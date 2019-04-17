#include<bits/stdc++.h>
using namespace std;
stack<string>xml;
int main()
{
    string word;
    bool begin=false;
    int flag=0;
    while((flag=getchar())!=EOF)
    {
        if(flag=='<')
        {
            begin=true;
        }
        if(flag=='>')
        {
            begin=false;
        }
        if(begin)
        {
            word+=(char)flag;
        }
        
    }
    return 0;
}