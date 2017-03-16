#include<iostream>
using namespace std;
void fan(int m,int n)
{
    int ji=0,ou=0;
    for(m;m<=n;m++)
    {
        if(m%2==0)
            ou+=m*m;
        else
            ji+=m*m*m;
    }
    cout<<ou<<" "<<ji<<endl;
}
int main()
{
    int x=0,y=0,swap=0;
    while(cin>>x>>y)
    {
        if(x>y)
        {
            swap=x;
            x=y;
            y=swap;
        }
        fan(x,y);
    }
    return 0;
}