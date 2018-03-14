#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    long long n,sum,t,i;
    sum=0;
    while(cin>>n)
    {
        long long sum=(((n%10000)*(n+1)%10000)/2)*(((n%10000)*(n+1)%10000)/2)%10000;
        printf("%04I64d\n",sum);
    }
}