#include <iostream>
using namespace std;
double quoit(int a[],int b[],int f)
{
    
}
int main()
{
    int n;
    while(cin>>n!=0)
    {   
        int x[n];
        int y[n];
        for(int i=0;i<n;i++)
         cin>>x[i]>>y[i];
        printf("%.2f\n",quoit(x,y,n));
    }
    return 0;
}