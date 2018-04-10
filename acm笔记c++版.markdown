string
======
之所以抛弃char*的字符串而选用C++标准程序库中的string类，是因为他和前者比较起来，不必担心内存是否足够、字符串长度等等，而且作为一个类出现，他集成的操作函数足以完成我们大多数情况下(甚至是100%)的需要。我们可以用 = 进行赋值操作，== 进行比较，+ 做串联（是不是很简单?）。我们尽可以把它看成是C++的基本数据类型。
首先，为了在我们的程序中使用string类型，我们必须包含头文件 < string > 。如下：
# include  < string >  注意这里不是string.h string.h是C字符串头文件
## 1．声明一个C++字符串
声明一个字符串变量很简单：
string Str;
这样我们就声明了一个字符串变量，但既然是一个类，
就有构造函数和析构函数。上面的声明没有传入参数，
所以就直接使用了string的默认的构造函数，这个函数所作的就是把Str初始化为一个空字符串。
### String类的构造函数和析构函数如下：
* a)    string s;  //生成一个空字符串s
* b)    string s(str) //拷贝构造函数 生成str的复制品
* c)    string s(str,stridx) //将字符串str内“始于位置stridx”的部分当作字符串的初值
* d)    string s(str,stridx,strlen) //将字符串str内“始于stridx且长度顶多strlen”的部分作为字符串的初值
* e)    string s(cstr) //将C字符串作为s的初值
* f)    string s(chars,chars_len) //将C字符串前chars_len个字符作为字符串s的初值。
* g)    string s(num,c) //生成一个字符串，包含num个c字符
* h)    string s(beg,end) //以区间beg;end(不包含end)内的字符作为字符串s的初值
* i)    s.~string() //销毁所有字符，释放内存
都很简单，我就不解释了。
## 2．字符串操作函数
 这里是C++字符串的重点，我先把各种操作函数罗列出来，
不喜欢把所有函数都看完的人可以在这里找自己喜欢的函数，再到后面看他的详细解释。
* a) =,assign()   //赋以新值
* b) swap()   //交换两个字符串的内容
* c) +=,append(),push_back() //在尾部添加字符
* d) insert() //插入字符
* e) erase() //删除字符
* f) clear() //删除全部字符
* g) replace() //替换字符
* h) + //串联字符串
* i) ==,!=,<,<=,>,>=,compare()  //比较字符串
* j) size(),length()  //返回字符数量
* k) max_size() //返回字符的可能最大个数
* l) empty()  //判断字符串是否为空
* m) capacity() //返回重新分配之前的字符容量
* n) reserve() //保留一定量内存以容纳一定数量的字符
* o) [ ], at() //存取单一字符
* p) >>,getline() //从stream读取某值
* q) <<  //将谋值写入stream
* r) copy() //将某值赋值为一个C_string
* s) c_str() //将内容以C_string返回
* t) data() //将内容以字符数组形式返回
* u) substr() //返回某个子字符串
* v)查找函数
* w)begin() end() //提供类似STL的迭代器支持
* x) rbegin() rend() //逆向迭代器
* y) get_allocator() //返回配置器

### 2．1 C++字符串和C字符串的转换
  C ++提供的由C++字符串得到对应的C_string的方法
是使用data()、c_str()和copy()，其中，data()以字符数组的形式返回字符串内容，但并不添加’\0’。c_str()返回一个以‘\0’结尾的字符数组，而copy()则把字符串的内容复制或写入既有的c_string或字符数组内。C++字符串并不以’\0’结尾。我的建议是在程序中能使用C++字符串就使用，除非万不得已不选用c_string。由于只是简单介绍，详细介绍掠过，谁想进一步了解使用中的注意事项可以给我留言(到我的收件箱)。我详细解释。
### 2．2 大小和容量函数
 一个C++字符串存在三种大小：
* a)现有的字符数，函数是size()和length()，他们等效。Empty()用来检查字符串是否为空。
* b)max_size() 这个大小是指当前C++字符串最多能包含的字符数，很可能和机器本身的限制或者字符串所在位置连续内存的大小有关系。我们一般情况下不用关心他，应该大小足够我们用的。但是不够用的话，会抛出length_error异常
* c)capacity()重新分配内存之前 string所能包含的最大字符数。这里另一个需要指出的是reserve()函数，这个函数为string重新分配内存。重新分配的大小由其参数决定，默认参数为0，这时候会对string进行非强制性缩减。还有必要再重复一下C++字符串和C字符串转换的问题，许多人会遇到这样的问题，自己做的程序要调用别人的函数、类什么的（比如数据库连接函数Connect(char*,char*)），但别人的函数参数用的是char*形式的，而我们知道，c_str()、data()返回的字符数组由该字符串拥有，所以是一种const char*,要想作为上面提及的函数的参数，还必须拷贝到一个char*,而我们的原则是能不使用C字符串就不使用。那么，这时候我们的处理方式是：如果此函数对参数(也就是char*)的内容不修改的话，我们可以这样Connect((char*)UserID.c_str(), (char*)PassWD.c_str()),但是这时候是存在危险的，因为这样转换后的字符串其实是可以修改的（有兴趣地可以自己试一试），所以我强调除非函数调用的时候不对参数进行修改，否则必须拷贝到一个char*上去。当然，更稳妥的办法是无论什么情况都拷贝到一个char*上去。同时我们也祈祷现在仍然使用C字符串进行编程的高手（说他们是高手一点儿也不为过，也许在我们还穿开裆裤的时候他们就开始编程了，哈哈…）写的函数都比较规范，那样我们就不必进行强制转换了。
### 2．3元素存取
我们可以使用下标操作符[]和函数at()对元素包含的字符进行访问。但是应该注意的是操作符[]并不检查索引是否有效（有效索引0~str.length()），如果索引失效，会引起未定义的行为。而at()会检查，如果使用 at()的时候索引无效，会抛出out_of_range异常。有一个例外不得不说，const string a;的操作符[]对索引值是a.length()仍然有效，其返回值是’\0’。其他的各种情况，a.length()索引都是无效的。举例如下：
<pre>
<code>
const string Cstr(“const string”);
string Str(“string”);
Str[3];    //ok
Str.at(3);  //ok
Str[100]; //未定义的行为
Str.at(100);  //throw out_of_range
Str[Str.length()]  //未定义行为
Cstr[Cstr.length()] //返回 ‘\0’
Str.at(Str.length());//throw out_of_range
Cstr.at(Cstr.length()) ////throw out_of_range
</code>
</pre>
我不赞成类似于下面的引用或指针赋值：
<pre>
<code>
char& r=s[2];
char* p= &s[3];
</code>
</pre>
因为一旦发生重新分配，r,p立即失效。避免的方法就是不使用。
### 2．4比较函数
C ++字符串支持常见的比较操作符（>,>=,<,<=,==,!=），
甚至支持string与C-string的比较(如 str<”hello”)。在使用>,>=,<,<=这些操作符的时候是根据“当前字符特性”将字符按字典顺序进行逐一得比较。字典排序靠前的字符小，比较的顺序是从前向后比较，遇到不相等的字符就按这个位置上的两个字符的比较结果确定两个字符串的大小。同时
<pre><code>
string (“aaaa”) < string(aaaaa)
</code></pre>
另一个功能强大的比较函数是成员函数compare()。他支持多参数处理，支持用索引值和长度定位子串来进行比较。他返回一个整数来表示比较结果，返回值意义如下：0-相等〉0-大于 <0-小于。举例如下：
<pre>
<code>
string s(“abcd”);
    s.compare(“abcd”); //返回0
    s.compare(“dcba”); //返回一个小于0的值
    s.compare(“ab”); //返回大于0的值
