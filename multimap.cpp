// multimap容器里的元素都是pair形式
// 例：multimap<T1，T2>mp;
// 则mp里的元素都是如下类型
// struct 
// {
//     T1 first;//关键字
//     T2 second;//值
// }
// multimap中的元素按照first排序，并可以按first进行查找
// 缺省的排序规则是"a.first<b.first"为true，则a排在b前面

// 一个学生成绩录入和查询系统，接受以下两种输入：
// Add name id score
// Query score
// name是个不超过16字符的字符串,中间没有空格,代表学生姓名。id
// 是个整数,代表学号。score是个整数,表示分数。学号不会重复,分数
// 和姓名都可能重复。
// 两种输入交替出现。第一种输入表示要添加一个学生的信息,碰到
// 这种输入,就记下学生的姓名、id和分数。第二种输入表示要查询,碰
// 到这种输入,就输出已有记录中分数比score低的最高分获得者的姓名、
// 学号和分数。如果有多个学生都满足条件,就输出学号最大的那个学生
// 的信息。如果找不到满足条件的学生,则输出“Nobody”
// 输入样例:
// Add Jack 12 78
// Query 78
// Query 81
// Add Percy 9 81
// Add Marry 8 81
// Query 82
// Add Tom 11 79
// Query 80
// Query 81
// 输出样例:
// Nobody
// Jack 12 78
// Percy 9 81
// Tom 11 79
// Tom 11 79
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
struct StudentInfo
{
    int id;
    char name[20];
};
struct Student 
{
    int score;
    StudentInfo info;
};
typedef multimap<int,StudentInfo>MAP_STD;
// 此后 MAP_STD 等价于 multimap<int,StudentInfo>
// typedef int * PINT;
// 则此后 PINT 等价于 int *。 即 PINT p; 等价于 int * p;
int main()
{
    MAP_STD mp;
    Student st;
    char cmd[20];
    while(cin>>cmd)
    {
        if(cmd[0]=='A')
        {
            cin>>st.info.name>>st.info.id>>st.score;
            mp.insert(make_pair(st.score,st.info));
        }
        //make_pair生成一个 pair<int,StudentInfo>变量
        //其first 等于 st.score, second 等于 st.info
        else if(cmd[0]=='Q')
        {
            int score;
            cin>>score;
            MAP_STD::iterator p=mp.lower_bound(score);
            if(p!=mp.begin())
            {
                --p;
                score=p->first;//比要查询分数低的最高分
                MAP_STD::iterator maxp=p;
                int maxId=p->second.id;
                for(;p!=mp.begin()&&p->first==score;--p)
                {
                    if(p->second.id>maxId)
                    {
                        maxp=p;
                        maxId=p->second.id;
                    }
                }
                if(p->first==score)
                //如果上面循环是因为 p == mp.begin() 而终止,则p指向的元素还要处理
                {
                    if(p->second.id>maxId)
                    {
                        maxp=p;
                        maxId=p->second.id;
                    }
                }
                cout<<maxp->second.name<<" "
                <<maxp->second.id<<" "
                <<maxp->first<<endl;
            }
            //lower_bound的结果就是 begin,说明没人分数比查询分数低
            else
                cout<<"Nobody"<<endl;
        }
    }
    return 0;
}