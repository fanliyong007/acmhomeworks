
// 如 532 mod 7 =（500%7+30%7+2%7)%7;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    string a;
    long b = 0;
    while(cin>>a>>b)
    {
        int num[1000];
        memset(num, 0, 1000);
        int answer=0;
        int len = 0;
        for (int i = 0; i <a.length();i++)
         {
             num[i] = (int)a[i] - 48;
         }
         len = a.length();
         for (int i = len - 1; i >= 0; i--)
         {
             answer += (num[i] * (int)pow(10, len - i)) % b;
        }
        cout << answer%b<<endl;
    }
    return 0;
}