s.compare(s); //相等
    s.compare(0,2,s,2,2); //用”ab”和”cd”进行比较小于零
    s.compare(1,2,”bcx”,2); //用”bc”和”bc”比较。
</code>
</pre>
### 2．5 更改内容
这在字符串的操作中占了很大一部分。
首先讲赋值，第一个赋值方法当然是使用操作符=，
新值可以是string(如：s=ns) 、c_string(如：s=”gaint”)
甚至单一字符（如：s=’j’）。还可以使用成员函数assign()，
这个成员函数可以使你更灵活的对字符串赋值。还是举例说明吧：
<pre>
<code>
s.assign(str); //不说
s.assign(str,1,3);//如果str是”iamangel” 就是把”ama”赋给字符串
s.assign(str,2,string::npos);//把字符串str从索引值2开始到结尾赋给s
s.assign(“gaint”); //不说
s.assign(“nico”,5);//把’n’ ‘I’ ‘c’ ‘o’ ‘\0’赋给字符串
s.assign(5,’x’);//把五个x赋给字符串
</code>
</pre>
把字符串清空的方法有三个：
s=””;s.clear();s.erase();(我越来越觉得举例比说话让别人容易懂！)。string提供了很多函数用于插入（insert）、删除（erase）、替换（replace）、增加字符。先说增加字符（这里说的增加是在尾巴上），函数有 +=、append()、push_back()。举例如下：
<pre>
<code>
s+=str;//加个字符串
s+=”my name is jiayp”;//加个C字符串
s+=’a’;//加个字符
s.append(str);
s.append(str,1,3);//不解释了同前面的函数参数assign的解释
s.append(str,2,string::npos)//不解释了
s.append(“my name is jiayp”);
s.append(“nico”,5);
s.append(5,’x’);
s.push_back(‘a’);//这个函数只能增加单个字符对STL熟悉的理解起来很简单
</code>
</pre>
也许你需要在string中间的某个位置插入字符串，
这时候你可以用insert()函数，这个函数需要你指定一个安插位置的索引，被插入的字符串将放在这个索引的后面。
<pre>
<code>
s.insert(0,”my name”);
s.insert(1,str);
</code>
</pre>
这种形式的insert()函数不支持传入单个字符，
这时的单个字符必须写成字符串形式(让人恶心)。
既然你觉得恶心，那就不得不继续读下面一段话：为了插入单个字符，insert()函数提供了两个对插入单个字符操作的重载函数：
<pre>
<code>
insert(size_type index,size_type num,chart c)
insert(iterator pos,size_type num,chart c)。
</code>
</pre>
其中size_type是无符号整数，iterator是char*,
所以，你这么调用insert函数是不行的：
<pre>
<code>
insert(0,1, ’j’);
</code>
</pre>
这时候第一个参数将转换成哪一个呢？所以你必须这么写：
<pre>
<code>
insert((string::size_type)0,1,’j’)！
</code>
</pre>
第二种形式指出了使用迭代器安插字符的形式，在后面会提及。顺便提一下，string有很多操作是使用STL的迭代器的，他也尽量做得和STL靠近。删除函数erase()的形式也有好几种（真烦！），替换函数replace()也有好几个。举例吧：
<pre>
<code>
string s=”il8n”;
s.replace(1,2,”nternationalizatio”);//从索引1开始的2个替换成后面的C_string
s.erase(13);//从索引13开始往后全删除
s.erase(7,5);//从索引7开始往后删5个
2．6提取子串和字符串连接
题取子串的函数是：substr(),形式如下：
s.substr();//返回s的全部内容
s.substr(11);//从索引11往后的子串
s.substr(5,6);//从索引5开始6个字符
</code>
</pre>
### 2．7输入输出操作
1．>> 从输入流读取一个string。
2．<< 把一个string写入输出流。
另一个函数就是getline(),他从输入流读取一行内容，直到遇到分行符或到了文件尾。
<pre>
<code>
string stuff;
cin >> stuff; //read a word
getline(cin,stuff) //read a line,discard \n
getline(stuff,':'); //read up to :,discard :
</code>
</pre>


### 2．8搜索与查找
查找函数很多，功能也很强大，包括了：
<pre>
<code>
find()
//size_type find(const string & str,size_type pos=0)const 从字符串的pos位置开始，查找子字符串str。如果找到，则返回该子字符串首次出现时其首字符的所以；否则，返回string::npos
//size_type find(const char* str,size_type pos=0)const 从字符串的pos位置开始，查找子字符串s。如果找到，则返回该子字符串首次出现时其首字符的所以；否则，返回string::npos
rfind()
find_first_of()
find_last_of()
find_first_not_of()
find_last_not_of()

