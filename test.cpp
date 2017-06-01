#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    bool flag[100];
    memset(flag,true,sizeof(flag));
    for(int i=2;i<=80;i++)
        {
            for(int j=i-1;j>1;j--)
                {
                    if(i%j==0)
                    {
                        flag[i]=false;
                        break;
                    }
                }
            if(flag[i]==false)
                cout<<"1,";
            else
                cout<<"0,";
        }
    cin.get(); cin.get();
    return 0;
    
}