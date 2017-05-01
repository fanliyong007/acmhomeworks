#include<iostream>
using namespace std;
int zhou(int x,int y)
{
    if(x==0&&y==0)
        return 0;
    else if(x==1&&y==1)
        return 1;
    else if(x==2&&y==0)
        return 2;
    else if(x==y)
    {
        return zhou(x,y-2)+2;
    }
    else if((x-2)==y)
    {
        return zhou(x-2,y)+2;
    }
    else 
        return -1;
}
int main()
{
    int count=0;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        int a=0,b=0;
        cin>>a>>b;
        int temp=0;
        temp=zhou(a,b);
        if(temp!=-1)
            cout<<temp<<endl;
        else
            cout<<"No Number"<<endl;
    }
    return 0;
}