// 这些函数返回符合搜索条件的字符区间内的第一个字符的索引，
// 没找到目标就返回npos。所有的函数的参数说明如下：
// 第一个参数是被搜寻的对象。
// 第二个参数（可有可无）指出string内的搜寻起点索引，
// 第三个参数（可有可无）指出搜寻的字符个数。
// 比较简单，不多说不理解的可以向我提出，我再仔细的解答。
// 当然，更加强大的STL搜寻在后面会有提及。
// 最后再说说npos的含义，string::npos的类型是string::size_type,
// 所以，一旦需要把一个索引与npos相比，这个索引值必须是string::size)type类型的，
// 更多的情况下，
// 我们可以直接把函数和npos进行比较（如：if(s.find(“jia”)== string::npos)）。
</code>
</pre>

数据类型范围
============
*   char             -128 ~ +127        (1 Byte)
*   short             -32767 ~ + 32768    (2 Bytes)
*   unsigned short     0 ~ 65536        (2 Bytes)
*   int             -2147483648 ~ +2147483647   (4 Bytes)
*   unsigned int         0 ~ 4294967295    (4 Bytes)
*   long == int
*   long long         -9223372036854775808 ~ +9223372036854775807    (8 Bytes)
*   double         1.7 * 10^308        (8 Bytes)
*   符号属性 长度属性 基本型 所占位数 取值范围 输入符举例 输出符举例
*   -- -- char                            8 -2^7 ~ 2^7-1 %c %c、%d、%u
    
*   signed -- char                    8 -2^7 ~ 2^7-1 %c %c、%d、%u

*   unsigned -- char                8 0 ~ 2^8-1 %c %c、%d、%u

*   [signed] short [int]            16 -2^15 ~ 2^15-1 %hd

*   unsigned short [int]           16 0 ~ 2^16-1 %hu、%ho、%hx

*   [signed] -- int                    32 -2^31 ~ 2^31-1 %d

*   unsigned -- [int]                 32 0 ~ 2^32-1 %u、%o、%x

*   [signed] long [int]              32 -2^31 ~ 2^31-1 %ld

*   unsigned long [int]             32 0 ~ 2^32-1 %lu、%lo、%lx

*   [signed] long long [int]       64 -2^63 ~ 2^63-1 %I64d

*   unsigned long long [int]      64 0 ~ 2^64-1 %I64u、%I64o、%I64x

*   -- -- float                            32 +/- 3.40282e+038 %f、%e、%g

*   -- -- double                        64 +/- 1.79769e+308 %lf、%le、%lg %f、%e、%g

*   -- long double                    96 +/- 1.79769e+308 %Lf、%Le、%Lg

万能头文件<bits/stdc++.h>
========================
    #include<bits/stdc++.h>这个头文件包含以下等等C++中包含的所有头文件：
    #include <iostream>
    #include <cstdio>
    #include <fstream>
    #include <algorithm>
    #include <cmath>
    #include <deque>
    #include <vector>
    #include <queue>
    #include <string>
    #include <cstring>
    #include <map>
    #include <stack>
    #include <set>
等等……
不过在国内oj中，poj，hdu 不支持这个函数，这几个oj的编译器问题，其他国外的oj，还有台湾的oj都支持，CF，Topcoder也都支持。

Pair
===========
*    pair是一种模板类型，其中包含两个数据值，两个数据的类型可以不同，基本的定义如下：
*    pair<int, string> a;
*    表示a中有两个类型，第一个元素是int型的，第二个元素是string类型的，如果创建pair的时候没有对其进行初始化，则调用默认构造函数对其初始化。
*    pair<string, string> a("James", "Joy");
*    也可以像上面一样在定义的时候直接对其初始化。
*    由于pair类型的使用比较繁琐，因为如果要定义多个形同的pair类型的时候，可以时候typedef简化声明：
*    typedef pair<string, string> author;
*    author pro("May", "Lily");
*    author joye("James", "Joyce");
##   Pair对象的操作
*    对于pair类，由于它只有两个元素，分别名为first和second，因此直接使用普通的点操作符即可访问其成员
*    pair<string, string> a("Lily", "Poly");  
*    string name;
*    name = pair.second;
*    生成新的pair对象
*    可以使用make_pair对已存在的两个数据构造一个新的pair类型：
*    int a = 8;
*    string m = "James";
*    pair<int, string> newone;
*    newone = make_pair(a, m);

sort
=====
<pre>
<code>
#include < iostream>
#include < algorithm>
using namespace std;
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    cout<< sort(a,a+sizeof(a));//普通排序格式为sort(数组名+要排序的下标，数组名+要结束的下标，排序规则)排序规则为空则是从小到大
    cout<< sort(a,a+sizeof(a),greater<int>());//倒叙排序
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
</code>
</pre>
当a b关系为 > < = 时，分别返回正值 负值 零 （或者相反）。
使用a b 时要强制转换类型，从void * 转换回应有的类型后，进行操作。
数组下标从零开始,个数为N, 下标0-(n-1)。
实例
<pre>
<code>
int compare(const void *a,const void *b)
{
  return *(int*)b-*(int*)a;  
}
int main()
{
  int a[20]={2,4,1,23,5,76,0,43,24,65},i;
  for(i=0;i<20;i++)
  cout << a[i]<< endl;
  qsort(a,20,sizeof(int),compare);
  for(i=0;i<20;i++)
  cout << a[i] << endl;
  return 0;
}
</code>
</pre>
qsort 函数执行期间，需要比较两个元素哪个应在前面时，就以两个元素的地址作为参数，调用 MyCompare 函数。如果返回值小于0，则qsort 就得知第一个元素应该在前，如果返回值大于0，则第一个元素应该在后。如果返回值等于0，则哪个在前都行。

