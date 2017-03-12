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