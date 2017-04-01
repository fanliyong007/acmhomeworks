#include<iostream>
using namespace std;
void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
void quicksort(int a[],int left,int right)
{
    
    int i,j,t,temp;
    if(left>right)
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        if(i<j)
            swap(a[i],a[j]);
    }
    a[left]=a[i];
    a[i]=temp;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
    return;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        quicksort(a,0,n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
    }
    return 0;
}
//有bug超简洁版(Jon Bently)
// void quicksort(int l,int u)
// {
//     int i,m;
//     if(i>=u)
//         return;
//     m=l;
//     for(i=l+1;i<=u;i++)
//         if(x[i]<x[l])
//             swap(++m,i);
//     swap(l,m);
//     quicksort(l,m-1);
//     quicksort(m+1,u);   
// }