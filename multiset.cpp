multiset<T>st;
//定义了一个multiset变量st，st里面可以存放T类型的数据，并能自动排序。开始st为空
//排序规则：表达式"a<b"为true,则a排在b前面
//可以用st.insert添加元素，st.find查找元素，st.erase删除元素，复杂度为log(n)
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
int main()
{
    multiset<int>st;
    int a[10]={1,14,12,13,7,13,21,19,8,8};
    for(int i=0;i<10;i++)
        st.insert(a[i]);//插入元素
    multiset<int>::iterator i;//迭代器，近似于指针
    for(i=st.begin();i!=st.end();++i)
        cout<<*i<<",";
    cout<<endl;
    //输出：1,7,8,8,12,13,13,14,19,21,
    return 0;
}
multiset迭代器
multiset<T>::iterator p;
//p是迭代器，相当于指针，可以用于指向multiset中的元素要通过迭代器
//与指针不同：multiset上的的迭代器可以++，--，用！=和==比较，不可比较大小,不可加减整数，不可相减
multiset<T>st;
//st.begin()返回值类型为multiset<T>::iterator,是指st中的最后一个元素后面的迭代器
//对迭代器++，其就指向容器的下一个元素，--则令其指向上一个元素
