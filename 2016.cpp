#include<iostream>
using namespace std;
void find(int num[],int count)
{
    int min=num[0];
    int swap=0,flag=0;
    for(int i=0;i<count;i++)
    {
        if(num[i]<min)
        {
            min=num[i];
            flag=i;
        }
    }
    swap=num[0];
    num[0]=num[flag];
    num[flag]=swap;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        find(a,n);
        for(int i=0;i<n;i++)
        {
        if(i!=n-1)
            cout<<a[i]<<" ";
        else
            cout<<a[i]<<endl;
        }
    }
    return 0;
}