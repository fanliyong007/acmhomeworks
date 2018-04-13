    // 模板：建议计算时把较大的数放在左边对较小的数做运算，比如“999+1”而不是"1+999"，
    // 因为我的模板针对该类型进行了很大的效率优化。另外模板可能因为更新的缘故，
    // 跟后面的解说会有细微出入。
#include<bits/stdc++.h>
using namespace std;    
const int maxn = 1000;     
struct bign{  
    int d[maxn], len;  
    void clean() { while(len > 1 && !d[len-1]) len--; }  
    bign(){ memset(d, 0, sizeof(d)); len = 1; }  
    bign(int num){ *this = num; }   
    bign(char* num) { *this = num; }  
    bign operator = (const char* num){  
        memset(d, 0, sizeof(d)); len = strlen(num);  
    for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';  
        clean();  
        return *this;  
    }  
    bign operator = (int num){  
        char s[20]; sprintf(s, "%d", num);  
        *this = s;  
        return *this;  
    }  
    bign operator + (const bign& b){  
    bign c = *this; int i;  
    for (i = 0; i < b.len; i++){  
        c.d[i] += b.d[i];  
        if (c.d[i] > 9) c.d[i]%=10, c.d[i+1]++;  
    }  
    while (c.d[i] > 9) c.d[i++]%=10, c.d[i]++;  
    c.len = max(len, b.len);  
    if (c.d[i] && c.len <= i) c.len = i+1;  
        return c;  
    }  
    bign operator - (const bign& b){  
    bign c = *this; int i;  
    for (i = 0; i < b.len; i++){  
        c.d[i] -= b.d[i];  
    if (c.d[i] < 0) c.d[i]+=10, c.d[i+1]--;  
    }  
    while (c.d[i] < 0) c.d[i++]+=10, c.d[i]--;  
    c.clean();  
    return c;  
    }  
    bign operator * (const bign& b)const{  
        int i, j; bign c; c.len = len + b.len;   
        for(j = 0; j < b.len; j++) for(i = 0; i < len; i++)   
            c.d[i+j] += d[i] * b.d[j];  
        for(i = 0; i < c.len-1; i++)  
            c.d[i+1] += c.d[i]/10, c.d[i] %= 10;  
        c.clean();  
        return c;  
        }  
    bign operator / (const bign& b){  
        int i, j;  
        bign c = *this, a = 0;  
        for (i = len - 1; i >= 0; i--)  
        {  
            a = a*10 + d[i];  
            for (j = 0; j < 10; j++) if (a < b*(j+1)) break;  
            c.d[i] = j;  
            a = a - b*j;  
        }  
        c.clean();  
        return c;  
    }  
    bign operator % (const bign& b){  
        int i, j;  
        bign a = 0;  
        for (i = len - 1; i >= 0; i--)  
        {  
            a = a*10 + d[i];  
            for (j = 0; j < 10; j++) if (a < b*(j+1)) break;  
            a = a - b*j;  
        }  
        return a;  
    }  
    bign operator += (const bign& b){  
        *this = *this + b;  
        return *this;  
    }  
    bool operator <(const bign& b) const{  
        if(len != b.len) return len < b.len;  
        for(int i = len-1; i >= 0; i--)  
            if(d[i] != b.d[i]) return d[i] < b.d[i];  
                return false;  
        }  
    bool operator >(const bign& b) const{return b < *this;}  
    bool operator<=(const bign& b) const{return !(b < *this);}  
    bool operator>=(const bign& b) const{return !(*this < b);}  
    bool operator!=(const bign& b) const{return b < *this || *this < b;}  
    bool operator==(const bign& b) const{return !(b < *this) && !(b > *this);}        
string str() const{  
        char s[maxn]={};  
        for(int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';  
        return s;  
    }  
};  
      
istream& operator >> (istream& in, bign& x)  
{  
    string s;  
    in >> s;  
    x = s.c_str();  
    return in;  
}  
      
ostream& operator << (ostream& out, const bign& x)  
{  
    out << x.str();  
    return out;  
}  
// 基本模板
// 说明：注释出现的“[int]”形式，代表这是int类型的变量名或者一个int值。其它[bign]、[char*]同理。
    #include <iostream> // 要用cin、cout   
    #include <string>   // 要用string类   
    #include <cstring>  // 要用strlen   
    #include <cstdio>   // 要用sprintf   
    using namespace std;  
      
    const int maxn = 2000;  // 大整数的最高位数限制   
      
    struct bign{  
        int d[maxn], len;  
      
