#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    cout<<sort(a,a+sizeof(a));//普通排序格式为sort(数组名+要排序的下标，数组名+要结束的下标，排序规则)排序规则为空则是从小到大
    cout<<sort(a,a+sizeof(a),greater<int>());//倒叙排序
    //排序规则定制
    sort(数组+n1,数组+n2，排序规则结构名());
    struct 结构名
    {
        bool operateor(const T & a1,T & a2){

            //若a1在a2前面则返回true
            //否则返回false
        }
    }
    return 0;
}