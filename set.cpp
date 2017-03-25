//set和multiset的区别在于容器内不能有重复的与元素
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    set<int> st;
    int a[10]={1,2,3,8,7,7,5,6,8,12};
    for(int i=0;i<10;++i)
    {
        st.insert(a[i]);
    }
    cout<<st.size()<<endl;//输出：8
    set<int>::iterator i;
    for(i=st.begin();i!=st.end();++i)
        cout<<*i<<",";//输出：1，2，3，5，6，7，8，12，
    cout<<endl;
    pair<set<int>::iterator,bool>result=st.insert(2);
    // pair<set<int>::iterator,bool>等价于
    // struct
    // {
    //     set<int>::iterator first;
    //     bool second;
    // };
    if(!result,second)
        cout<<*result.first<<"already exists"<<endl;
    else
        cout<<*result.first<<" insert."<<endl;
    return 0;
}
//输出
//2 already exists
// pair模板的用法
pair<T1,T2>类型等价于：
struct
{
    T1 first;
    T2 second;
}
例如：pair<int,double>a;
等价于：
struct 
{
    int first;
    double second;
}a;
a.first=1;//ok
a.second=1.01;//ok

