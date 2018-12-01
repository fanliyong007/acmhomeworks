#include<iostream>
#include<cstring>
using namespace std;
int price[10000];
int main()
{
    int n = 0;
    while(cin>>price[n])
    {
        n++;
    }
    int max = -9999;
    for (int i = 0; i < n;i++)
    {
        for (int j = i; j < n;j++)
        {
            if(price[j]-price[i]>max)
            {
                max = price[j] - price[i];
            }
        }
    }
    cout << max << endl;
    return 0;
} 