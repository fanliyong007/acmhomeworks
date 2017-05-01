#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int main(){

    double chang=297.0;
    double kuan=210.0;
    double hou=0.08;
    double c,k,h;

    c=chang;
    h=hou;
    k=kuan;
    int Count=0;
    while(k>h&&c>h)
    {
        c=c/2;
        h=h*2;
        Count++;
    }
    cout<<Count<<endl;

    Count=0;
    c=chang;
    h=hou;
    k=kuan;
    while(k>h&&c>h)
    {
        k=k/2;
        h=h*2;
        Count++;
    }
    cout<<Count<<endl;

    Count=0;
    c=chang;
    h=hou;
    k=kuan;
    while(k>h&&c>h)
    {
        if(k>=c)
        {
            k=k/2;
            h=h*2;
            Count++;
        }
        else
        {
            c=c/2;
            h=h*2;
            Count++;
        }
    }
    cout<<Count<<endl;

    Count=0;
    c=chang;
    h=hou;
    k=kuan;
    while(k>h&&c>h)
    {
        if(k<=c)
        {
            k=k/2;
            h=h*2;
            Count++;
        }
        else
        {
            c=c/2;
            h=h*2;
            Count++;
        }
    }
    cout<<Count<<endl;

    int a;
    cin>>a;
    return 0;
}