## 结构体排序
<pre>
<code>
#include "stdafx.h"  
#include<iostream>  
#include<string>  
#include<algorithm>  
using namespace std;  
struct student  
{  
    string name;//姓名  
    int math;//数学成绩  
    int english;//英语  
};  
int c =0;//控制排序规则  
bool compare(student a, student b)  
{  
    if (c == 0)//按照姓名递增排序  
    {  
        return (a.name<=b.name);  
    }  
    else if (c == 1)//按照数学成绩递增排序  
    {  
        return (a.math <= b.math);  
    }  
    else//按照英语成绩递增排序  
    {  
        return (a.english <= b.english);  
    }  
}  
int _tmain(int argc, _TCHAR* argv[])  
{  
    student array[3];  
  
    array[0].name = "John";  
    array[0].math = 86;  
    array[0].english = 91;  
  
    array[1].name = "Michelle";  
    array[1].math = 85;  
    array[1].english =95;  
  
    array[2].name = "Kim";  
    array[2].math = 89;  
    array[2].english = 60;  
    cout << "原始顺序：" << endl;  
    for (int i = 0; i <3; i++)  
        cout << array[i].name << ' ' << array[i].math << ' ' << array[i].english << endl;  
    cout << "按姓名递增排序：" << endl;  
    c =0;  
    sort(array,array+3,compare);  
    for (int i = 0; i <3;i++)  
        cout << array[i].name << ' ' << array[i].math << ' ' << array[i].english << endl;  
    cout << "按数学成绩递增排序：" << endl;  
    c =1;  
    sort(array, array + 3, compare);  
    for (int i = 0; i <3; i++)  
        cout << array[i].name << ' ' << array[i].math << ' ' << array[i].english << endl;  
    system("pause");  
    return 0;  
}  
</code>
</pre>

类型转换
=======
## string转const char*
<pre>
<code>
string s ="abc";
constchar* c_s = s.c_str();
</code>
</pre>
## const char*转string
<pre>
<code>
   直接赋值即可
constchar* c_s ="abc";
string s(c_s);
</code>
</pre>
## string转char*
<pre>
<code>
string s ="abc";
char* c;
constint len = s.length();
c =newchar[len+1];
strcpy(c,s.c_str());
</code>
</pre>
## char*转string
<pre>
<code>
char* c ="abc";
string s(c);
</code>
</pre>
## const char*转char*
<pre>
<code>
constchar* cpc ="abc";
char* pc =newchar[100];//足够长
strcpy(pc,c）
</code>
</pre>
## int转string
<pre>
<code>
int n = 0;
std::stringstream ss;
std::string str;
ss<<n;
ss>>str;
</code>
</pre>
## string转int
<pre>
<code>
std::string str = "123";
int n = atoi(str.c_str());
</code>
</pre>
## char*转数字
<pre>
<code>
#include < stdlib.h>//头文件

int atoi (const char * str);//char2int

long atol(const char * str);//char2long

long int strtol (const char* str, char** endptr, int base);
/*
【参数说明】str 为要转换的字符串，endstr 为第一个不能转换的字符的指针，base 为字符串 str 所采用的进制。
【函数说明】strtol() 会将参数 str 字符串根据参数 base 来转换成长整型数(long)。参数 base 范围从2 至36，或0。参数base 代表 str 采用的进制方式，如base 值为10 则采用10 进制，若base 值为16 则采用16 进制等。strtol() 会扫描参数 str 字符串，跳过前面的空白字符（例如空格，tab缩进等，可以通过 isspace() 函数来检测），直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('\0')结束转换，并将结果返回。
两点注意： 
当 base 的值为 0 时，默认采用 10 进制转换，但如果遇到 '0x' / '0X' 前置字符则会使用 16 进制转换，遇到 '0' 前置字符则会使用 8 进制转换。
若endptr 不为NULL，则会将遇到的不符合条件而终止的字符指针由 endptr 传回；若 endptr 为 NULL，则表示该参数无效，或不使用该参数。
【返回值】返回转换后的长整型数；如果不能转换或者 str 为空字符串，那么返回 0(0L)；如果转换得到的值超出 long int 所能表示的范围，函数将返回 LONG_MAX 或 LONG_MIN（在 limits.h 头文件中定义），并将 errno 的值设置为 ERANGE。*/

unsigned long strtoul (const char* str, char** endptr, int base);

double strtod (const char* str, char** endptr);//函数 strtod() 用来将字符串转换成双精度浮点数
/*strtod() 函数会扫描参数str字符串，跳过前面的空白字符（例如空格，tab缩进等，可以通过 isspace() 函数来检测），直到遇上数字或正负符号才开始做转换，到出现非数字或字符串结束时('\0')才结束转换，并将结果返回。参数 str 字符串可包含正负号、小数点或E(e)来表示指数部分。如123. 456 或123e-2。若endptr 不为NULL，则会将遇到的不符合条件而终止的字符指针由 endptr 传回；若 endptr 为 NULL，则表示该参数无效，或不使用该参数。返回转换后的浮点型数；若不能转换或字符串为空，则返回 0.0。*/

double atof (const char* str);//char2double
/*它会扫描参数str字符串，跳过前面的空白字符（例如空格，tab缩进等，可以通过 isspace() 函数来检测），直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。参数str 字符串可包含正负号、小数点或E(e)来表示指数部分，如123. 456 或123e-2。
返回转换后的浮点数；如果字符串 str 不能被转换为 double，那么返回 0.0。*/

char*itoa(int value,char*string,int radix);
/*int value 被转换的整数，char *string 转换后储存的字符数组，int radix 转换进制数，如2,8,10,16 进制等*/
</code>
</pre>
## math.h
* acos()
求反余弦的值
* cos()
求余弦值
* cosh()
求双曲余玄值
* exp()
e的次幂函数(以e为底的x次方值)
* frexp()
把一个浮点数分解为尾数和指数
* ldexp()
返回x乘上2的exp次方的值
* log()
返回以e为底的对数值
* log10()
返回以10为底的对数值
* pow()
求x的y次方（次幂）
* sin()
正弦函数
* sinh()
双曲正玄函数
* sqrt()
求给定值的平方根
* tan()
正切函数
* tanh()
双曲线正切函数
* fabs()
求浮点数的绝对值
* abs()
求整数的绝对值
* asin()
反正弦函数
* atan()
反正切函数
* atan2()
求y/x的反正切值
* ceil()
向上取整，即求不小于某个数的最小整数
* floor()
向下取整，即求不大于某个数的最大整数
* fmod()
对浮点数取模（求余）
* modf()
将浮点数分解为整数和小数部分
* hypot()
求直角三角形的斜边长
* pow10()
求10的x次方（次幂）

## ctype.h
* isalnum()
判断字符是否为英文字母或数字
* isalpha()
判断字符是否为英文字母
* iscntrl()
判断字符是否为ASCII码的控制字符
* isdigit()
判断字符是否为阿拉伯数字
* isgraph()
判断字符是否为除空格以外的可打印字符
* islower()
判断字符是否为小写字母
* isprint()
判断字符是否为可打印字符
* isspace()
判断字符是否为空白字符
* ispunct()
判断字符是否为标点符号或特殊字符
* isupper()
判断字符是否为大写英文字母
* isxdigit()
判断字符是否为16进制数字
* toascii()
将字符转换成对应的ASCII码
* tolower()
将大写字母转换为小写字母
* toupper()
将小写字母转换为大写字母
* isascii()
检测字符是否为ASCII字符
* isblank()
判断字符是否为TAB或空格

list
====
 List将元素按顺序储存在链表中. 与 向量(vector)相比, 它允许快速的插入和删除，但是随机访问却比较慢。
* assign() 给list赋值 
* back() 返回最后一个元素 
* begin() 返回指向第一个元素的迭代器 
* clear() 删除所有元素 
* empty() 如果list是空的则返回true 
* end() 返回末尾的迭代器 
* erase() 删除一个元素 
* front() 返回第一个元素 
* get_allocator() 返回list的配置器 
* insert() 插入一个元素到list中 
* max_size() 返回list能容纳的最大元素数量 
* merge() 合并两个list 
* pop_back() 删除最后一个元素 
* pop_front() 删除第一个元素 
* push_back() 在list的末尾添加一个元素 
* push_front() 在list的头部添加一个元素 
* rbegin() 返回指向第一个元素的逆向迭代器 
* remove() 从list删除元素 
* remove_if() 按指定条件删除元素 
* rend() 指向list末尾的逆向迭代器 
* resize() 改变list的大小 
* reverse() 把list的元素倒转 
* size() 返回list中的元素个数 
* sort() 给list排序 
* splice() 合并两个list 
* swap() 交换两个list 
* unique() 删除list中重复的元素

* 1)、如何定义一个list对象
<pre>
<code>
#include < list>
int main (void)
{
 list<char > cList; //声明了list<char>模板类 的一个实例
}
</code>
</pre>
* 2)、使用list的成员函数push_back和push_front插入一个元素到list中 
<pre>
<code>
cList. push_back(‘a’); //把一个对象放到一个list的后面
cList. push_front (‘b’); //把一个对象放到一个list的前面
</code>
</pre>
* 3)、使用list的成员函数empty()判断list是否为空 
<pre>
<code>
if (cList.empty())
{
 printf(“this list is empty”);
}
</code>
</pre>
* 4)、用list< char >::iterator得到指向list的指针 
<pre>
<code>
list< char>::iterator charIterator;
for(cIterator = cList.Begin();cIterator != cList.end();cIterator++)
{
 printf(“%c”, *cIterator);
} //输出list中的所有对象
说明：cList.Begin()和cList.end()函数返回指向list< char >::iterator的指针，由于list采用链表结构，因此它不支持随机存取，因此不能用cList.begin()+3来指向list中的第四个对象，vector和deque支持随机存取。
</code>
</pre>
* 5）、用STL的通用算法count()来统计list中的元素个数 
<pre>
<code>
int cNum;
char ch = ’b’;
cNum = count(cList.Begin(), cList.end(), ch); //统计list中的字符b的个数
说明：在使用count()函数之前必须加入#include <algorithm> 
</code>
</pre>
* 6）、用STL的通用算法count_if ()来统计list中的元素个数 
<pre>
<code>
const char c(‘c’);
class IsC
{
public:
 bool operator() ( char& ch )
 {
  return ch== c;
 }
};

