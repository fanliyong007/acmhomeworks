// map的用法
// 和multimap区别在于:
// 不能有关键字重复的元素
// 可以使用 [] ,下标为关键字,返回值为first和关键字相同的元
// 素的second
// 插入元素可能失败
#include<iostream>
#include<map>
#include<string>
using namespace std;
struct Student
{
    string name;
    int score;
};
Student students[5]=
{
   {"Jack",89},
   {"Tom",74},
   {"Cindy",87},
   {"Alysa",87},
   {"Micheal",98} 
};
typedef map<string,int>MP;
int main()
{
    MP mp;
    for(int i=0;i<5;++i)
        mp.insert(make_pair(students[i].name,students[i].score));
    cout<<mp["Jack"]<<endl;// 输出 89
    mp["Jack"]=60;//修改名为"Jack"的元素的second
    for(MP::iterator i=mp.begin();i!=mp.end();i++)
     //输出:(Alysa,87) (Cindy,87) (Jack,60) (Micheal,98) (Tom,74)   
        cout<<"("<<i->first<<","<<i->second<<")";
    cout<<endl;
    Student st;
    st.name="Jack";
    st.score=99;
    pair<MP::iterator,bool>p=mp.insert(make_pair(st.name,st.scora));
    if(p.second)
        cout<<"("<<p.first->first<<","
        <<p,first->second<<") inserted"<<endl;
    else
        cout<<"inserttion failed"<<endl;//输出此信息
    mp["Harry"]=78;//插入一元素,其first为"Harry",然后将其second改为78
    MP::iterator q=mp.find("Harry");//输出 (Harry,78)
    cout<<"("<<q->first<<","<<q->second<<")"<<endl;
   return 0; 
}
// map例题:单词词频统计程序
// 输入大量单词,每个单词,一行,不超过20字符,没有空
// 格。 按出现次数从多到少输出这些单词及其出现次数。
// 出现次数相同的,字典序靠前的在前面
// 输入样例:
// this
// is
// ok
// this
// plus
// that
// is
// plus
// plus
// 输出样例:
// plus 3
// is 2例题:单词词频统计程序
// 输入大量单词,每个单词,一行,不超过20字符,没有空
// 格。 按出现次数从多到少输出这些单词及其出现次数。
// 出现次数相同的,字典序靠前的在前面
// 输入样例:
// this
// is
// ok
// this
// plus
// that
// is
// plus
// plus
// 输出样例:
// plus 3
// is 2
// this 2
// ok 1
// that 1
// this 2
// ok 1
// that 1
#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
struct Word
{
    int times;
    string wd;
};
struct Rule
{
    bool operator () (const Word & w1,const Word & w2)
    {
        if(w1.times!=w2.times)
            return w1.times>w2.times;
        else
            return w1.wd<w2.wd;
    }
};
int main()
{
    string s;
    set<Word,Rule>st;
    map<string,int>mp;
    while(cin>>s)
        ++mp[s];
    for(map<string,int>::iterator i=mp.begin();i!=mp.end();++i)
    {
        Word tmp;
        tmp.wd=i->first;
        tmp.times=i->second;
        st.insert(tmp);
    }
    for(set<Word,Rule)::iterator i=st.begin();i!=st.end();++i)
        cout<<i->wd<<" "<<i->times<<endl;
    return 0;
}