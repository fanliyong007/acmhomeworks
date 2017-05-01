#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a,b,c;
        cin>>a>>b>>c;
        double a1=(double)1/a;
        double b1=(double)1/b;
        double c1=(double)1/c;

        int i=1;
        while(true)
        {
            if(a==b&&b==c)
            {
                i=a;
                break;
            }
            if(i%a==0&&i%b==0&&i%c==0)
                break;
            i++;
        }
        double j=(double)i;
        double sum=j*(a1+b1+c1);
        if(n==(int)sum)
        {
            cout<<(int)sum-b-c<<(int)sum-a-c<<(int)sum-a-b<<endl;
        }    
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}