int numC;
numC = count_if (cList.begin(), cList.end(),IsC());//统计c的数量；
说明：count_if() 带一个函数对象的参数,函数对象是一个至少带有一个operator()方法的类函数对象被约定为STL算法调用operator时返回true或false。它们根据这个来判定这个函数。举个例子会 说的更清楚些。count_if()通过传递一个函数对象来作出比count()更加复杂的评估以确定一个对象是否应该被记数。

</code>
</pre>

* 7）、使用STL通用算法find()在list中查找对象 
<pre>
<code>
list< char>::iterator FindIterator;
FindIterator = find(cList.begin(), cList.end(), ‘c’);
If (FindIterator == cList.end())
{
 printf(“not find the char ‘c’!”);
}
else
{
 printf(“%c”, * FindIterator);
}
说明：如果没有找到指定的对象，就会返回cList.end()的值，找到了就返回一个指向对象iterator的指针。
</code>
</pre>
* 8）、使用STL通用算法find_if()在list中查找对象
<pre>
<code>
const char c(‘c’);
class c
{
public:
 bool operator() ( char& ch )
 {
  return ch== c;
 }
};
list< char>::iterator FindIterator
FindIterator = find_if (cList.begin(), cList.end(),IsC());//查找字符串c
</code>
</pre> 
说明：如果没有找到指定的对象，就会返回cList.end()的值，找到了就返回一个指向对象iterator的指针。

* 9）、使用list的成员函数sort()排序 
<pre>
<code>
cList.sort();
</code>
</pre>
* 10)、使用list的成员函数insert插入一个对象到list中 
<pre>
<code>
cList.insert(cLiset.end, ‘c’); ///在list末尾插入字符‘c’

char ch[3] ={‘a’, ‘b’, ‘c’};
cList.insert(cList.end, &ch[0], & ch[3] ); //插入三个字符到list中
</code>
</pre>
说明：insert()函数把一个或多个元素插入到指出的iterator位置。元素将出现在 iterator指出的位置以前。
* 11)、如何在list中删除元素 
<pre>
<code>
cList.pop_front(); //删除第一个元素
cList.pop_back(); //删除最后一个元素
cList. Erase(cList.begin()); //使用iterator删除第一个元素；
cList. Erase(cList.begin(), cList.End()); //使用iterator删除所有元素；
cList.remove(‘c’); //使用remove函数删除指定的对象；
list<char>::iterator newEnd;
//删除所有的’c’ ,并返回指向新的list的结尾的iterator
newEnd = cList.remove(cList.begin(), cList.end(), ‘c’);
</code>
</pre>

