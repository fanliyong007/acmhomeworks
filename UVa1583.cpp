#include<bits/stdc++.h>
using namespace std;
int arr[100008];
int sumof(int i)
{
    int sum = 0;
    while(i!=0)
    {
        sum += (i % 10);
        i /= 10;
    }
    return sum;
}
void init()
{
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i < 100001;i++)
    {
        if(arr[i]==0)
            arr[i] = i + sumof(i);
    }
}
void FindG(int num)
{
    bool flag = false;
    for (int i = 1; i < num;i++)
    {
        if(arr[i]==num)
        {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(flag==false)
    {
        cout << "0" << endl;
    }
}
int main()
{
    int times = 0;
    init();
    cin>>times;
    while(times--)
    {
        int num;
        cin >> num;
        FindG(num);
    }
    return 0;
}