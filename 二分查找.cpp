#include <iostream>
#include<algorithm>
using namespace std;
int search (int goal,int shuzu[],int wide)
{
    int left=0;
    int right=wide;
    int mid=(right+left)/2;
    while(true)
    {
        if(shuzu[mid]==goal)
        {
            return mid;
            break;
        }
        else if(shuzu[mid]>goal)
        {
            right=mid;
            mid=(left+right)/2;
        }
        else if(shuzu[mid]<goal)
        {
            left=mid;
            mid=(left+right)/2;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int foundnumber=0;
    cin>>foundnumber;
    sort(a,a+n);
    foundnumber=a[search(foundnumber,a,n)];
    cout<<foundnumber;
}
//标准版 
int BinarySearch(int a[],int size,int p)
{
    int L=0;
    int R=size-1;
    while(L<=R)
    {
        int mid=L+(R-L)/2;
        if(p==a[mid])
            return mid;
        else if(p>a[mid])
            L=mid+1;
        else 
            R=mid-1;
    }
    return -1; 
}
//查找比给定整数p小的，下标最大的元素
int LowerBound(int a[],int size,int p)
{
    int L=0;
    int R=size-1;
    int lastPos=-1;
    while(L<=R)
    {
        int mid=L+(R-L)/2;
        if(a[mid]>=p)
            R=mid-1;
        else
        {
            lasePos=mid;
            L=mid+1;
        }
    }
    return lastPos;
}
//STL版本，需要头文件#include<algorithm>
binary_search(数组名+n1,数组名+n2,值)//查找区间[n1,n2)内的值返回值为true（找到），false（没找到）