deque(双向队列) 
==============
deque是一种优化了的、对序列两端元素进行添加和删除操作的基本序列容器。它允许较为快速地随机访问，但它不像vector 把所有的对象保存在一块连续的内存块，而是采用多个连续的存储块，并且在一个映射结构中保存对这些块及其顺序的跟踪。向deque 两端添加或删除元素的开销很小。它不需要重新分配空间，所以向末端增加元素比vector 更有效。 

* 1.Constructors 创建一个新双向队列 
   语法: 
    <pre>
    <code>
      deque();//创建一个空双向队列 
      deque( size_type size );// 创建一个大小为size的双向队列 
      deque( size_type num, const TYPE &val ); //放置num个val的拷贝到队列中 
      deque( const deque &from );// 从from创建一个内容一样的双向队列 
      deque( input_iterator start, input_iterator end ); 
      // start 和 end - 创建一个队列，保存从start到end的元素。
    </code>
    </pre>
* 2.Operators 比较和赋值双向队列 
      //可以使用[]操作符访问双向队列中单个的元素 
* 3.assign() 设置双向队列的值 
   语法: 
    <pre>
    <code>
      void assign( input_iterator start, input_iterator end); 
      //start和end指示的范围为双向队列赋值 
      void assign( Size num, const TYPE &val );//设置成num个val。 
    </code>
    </pre>
* 4.at() 返回指定的元素 
   语法: 
      <pre>
      <code>
      reference at( size_type pos ); 返回一个引用，指向双向队列中位置pos上的元素 
      </code>
      </pre>
* 5.back() 返回最后一个元素 
   语法: 
     <pre>
     <code>
      reference back();//返回一个引用，指向双向队列中最后一个元素 
     </code>
     </pre>
* 6.begin() 返回指向第一个元素的迭代器 
   语法: 
     <pre>
     <code>
      iterator begin();//返回一个迭代器，指向双向队列的第一个元素 
     </code>
     </pre>
* 7.clear() 删除所有元素 
* 8.empty() 返回真如果双向队列为空 
* 9.end() 返回指向尾部的迭代器 
* 10.erase() 删除一个元素 
   语法: 
     <pre>
     <code>
      iterator erase( iterator pos ); //删除pos位置上的元素 
      iterator erase( iterator start, iterator end ); //删除start和end之间的所有元素 
      //返回指向被删除元素的后一个元素 
     </code>
     </pre>
* 11.front() 返回第一个元素的引用
* 12.get_allocator() 返回双向队列的配置器 
* 13.insert() 插入一个元素到双向队列中 
   语法: 
    <pre>
    <code>
    iterator insert( iterator pos, size_type num, const TYPE &val );
        //pos前插入num个val值 
        void insert( iterator pos, input_iterator start, input_iterator end ); 
        //插入从start到end范围内的元素到pos前面 
    </code>
    <pre>
* 14.max_size() 返回双向队列能容纳的最大元素个数 
* 15.pop_back() 删除尾部的元素 
* 16.pop_front() 删除头部的元素 
* 17.push_back() 在尾部加入一个元素 
* 18.push_front() 在头部加入一个元素 
* 19.rbegin() 返回指向尾部的逆向迭代器 
* 20.rend() 返回指向头部的逆向迭代器 
* 21.resize() 改变双向队列的大小 
* 22.size() 返回双向队列中元素的个数 
* 23.swap() 和另一个双向队列交换元素 