        // 去掉大数的前导0   
        void clean() { while(len > 1 && !d[len-1]) len--; }  
      
        // 初始化：默认初始化为值0   
        bign() { memset(d, 0, sizeof(d)); len = 1; }  
          
        // 初始化：可以用“bign [bign] = [int];”或“bign [bign]([int]);”  
        bign(int num) { *this = num; }  
          
        // 初始化：可以用“bign [bign] = [char*];”或“bign [bign](char*);”  
        bign(char* num) { *this = num; }  
          
        // 赋值：可以用“[bign] = [char*];”   
        bign operator = (const char* num){  
            len = strlen(num);  
            for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';  
            clean();  
            return *this;  
        }  
          
        // 赋值：可以用“[bign] = [int];”   
        bign operator = (int num){  
            char s[maxn];  
            sprintf(s, "%d", num);  
            *this = s;  
            return *this;  
        }  
      
        // 将int数组存储的值转换为高精度的字符串形式   
        string str() const{  
            string res;  
            for(int i = 0; i < len; i++) res = char(d[i]+'0') + res;  
            return res;  
        }  
    };  
      
    // 可以用“cin >> [bign];”的方式输入   
    istream& operator >> (istream& in, bign& x)  
    {  
        string s;  
        in >> s;  
        x = s.c_str();  
        return in;  
    }  
      
