#include<iostream>
#include<cstring>
using namespace std;
int num[408];
int change(int n)
{
    return n % 2 == 0 ? n : n + 1;
}
int fun(int n)
{
    int tmpA = 0, tmpB = 0, max = -999;
    bool flag = true;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n;i++)
    {
        cin >> tmpA >> tmpB;
        tmpA = change(tmpA);
        tmpB = change(tmpB);
        if(tmpA>tmpB)
        {
            int tmp = 0;
            tmp = tmpA;
            tmpA = tmpB;
            tmpB = tmp;
        }
        for (int j = tmpA; j <= tmpB;j++)
        {
            num[j]++;
            if(num[j]>max)
                max = num[j];
        }
    }
    return max*10;    
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        cout<<fun(n)<<endl;
    }
    return 0;
}