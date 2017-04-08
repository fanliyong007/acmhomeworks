#include<iostream>
//#include<algorithm>//swap
using namespace std;
// void swapint(int a,int b)
// {
//     int* tempa=0;
//     tempa=&a;
//     int* tempb=0;
//     tempb=&b;
//     (int *)a=tempb;
//     (int *)b=tempa;
// }
// void swap(int & __restrict a, int & __restrict b)  
// {  
//     a ^= b;  
//     b ^= a;  
//     a ^= b;  
// } 
void quicksort(int num[],int left,int right)
{
    int l=left;
    int r=right;
    int temp=num[l];
    int t=0;
    if(l>r)
        return;
    while(l!=r)
    {
        while(num[r]>=temp&&l<r)
            r--;
        while(num[l]<=temp&&l<r)
            l++;
        if(l<r)
        {
            //cout<<"num[r]:"<<num[r]<<" num[l]"<<num[l]<<endl;
            swap(num[r],num[l]);
            // t=num[r];
            // num[r]=num[l];
            // num[l]=t;
            //cout<<"num[r]:"<<num[r]<<" num[l]"<<num[l]<<endl;
        }
          
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