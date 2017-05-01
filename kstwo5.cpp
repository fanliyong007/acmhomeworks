#include <iostream>
#include<cstdlib>
#include<cstring>
#include <cstdio>
#include <memory.h>
#include<algorithm>
#include<stack>
using namespace std;
bool cp(char a,char b)
{
    if(a=='('&&b==')')
        return true;
    else if(a=='['&&b==']')
        return true;
    else 
        return false;
}
int main()
{
    string word;
    while(cin>>word)
    {
        stack<char>stk;
        const char*wd=word.c_str();
        int len=strlen(wd);
        stk.push(wd[0]);
        while(!stk.empty()) 
        {

        }
       


    }
}