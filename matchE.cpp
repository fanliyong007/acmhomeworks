#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ll num = 0;
    int i = 0;
    while(cin>>num)
    {
        if(i!=0)
            cout << endl;
        i = 1;
        num = num > 0 ? num : -num;
        ll sum = 0;
        ll tmp = 0;
        while(num>0)
        {
            tmp = num % 10;
            num /= 10;
            if(tmp%2==0)
                sum += tmp;
        }
        cout << sum << endl;
    }
    return 0;
}