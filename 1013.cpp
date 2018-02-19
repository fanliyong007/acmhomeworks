#include<iostream>
using namespace std;

int change(int num);
int main()
{
    int num;
    while(cin>>num&&num!=0)
    {
        int tmp = change(num);
        int x = 0;
        while(tmp>10)
        {
            while(tmp>0)
            {
                x += tmp % 10;
                tmp /= 10;
            }
            tmp = x;
            x = 0;
        }
            cout << tmp << endl;
    }
    return 0;
}
int change(int num)
{
    if(num>0)
        return num;
    else
    {
        return -num;
    }
}