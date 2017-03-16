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
binary_search(数组名+n1,数组名+n2,值,排序规则结构名（）)//在使用自定义排序规则内的数组里二分查找
//在二分查找中等于的含义是“a必须在b前面“和”b必须在a前面“都不成立
//例子
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Rule//按个位数从小到大排序
{
    bool operator(const int & a1,const int & a2)
    {
        return a1%10<a2%10;
    }
};
void Print(int a[],int size)
{
    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<",";
    }
    cout<<endl;
}
int main()
{
    int a[] ={12,45,3,98,21,7};
    sort(a,a+6);
    cout<<"result"<<binary_search(a,a+6,12)<<endl;
    cout<<"result"<<binary_search(a,a+6,77)<<endl;
    sort(a,a+6,Rule());
    Print(a,6);
    cout<<"result"<<binary_search(a,a+6,7)<<endl;
    cout<<"result"<<binary_search(a,a+6,Rule())<<endl;
    return 0;
}
/*输出
3,7,12,21,45,98,
result:1
result:0
21,12,3,45,7,98,
result:0
result:1
*/
//用lower_bound二分查找下界（一）
T * lower_bound(数组名+n1,数组名+n2,值);
返回一个指针T*p；
*p是查找区间里下标最小的，大于等于“值”的元素。如果找不到，p指向下标为n2的元素
//用lower_bound二分查找下界（二）在元素为任意的T类型，按照自定义排序规则排好序的数组中进行查找
T * lower_bound(数组名+n1,数组名+n2,值，排序规则结构名);
返回一个指针T*p；
*p是查找区间里下标最小的，按自定义排序规则，可以排在“值”后面的元素。如果找不到，p指向下标为n2的元素
//用upper_bound二分查找上界（一）
在元素为任意的T类型从小到大排好序的数组中进行查找
T * upper_bound(数组名+n1,数组名+n2,值);
返回一个指针T*p；
*p是查找区间里下标最小的，大于“值”的元素。如果找不到，p指向下标为n2的元素
//用upper_bound二分查找下界（二）在元素为任意的T类型，按照自定义排序规则排好序的数组中进行查找
T * upper_bound(数组名+n1,数组名+n2,值，排序规则结构名);
返回一个指针T*p；
*p是查找区间里下标最小的，按自定义排序规则，必须排在“值”后面的元素。如果找不到，p指向下标为n2的元素
//例子
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Rule
{
    bool operator(){const int & a1,const int & a2}
    {
        return a1%10 < a2%10
    }
};
void Print(int a[], int size)
{
    for(int i=0;i<size;++i)
    {
        cout<<a[i]<<",";
    }
    cout<<endl;
}
#define NUM 7
int main()
{
    int a[NUM]={12,5,3,5,98,21,7};
    sort(a,a+NUM);
    Print(a,NUM);//=>3,5,5,7,12,21,98,
    int *p=lower_bound(a,a+NUM,5);
    cout<<*p<<","<<p-a<<endl;//=>5,1
    p=upper_bound(a,a+NUM,5);
    cout<<*p<<endl;//=>7
    cout<<*upper_bound(a,a+NUM,13)<<endl;//=>21
    sort(a,a+NUM,Rule());
    Print(a,Num);=>21,12,3,5,5,7,98,
    cout<<*lower_bound(a,a+NUM,16,Rule())<<endl;//=>7
    cout<<lower_bound(a,a+NUM,25,Rule())-a<<endl;//=>3
    cout<<upper_bound(a,a+NUM,18,Rule())-a<<endl;//=>7
    if(upper_bound(a,a+NUM,18,Rule()==a+NUM))
        cout<<"not found"<<endl;//=>not found
    cout<<*upper_bound(a,a+NUM,5,Rule())<<endl;//=>7
    cout<<*upper_bound(a,a+NUM,4,Rule())<<endl;//=>5
    return 0;
}

