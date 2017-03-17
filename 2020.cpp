#include<iostream>
#include<algorithm>
using namespace std;
int  compare(const void *a,const void *b)
{
    if(*(int*)a<0&&*(int*)b>=0)
    {
        int x=-*(int*)a;
        if(x>*(int*)b)
            return *(int*)a>*(int*)b;
        else
            return *(int*)b>*(int*)a;
    }
    else if(*(int*)b<0&&*(int*)a>=0)
    {
        int x=-*(int*)b;
        if(x>*(int*)a)
            return *(int*)b>*(int*)a;
        else
            return *(int*)a>*(int*)b;
    }
    else if(*(int*)b<0&&*(int*)a<0)
    {
        int x=*(int*)b;
        int y=*(int*)a;
        if(x>y)
            return *(int*)b-*(int*)a;
        else
             return *(int*)a-*(int*)b;
    }
    else
        return *(int*)b-*(int*)a;
}
int main()
{
    int n=0;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        qsort(a,n,sizeof(int),compare);
        for(int j=0;j<n;j++)
        {
            if(j!=n-1)
                cout<<a[j]<<" ";
            else
                cout<<a[j]<<endl;
        }
    }
    return 0;
}