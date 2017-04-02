#include<iostream>
using namespace std;
void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}
void quicksort(int num[],int left,int right)
{
    int l=left;
    int r=right;
    int temp=num[l];
    if(l>r)
        return;
    while(l!=r)
    {
        while(num[r]>=temp&&l<r)
            r--;
        while(num[l]<=temp&&l<r)
            l++;
        if(l<r)
            swap(num[l],num[r]);
    }
    num[left]=num[l];
    num[l]=temp;
    quicksort(num,left,l-1);
    quicksort(num,l+1,right);
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
        quicksort(a,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
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