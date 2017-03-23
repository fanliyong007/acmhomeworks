#include<iostream>
using namespace std;
void sum(int a)
{
    double x=0;
    for(int k=1;k<=a;k++)
    {               
        if(k%2==0)
        {
            x-=(double)1/k;
        }
        else
        {
            x+=(double)1/k;
        }
    }
    printf("%.2f\n",x);
}
int main()
{
    int m;
    cin>>m;
    int n[m];
    for(int i=0;i<m;i++)
    {
        cin>>n[i];
        sum(n[i]);
    }
    return 0;
}