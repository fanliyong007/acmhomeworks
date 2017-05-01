#include<iostream>
#include<string>
// #include<memory.h>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<cstdlib>
using namespace std;
string xname;
int x=0;
void fun(string man[])
{

}
int main()
{
    int count=0;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        string name[200];
        cin>>x;
        cin>>xname;
        for(int j=1;j<=x;j++)
            cin>>name[j];
        fun(name);
        for(int j=1;j<=x;j++)
            name[j]="0";
    }
    return 0;
}