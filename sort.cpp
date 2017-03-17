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
            return a1>a2;
            //若a1在a2前面则返回true
            //否则返回false
        }
    }
    return 0;
}
//第三个参数
less<数据类型>()//从小到大排序

greater<数据类型>()//从大到小排序
qsort ( 数组名 ，元素个数，元素占用的空间(sizeof)，比较函数)
比较函数是一个自己写的函数 遵循 int com(const void *a,const void *b) 的格式。
当a b关系为 > < = 时，分别返回正值 负值 零 （或者相反）。
使用a b 时要强制转换类型，从void * 转换回应有的类型后，进行操作。
数组下标从零开始,个数为N, 下标0-(n-1)。
实例：
int compare(const void *a,const void *b)
{
  return *(int*)b-*(int*)a;  
}
int main()
{
  int a[20]={2,4,1,23,5,76,0,43,24,65},i;
  for(i=0;i<20;i++)
  cout<<a[i]<<endl;
  qsort(a,20,sizeof(int),compare());
  for(i=0;i<20;i++)
  cout<<a[i]<<endl;
  return 0;
}
//qsort 函数执行期间，需要比较两个元素哪个应在前面时，就以两个元素的地址作为参数，调用 MyCompare 函数。
//如果返回值小于0，则qsort 就得知第一个元素应该在前，如果返回值大于0，则第一个元素应该在后。
//如果返回值等于0，则哪个在前都行。