vector
======
### 1 基本操作
* (1)头文件#include< vector>.
* (2)创建vector对象，vector< int> vec;
* (3)尾部插入数字：vec.push_back(a);
* (4)使用下标访问元素，cout<< vec[0]<< endl;记住下标是从0开始的。
* (5)使用迭代器访问元素.
<pre>
<code>
vector<int>::iterator it;
for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<< endl;
</code>
</pre>
* (6)插入元素：    vec.insert(vec.begin()+i,a);在第i+1个元素前面插入a;
* (7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素
vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始
* (8)向量大小:vec.size();
* (9)清空:vec.clear();
### 2 结构体vector
vector的元素不仅仅可以使int,double,string,还可以是结构体，但是要注意：结构体要定义为全局的，否则会出错。下面是一段简短的程序代码：
<pre>
<code>
#include< stdio.h>
#include< algorithm>
#include< vector>
#include< iostream>
using namespace std;
typedef struct rect
{
    int id;
    int length;
    int width;
　　//对于向量元素是结构体的，可在结构体内部定义比较函数，下面按照id,length,width升序排序。
　　bool operator< (const rect &a)  const
    {
        if(id!=a.id)
            return id< a.id;
        else
        {
            if(length!=a.length)
                return length< a.length;
            else
                return width< a.width;
        }
    }
}Rect;
int main()
{
    vector < Rect > vec;
    Rect rect;
    rect.id=1;
    rect.length=2;
    rect.width=3;
    vec.push_back(rect);
    vector< Rect>::iterator it=vec.begin();
    cout<<(*it).id<<' '<<(*it).length<<' '<<(*it).width<< endl;
    return 0;
}
</code>
</pre>
### 3  算法
* (1) 使用reverse将元素翻转：需要头文件#include<algorithm>
reverse(vec.begin(),vec.end());将元素翻转(在vector中，如果一个函数中需要两个迭代器，
一般后一个都不包含.)
* (2)使用sort排序：需要头文件#include<algorithm>，sort(vec.begin(),vec.end());(默认是按升序排列,即从小到大).可以通过重写排序比较函数按照降序比较，如下：
<pre>
<code>
//定义排序比较函数：
bool Comp(const int &a,const int &b)
{
    return a>b;
}
//调用时:sort(vec.begin(),vec.end(),Comp)，这样就降序排序。
</code>
</pre>

set
===
* 1.元素插入：insert()
* 2.中序遍历：类似vector遍历（用迭代器）
* 3.反向遍历：利用反向迭代器reverse_iterator。
    例：
   <pre>
   <code>
    set< int> s;
    ......
    set< int>::reverse_iterator rit;
    for(rit=s.rbegin();rit!=s.rend();rit++)
   </code>
   </pre>
* 4.元素删除：与插入一样，可以高效的删除，并自动调整使红黑树平衡。
    <pre>
    <code>
        set< int> s;
        s.erase(2);        //删除键值为2的元素
        s.clear();
    </code>
    </pre>
* 5.元素检索：find()，若找到，返回该键值迭代器的位置，否则，返回最后一个元素后面一个位置。
    <pre>
    <code>
    set< int> s;
    set< int>::iterator it;
    it=s.find(5);    //查找键值为5的元素
    if(it!=s.end())    //找到
        cout<<*it<< endl;
    else            //未找到
        cout<<"未找到";
    </code>
    </pre>
* 6.自定义比较函数
        (1)元素不是结构体：
        例：
        <pre>
        <code>
        //自定义比较函数myComp,重载“（）”操作符
        struct myComp
        {
            bool operator()(const your_type &a,const your_type &b)
            {
                return a.data-b.data>0;
            }
        }
        set< int,myComp>s;
        ......
        set< int,myComp>::iterator it;
        </code>
        </pre>
        (2)如果元素是结构体，可以直接将比较函数写在结构体内。
        例：
        <pre>
        <code>
        struct Info
        {
            string name;
            float score;
            //重载“<”操作符，自定义排序规则
            bool operator < (const Info &a) const
            {
                //按score从大到小排列
                return a.score< score;
            }
        }
        set< Info> s;
        ......
        set< Info>::iterator it; 
        </code>
        </pre>

map
===
   Map是c++的一个标准容器，她提供了很好一对一的关系，在一些程序中建立一个map可以起到事半功倍的效果，总结了一些map基本简单实用的操作！
* 1.map最基本的构造函数；
    <pre>
    <code>
        map< string , int >mapstring;         map< int ,string >mapint;
        map< sring, char>mapstring;         map< char ,string>mapchar;
        map< char ,int>mapchar;            map< int ,char >mapint；
    </code>
    </pre>
* 2.map添加数据；
    <pre>
    <code>
        map< int ,string> maplive;  
        maplive.insert(pair< int,string>(102,"aclive"));
        maplive.insert(map< int,string>::value_type(321,"hai"));
        maplive[112]="April";//map中最简单最常用的插入添加！
    </code>
    </pre>
* 3.map中元素的查找：
    find()函数返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器。   
    <pre>
    <code>
        map< int ,string >::iterator l_it;
        l_it=maplive.find(112);
        if(l_it==maplive.end())
            cout<<"we do not find 112"<< endl;
        else cout<<"wo find 112"<< endl;
    </code>
    </pre>

   
* 4.map中元素的删除：
    如果删除112；
    <pre>
    <code>
        map<int ,string >::iterator l_it;;
        l_it=maplive.find(112);
        if(l_it==maplive.end())
            cout<<"we do not find 112"<< endl;
        else  maplive.erase(l_it);  //delete 112;
    </code>
    </pre>
* 5.map中 swap的用法：
  Map中的swap不是一个容器中的元素交换，而是两个容器交换；
  For example：
    <pre>
    <code>
        #include < map>
        #include < iostream>
        using namespace std;
        int main( )
        {
        map < int, int> m1, m2, m3;
        map < int, int>::iterator m1_Iter;
        m1.insert ( pair < int, int>  ( 1, 10 ) );
        m1.insert ( pair < int, int>  ( 2, 20 ) );
        m1.insert ( pair < int, int>  ( 3, 30 ) );
        m2.insert ( pair < int, int>  ( 10, 100 ) );
        m2.insert ( pair < int, int>  ( 20, 200 ) );
        m3.insert ( pair < int, int>  ( 30, 300 ) );
        cout << "The original map m1 is:";
        for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
            cout << " " << m1_Iter->second;
            cout   << "." << endl;
        // This is the member function version of swap
        //m2 is said to be the argument map; m1 the target map
        m1.swap( m2 );
        cout << "After swapping with m2, map m1 is:";
        for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
            cout << " " << m1_Iter -> second;
            cout  << "." << endl;
        cout << "After swapping with m2, map m2 is:";
        for ( m1_Iter = m2.begin( ); m1_Iter != m2.end( ); m1_Iter++ )
            cout << " " << m1_Iter -> second;
            cout  << "." << endl;
        // This is the specialized template version of swap
        swap( m1, m3 );
        cout << "After swapping with m3, map m1 is:";
        for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
            cout << " " << m1_Iter -> second;
            cout   << "." << endl;
        }
    </code>
    </pre>
* 6.map的sort问题：
  Map中的元素是自动按key升序排序,所以不能对map用sort函数：
  For example：
    <pre>
    <code>
        #include < map>
        #include < iostream>
        using namespace std;
        int main( )
        {
            map < int, int> m1;
            map < int, int>::iterator m1_Iter;
            m1.insert ( pair < int, int>  ( 1, 20 ) );
            m1.insert ( pair < int, int>  ( 4, 40 ) );
            m1.insert ( pair < int, int>  ( 3, 60 ) );
            m1.insert ( pair < int, int>  ( 2, 50 ) );
            m1.insert ( pair < int, int>  ( 6, 40 ) );
            m1.insert ( pair < int, int>  ( 7, 30 ) );
            cout << "The original map m1 is:"<< endl;
            for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
                cout << m1_Iter->first<<" "<< m1_Iter->second<< endl;
        }
        The original map m1 is:
        1 20
        2 50
        3 60
        4 40
        6 40
        7 30
        请按任意键继续. . .
    </code>
    </pre>
* 7.map的基本操作函数：
    <pre>
    <code>
        C++ Maps是一种关联式容器，包含“关键字/值”对
        begin()          返回指向map头部的迭代器
        clear(）         删除所有元素
        count()          返回指定元素出现的次数
        empty()          如果map为空则返回true
        end()            返回指向map末尾的迭代器
        equal_range()    返回特殊条目的迭代器对
        erase()          删除一个元素
        find()           查找一个元素
        get_allocator()  返回map的配置器
        insert()         插入元素
        key_comp()       返回比较元素key的函数
        lower_bound()    返回键值>=给定元素的第一个位置
        max_size()       返回可以容纳的最大元素个数
        rbegin()         返回一个指向map尾部的逆向迭代器
        rend()           返回一个指向map头部的逆向迭代器
        size()           返回map中元素的个数
        swap()            交换两个map
        upper_bound()     返回键值>给定元素的第一个位置
        value_comp()      返回比较元素value的函数
    </code>
    </pre>
## map例程
<pre>
<code>
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
    #include< iostream>
    #include< set>
    #include< map>
    #include< string>
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
                return w1.wd< w2.wd;
        }
    };
    int main()
    {
        string s;
        set< Word,Rule>st;
        map< string,int>mp;
        while(cin>>s)
            ++mp[s];
        for(map< string,int>::iterator i=mp.begin();i!=mp.end();++i)
        {
            Word tmp;
            tmp.wd=i->first;
            tmp.times=i->second;
            st.insert(tmp);
        }
        for(set< Word,Rule)::iterator i=st.begin();i!=st.end();++i)
            cout<< i->wd<<" "<< i->times<< endl;
        return 0;
    }
