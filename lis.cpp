#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>
#include<string.h>
using namespace std;
int num[1008];
int maxlen[1008];
void fun(int x)
{
    for(int i=2;i<=x;i++)
        for(int j=i-1;j>0;j--)
        {
            if(num[i]>num[j])
            {
                maxlen[i]=max(maxlen[i],maxlen[j]+1); 
            }
        }
        cout<<*max_element(maxlen+1,maxlen+x+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        maxlen[i]=1;
    }
    fun(n);
    return 0;
}