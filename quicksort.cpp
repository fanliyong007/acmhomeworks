#include<iostream>
using namespace std;
void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
void quicksort(int num[],int left,int right)
{
    int temp=num[left];
    int i=left;
    int j=right;
    if(i>j)
        return;
    while(i!=j)
    {
        while(num[j]>=temp&&i<j)
            j--;
        while(num[i]<=temp&&i<j)
            i++;
        if(i<j)
            swap(num[i],num[j]);
    } 
    num[left]=num[i];
    num[i]=temp;
    quicksort(num,left,i-1);
    quicksort(num,i+1,right);
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