</code>
</pre>

stack
=====
stack 模板类的定义在< stack>头文件中。
stack 模板类需要两个模板参数，一个是元素类型，一个容器类型，但只有元素类型是必要
的，在不指定容器类型时，默认的容器类型为deque。
定义stack 对象的示例代码如下：
<pre>
<code>
stack< int> s1;
stack< string> s2;
</code>
</pre>
stack 的基本操作有：
* 入栈，如例：s.push(x);
* 出栈，如例：s.pop();注意，出栈操作只是删除栈顶元素，并不返回该元素。
* 访问栈顶，如例：s.top()
* 判断栈空，如例：s.empty()，当栈空时，返回true。
* 访问栈中的元素个数，如例：s.size()。
 
queue
=====
queue 模板类的定义在<queue>头文件中。
与stack 模板类很相似，queue 模板类也需要两个模板参数，一个是元素类型，一个容器类
型，元素类型是必要的，容器类型是可选的，默认为deque 类型。
定义queue 对象的示例代码如下：
<pre>
<code>
queue<int> q1;
queue<double> q2;
</code>
</pre>
queue 的基本操作有：
* 入队，如例：q.push(x); 将x 接到队列的末端。
* 出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。
* 访问队首元素，如例：q.front()，即最早被压入队列的元素。
* 访问队尾元素，如例：q.back()，即最后被压入队列的元素。
* 判断队列空，如例：q.empty()，当队列空时，返回true。
* 访问队列中的元素个数，如例：q.size()

priority_queue
=================
在< queue>头文件中，还定义了另一个非常有用的模板类priority_queue(优先队列）。优先队
列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序
出队（默认为大者优先，也可以通过指定算子来指定自己的优先顺序）。
priority_queue 模板类有三个模板参数，第一个是元素类型，第二个容器类型，第三个是比
较算子。其中后两个都可以省略，默认容器为vector，默认算子为less，即小的往前排，大
的往后排（出队时序列尾的元素出队）。
定义priority_queue 对象的示例代码如下：
<pre>
<code>
priority_queue<int> q1;
priority_queue< pair<int, int> > q2; // 注意在两个尖括号之间一定要留空格。
priority_queue<int, vector<int>, greater<int> > q3; // 定义小的先出队
</code>
</pre>
priority_queue 的基本操作与queue 相同。
初学者在使用priority_queue 时，最困难的可能就是如何定义比较算子了。
如果是基本数据类型，或已定义了比较运算符的类，可以直接用STL 的less 算子和greater
算子——默认为使用less 算子，即小的往前排，大的先出队。
如果要定义自己的比较算子，方法有多种，这里介绍其中的一种：重载比较运算符。优先队
列试图将两个元素x 和y 代入比较运算符(对less 算子，调用x< y，对greater 算子，调用x>y)，若结果为真，则x 排在y 前面，y 将先于x 出队，反之，则将y 排在x 前面，x 将先出队。
看下面这个简单的示例：
<pre>
<code>
#include <iostream>
#include <queue>
using namespace std;
class T
{
    public:
    int x, y, z;
    T(int a, int b, int c):x(a), y(b), z(c)
    {
    }
    };
    bool operator < (const T &t1, const T &t2)
    {
    return t1.z < t2.z; // 按照z 的顺序来决定t1 和t2 的顺序
}
main()
{
    priority_queue<T> q;
    q.push(T(4,4,3));
    q.push(T(2,2,5));
    q.push(T(1,5,4));
    q.push(T(3,3,6));
    while (!q.empty())
    {
    T t = q.top(); q.pop();
    cout << t.x << " " << t.y << " " << t.z << endl;
    }
    return 1;
}
输出结果为(注意是按照z 的顺序从大到小出队的)：
3 3 6
2 2 5
1 5 4
4 4 3
</code>
</pre>
再看一个按照z 的顺序从小到大出队的例子：
<pre>
<code>
#include <iostream>
#include <queue>
using namespace std;
class T
{
    public:
    int x, y, z;
    T(int a, int b, int c):x(a), y(b), z(c)
    {
    }
    };
    bool operator > (const T &t1, const T &t2)
    {
    return t1.z > t2.z;
}
main()
{
    priority_queue<T, vector<T>, greater<T> > q;
    q.push(T(4,4,3));
    q.push(T(2,2,5));
    q.push(T(1,5,4));
    q.push(T(3,3,6));
    while (!q.empty())
    {
    T t = q.top(); q.pop();
    cout << t.x << " " << t.y << " " << t.z << endl;
    }
    return 1;
}
输出结果为：
4 4 3
1 5 4
2 2 5
3 3 6
</code>
</pre>
如果我们把第一个例子中的比较运算符重载为：
<pre>
<code>
bool operator < (const T &t1, const T &t2)
{
return t1.z > t2.z; // 按照z 的顺序来决定t1 和t2 的顺序
}
</code>
</pre>
则第一个例子的程序会得到和第二个例子的程序相同的输出结果。