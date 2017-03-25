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
    i=st.find(22);
    if(i==st.end())
        cout<<"not found"<<endl;
    st.insert(22);
    i=st.find(22);
    if(i==st.end())
        cout<<"not found"<<endl;
    else
        cout<<"found"<<endl;
    return 0;
}
multiset迭代器
multiset<T>::iterator p;
//p是迭代器，相当于指针，可以用于指向multiset中的元素要通过迭代器
//与指针不同：multiset上的的迭代器可以++，--，用！=和==比较，不可比较大小,不可加减整数，不可相减
multiset<T>st;
//st.begin()返回值类型为multiset<T>::iterator,是指st中的最后一个元素后面的迭代器
//对迭代器++，其就指向容器的下一个元素，--则令其指向上一个元素
#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<int>st;
    multiset<int>::iterator i;
    int a[10]={1,14,12,13,7,13,21,19,8,8};
    for(int i=0;i<10;i++)
        st.insert(a[i]);
    //插入元素1，7，8，8，12，13，13，14，19，21
    i=st.lower_bound(13);
    //返回最靠后的迭代器it,使得[begin(),it)中的元素
    //都在13前面,复杂度为log(n)
    cout<<*i<<endl;
    i=st.upper_bound(8);
    //返回最靠前的迭代器it使得[it,end())中的元素
    //都在8后面，复杂度为log(n)
    cout<<*i<<endl;
    st.erase(i);//删除迭代器i指向的元素即12
    for(i=st.begin();i!=st.end();++i)
        cout<<*i<<",";
    return 0;
}
// 输出：
// 13
// 12
// 1，7，8，8，13，13，14，19，21，22，

//自定义排序规则的mutiset用法1
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
struct Rule1
{
    bool operator()(const int & a,const int & b)
    {
        return (a%10)<(b%10);
    }//返回则说明a必须排在b前面
};
int main()
{
    multiset<int,greater<int>>st;//排序规则为从大到小
    int a[10]={1,14,12,13,7,13,21,19,8,8};
    for(int i=0;i<10;i++)
        st.insert(a[i]);
    multiset<int,greater<int>>::iterator i;
    for(int i=st.begin();i!=st.end();++i)
        cout<<*i<<",";
    cout<<endl;
    multiset<int,Rule1>st2;
    //st2的元素排序规则为：个位数小的排在前面
    for(int i=0;i<10;++i)
        st2.insert(a[i]);
    multiset<int,Rule1>::iterator p;
    for(p=st2.begin();p!=st2.end();++p)
        cout<<*p<<",";
    cout<<endl;
    p=str2.find(133);
    //按理说133不存在于multiset中
    //但是找到的为什么呢？
    //这是因为find(x):在排序容器中找到一个元素y，
    //使得“x必须排在y前面”和“y必须排在x前面”
    //都不成立
    cout<<*p<<endl;
    return 0;
}
// 输出
// 1，21，12，13，13，14，7，8，8，19，
// 13
//自定义排序规则的mutiset用法2
#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student
{
    char name[20];
    int id;
    int score;
};
Student students[]=
{
    {"jack",112,78},
    {"Mary",102,85},
    {"Ala",333,92},
    {"Zero",101,70},
    {"Cindy",102,78};
}
struct Rule
{
    bool operator() (const Student & s1,const Student & s2)
    {
        if(s1.score!=s2.score)
            return s1.score>s2.score;
        else
            return (strcmp(s1.name,s2.name)<0);
    }
}
int main()
{
    multiset<Student,Rule>st;
    for(int i=0;i<5;++i)
        st.insert(student[i]);
    multiset<Student,Rule>::iterator p;
    for(p=st.begin();p!=st.end();++p)
        cout<<p->score<<" "<<p->name<<" "<<p->id<<endl;
    Student s={"Mary",1000,85};
    p=st.find(s);
    if(p!=st.end())
         cout<<p->score<<" "<<p->name<<" "<<p->id<<endl;
    return 0;
}
// 输出
// 92 Ala 333
// 85 Mary 102
// 78 Cindy 102
// 78 Jack 102
// 70 Zero 101
// 85 Mary 102
