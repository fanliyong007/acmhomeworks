    // 模板：建议计算时把较大的数放在左边对较小的数做运算，比如“999+1”而不是"1+999"，
    // 因为我的模板针对该类型进行了很大的效率优化。另外模板可能因为更新的缘故，
    // 跟后面的解说会有细微出入。
    #include <iostream>  
    #include <string>  
    #include <cstring>  
    #include <cstdio>  
    using namespace std;  
      
    const int maxn = 1000;  
      
    struct bign{  
        int d[maxn], len;  
      
        void clean() { while(len > 1 && !d[len-1]) len--; }  
      
        bign()          { memset(d, 0, sizeof(d)); len = 1; }  
        bign(int num)   { *this = num; }   
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
