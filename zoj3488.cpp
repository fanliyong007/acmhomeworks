#include<iostream>
using namespace std;
void fun(double a[])
{
    if(a[0]==a[2]&&a[1]==0&&(a[3]*a[3]+a[4]*a[4]-4*a[0]*a[5]>0))
        cout<<"circle"<<endl;
    else if(a[1]*a[1]==4*a[0]*a[2])
        cout<<"parabola"<<endl;
    else if(a[1]*a[1]>4*a[0]*a[2])
        cout<<"hyperbola"<<endl;
    else
        cout<<"ellipse"<<endl;
}
int main()
{
    int count=0;
    double num[6];
    cin>>count;
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<6;j++)
            cin>>num[j];
        fun(num);
    }
    return 0;
}