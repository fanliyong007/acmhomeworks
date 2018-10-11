#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int n;
LL Molecular[108];//分子
LL Denominator[108];//分母
LL GCD(LL num1,LL num2)//最大公约数
{
    if(num1%num2==0)
        return num2;
    else 
        return GCD(num2,num1%num2);
}
LL LCM(LL a,LL b)//最小公倍数
{
    LL temp_lcm;
    temp_lcm=a*b/GCD(a,b);//最小公倍数等于两数之积除以最大公约数
    return temp_lcm;
}
void getsum()
{
    LL multiple=1;
    LL sum = 0;

    for (int i = 0; i < n;i++)
    {
        multiple = LCM(multiple, Denominator[i]);
    }
    for (int i = 0; i < n;i++)
    {
        sum += multiple / Denominator[i] * Molecular[i];
    }
    if(sum==0)
    {
        cout << "0" << endl;
    }
    else if(sum<0)
    {
        if(-sum<multiple)
        {
            LL tmp = GCD(-sum, multiple);
            cout << sum/tmp << "/" << multiple/tmp << endl;
        }
        else if(-sum%multiple==0)
        {
            cout << sum / multiple << endl;
        }
        else 
        {
            LL tmp = GCD(-sum % multiple, multiple);
            cout << sum / multiple << " " << -sum % multiple / tmp << "/" << multiple / tmp << endl;
        } 
    }
    else 
    {
        if(sum<multiple)
        {
            LL tmp = GCD(sum, multiple);
            cout << sum/tmp << "/" << multiple/tmp << endl;
        }
        else if(sum%multiple==0)
        {
            cout << sum / multiple << endl;
        }
        else 
        {
            LL tmp = GCD(sum % multiple, multiple);
            cout << sum / multiple << " " << sum % multiple / tmp << "/" << multiple / tmp << endl;
        } 
    }
}
int main()
{
    char tmp;
    cin >> n;
    int i = 0;
    int numtmp = n;
    for (i = 0; i < numtmp; i++)
    {
        cin>>Molecular[i]>>tmp>>Denominator[i];
        if(Molecular[i]==0)
        {
            i--;
            numtmp--;
        }
    }
    if(i==0)
        cout << "0" << endl;
    else
        getsum();
    // system("pause");
    return 0;
}