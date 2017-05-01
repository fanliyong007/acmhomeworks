#include<iostream>
using namespace std;
int main()
{
    int count;
    cin>>count;
    while(count--)
    {
        int n,m,sum=0,tmp=0;;
        cin>>n>>m;
        while(n--)
        {
            cin>>tmp;
            sum+=tmp;
        }  
        sum>m?cout<<"Warning"<<endl:cout<<"Safe"<<endl;
        sum=0;
    }
    return 0;
}
