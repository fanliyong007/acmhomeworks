/*假设表达式中只允许出现圆括号和方括号且他们的嵌套顺序随意，
即（【】（））或者【（【】【】）】等均合法。但是【（】）或者
（【（（（）或者（（）】【）等为不合法。输入诺干个表达式，请
检测表达式的括号是否合法（#表示结束）合法输出Yes否则No*/
#include<iostream>
#include<stack>
#include<cstring>
#define max 100
using namespace std;
bool cp(char a)
{
    if(a=='['||a=='(')
        return true;
    else
        return false;
}
bool ca(char a,char b)
{
    if(a=='['&&b==']')
        return true;
    else if(a=='('&&b==')')
        return true;
    else
        return false;
}
int main()
{
    stack<char>stk;
    char achar[max];
    while(true)
    {
        cin.getline(achar,max,'\n');
        if(achar[0]=='#')
            break;
        int count=strlen(achar);
        for(int i=0;i<count;i++)
        {
            if(stk.empty()&&cp(achar[i]))
            {
                stk.push(achar[i]);
            }
            else if(cp(achar[i]))
            {
                stk.push(achar[i]);
            }
            if(ca(stk.top(),achar[i]))
            {
                    stk.pop();
            }
        }
        if(stk.empty())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
