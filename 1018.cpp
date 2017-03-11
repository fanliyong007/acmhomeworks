#include<iostream>
#include<cmath>
using namespace std;
int fun(const int b)
{
    double z=0;
    for(int k=1;k<=b;k++)
    {
        z+=log10(k);
    }
    int answer=(int)z++;
    return answer;
}
int main()
{
int n=0;
int a=0;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a;
    cout<<fun(a)<<endl;
}
return 0;
}