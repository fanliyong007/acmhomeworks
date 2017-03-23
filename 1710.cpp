#include<iostream>
#include<cstring>
using namespace std;
int searchroot(int x,int LMR[])
{
    int n=strlen();
    for(int i=0;i<n;i++)
    {
        if(x==LMR[i])
        {
            x=searchroot(x,LMR);
            // break;
        }
        else if(i==(n-1)&&x!=LMR[i])
             return x;
    }
}
void find(int a[],int b[],int count)
{
    int root=a[0];
    int root=searchroot(root,b);
    

}
int main()
{
    int n=0;
    while(cin>>n)
    {
        int mlr[n];
        int lmr[n];
        for(int i=0;i<n;i++)
            cin>>mlr[i];
        for(int i=0;i<n;i++)
            cin>>lmr[i];
        find(mlr,lmr,n);
    }
    return 0;
}