    // 可以用“cout << [bign];”的方式输出   
    ostream& operator << (ostream& out, const bign& x)  
    {  
        out << x.str();  
        return out;  
    }  

// 不论做哪类高精度运算最好都完整抄录该部分代码，可以让bign类型用起来跟int一样方便。
// 四个头文件包含了模板中需要用到的数据类型和函数。
// 常量maxn代表会出现的最大整数位数，这个值定太小会出错(见下文的“例题-2”，有个乘法中的陷阱)，
//但也不要太大浪费过多内存。
// clean在后续的减法、乘法、除法里都要用到。
// 介绍-2：扩展bign的运算功能
// 该部分代码包括上面所有重载的运算符：+、-、*、/、%、+=。
// 注意第加法运算里调用了max 函数，UVA 的 OJ 可以直接使用，其它OJ 未必。
// 模板的减法要注意不能用小数减大数，要算绝对值，可以用(a<b?b-a:a-b)。
// 虽然重载的运算符两边数据类型都是bign，但因为自动强制转换，所以用“[bign]*[int]”也不会错。
// （这在应用中带来了相当大的便利）
// 这里的除法与C语言中两个整数相除的效果相同，会舍尾取整。且除法里其实包含取余运算了，最后的a就是。
// 末尾写了个重载“+=”的代码，主要是方便bign类型的使用。
// 读者可以根据自己喜好，①把“*=”等的重载代码写上方便使用，②或者在使用bign类型中不要用这类运算符。
// 最后说一下效率问题，因为我的代码可以进行大数对大数的运算，
// 如大数除大数、大数对大数取余，所以在大数除int、大数对int取余时，效率不及专门功能的函数，这里牺牲效率增加通用性。
// 介绍-3：扩展bign的比较功能
// 只要定义了“<”符号，即可用它定义其他所有比较运算符。
// 实际题目中根据需要抄录小于和其它需要的运算符，
// 不必全部写入(虽然到了高级运算，如取余，就环环相扣，很难删除某一部分了)，
// 在“介绍-2”中的运算符也是一样，这样在ACM比赛中能加快解题速度。 



//  前言:由于计算机运算是有模运算,数据范围的表示有一定限制,如整型int(C++中int 与long相同)表达范围是(-2^31~2^31-1),unsigned long(无符号整数)是(0~2^32-1),都约为几十亿.如果采用实数型,则能保存最大的double只能提供15~16位的有效数字,即只能精确表达数百万亿的数.因此,在计算位数超过十几位的数时,不能采用现有类型,只能自己编程计算.
// 高精度计算通用方法:高精度计算时一般用一个数组来存储一个数,数组的一个元素对应于数的一位(当然,在以后的学习中为了加快计算速度,也可用数组的一个元素表示数的多位数字,暂时不讲),表示时,由于数计算时可能要进位,因此为了方便,将数由低位到高位依次存在数组下标对应由低到高位置上,另外,我们申请数组大小时,一般考虑了最大的情况,在很多情况下,表示有富余,即高位有很多0,可能造成无效的运算和判断,因此,我们一般将数组的第0个下标对应位置来存储该数的位数.如数:3485(三千四百八十五)，表达在数组a[10]上情况是:
// 下标　　0  　 1　   2   　3   　　4 　  5    6    7    8    9  
// 内容　　4   　5  　 8   　4   　　3  　 0    0    0    0    0
// 说明：位数   个位  十位  百位　千位
// 具体在计算加减乘除时方法就是小学时采用的列竖式方法．
// 注：高精度计算时一般用正数，对于负数，通过处理符号位的修正．
// 一．高精度数的存储
// １．如对数采用的字符串输入
#include <iostream>
#include <cstring>
using namespace std;
const int N=100;//最多100位
int main()
{
int a[N+1],i;
string s1;
cin>>s1;//数s1
memset(a,0,sizeof(a)); //数组清0
a[0]=s1.length(); //位数
for(i=1;i<=a[0];i++) a[i]=s1[a[0]-i]-'0';//将字符转为数字并倒序存储．
return 0;
}
2.直接读入
#include <iostream>
using namespace std;
const int N=100;//最多100位
int main()
{
int a[N+1],i,s,key;
cin>>key;//数key
memset(a,0,sizeof(a)); //数组清0
i=0;//第0位
while(key)  //当key大于0
{
  a[++i]=key%10;//取第i位的数
  key=key/10;
}
a[0]=i; //共i位数
return 0;
}
// 3.直接初始化(用a[]存储)
// 初始化为0: memset(a,0,sizeof(a));
// 初始化为1: memset(a,0,sizeof(a));a[0]=1;a[1]=1;

// 以下程序都只写函数，不写完整程序，所有高精度数存储都满足上述约定。
// 二.高精度数比较
int compare(int a[],int b[])   //比较a和b的大小关系，若a>b则为1，a<b则为-1,a=b则为0
{int i;
if (a[0]>b[0]) return 1;//a的位数大于b则a比b大
if (a[0]<b[0]) return -1;//a的位数小于b则a比b小
for(i=a[0];i>0;i--)  //从高位到低位比较
     {if (a[i]>b[i]) return 1;
      if (a[i]<b[i]) return -1;}
return 0;//各位都相等则两数相等。
}
三、高精度加法
int plus(int a[],int b[]) //计算a=a+b
{int i,k;
k=a[0]>b[0]?a[0]:b[0]; //k是a和b中位数最大的一个的位数
for(i=1;i<=k;i++)
    {a[i+1]+=(a[i]+b[i])/10;  //若有进位，则先进位
    a[i]=(a[i]+b[i])%10;}  //计算当前位数字,注意：这条语句与上一条不能交换。
if(a[k+1]>0) a[0]=k+1;  //修正新的a的位数（a+b最多只能的一个进位）
               else a[0]=k;
return 0;
}
四、高精度减法
int gminus(int a[],int b[]);//计算a=a-b，返加符号位0:正数 1:负数
{ int flag,i
  flag=compare(a,b); //调用比较函数判断大小
if (falg==0)//相等
  {memset(a,0,sizeof(a));return 0;}  //若a=b，则a=0,也可在return前加一句a[0]=1,表示是 1位数0
if(flag==1) //大于  
  {  for(i=1;i<=a[0];i++)
      {  if(a[i]<b[i]){ a[i+1]--;a[i]+=10;} //若不够减则向上借一位
        a[i]=a[i]-b[i];}
     while(a[a[0]]==0) a[0]--; //修正a的位数
    return 0;}
if (flag==-1)//小于  则用a=b-a,返回-1
    { for(i=1;i<=b[0];i++)       {  if(b[i]<a[i]){ b[i+1]--;b[i]+=10;} //若不够减则向上借一位
        a[i]=b[i]-a[i];}
      a[0]=b[0];
     while(a[a[0]]==0) a[0]--; //修正a的位数
    return -1;}
}
五、高精度乘法1(高精度乘单精度数，单精度数是指通常的整型数)
int multi1(int a[],long  key) //a=a*key,key是单精度数  
{int i,k;
if (key==0){memset(a,0,sizeof(a));a[0]=1;return 0;} //单独处理key=0
for(i=1;i<=a[0];i++)a[i]=a[i]*key;//先每位乘起来
for(i=1;i<=a[0];i++){a[i+1]+=a[i]/10;a[i]%=10;} //进位
//注意上一语句退出时i=a[0]+1
while(a[i]>0) {a[i+1]=a[i]/10;a[i]=a[i]%10;i++;a[0]++];}  //继续处理超过原a[0]位数的进位,修正a的位数
return 0;
}

int multi2(int a[],int b[]) //a=a*b
{
}