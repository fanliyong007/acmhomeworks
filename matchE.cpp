#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        cout<<(int)pow(2,m)-1<<endl;
    }
    return 0;
}