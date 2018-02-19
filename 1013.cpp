//  如果你一开始把所有的值设置为int型，恭喜你，你会得到一个WA
//  接着你大概会改成unsigned型，恭喜你，你会得到一个超时
// 然后你终于恍然大悟，用字符串！！

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string num;
    while(cin>>num&&num!="0")
    {
        int tmp = 0;
        for (int i = 0; i < num.length();i++)
        {
            tmp += num[i] - '0';
        }
        while(tmp>=10)
        {
            int x = 0;
            while(tmp)
            {
                x += tmp % 10;
                tmp /= 10;
            }
            tmp = x;
        }
        cout << tmp << endl;
    }
    return 0;
}
