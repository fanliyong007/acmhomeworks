#include<iostream>
using namespace std;
int feibo[1008];
int main()
{
    int tmp = 1;
    feibo[1] = 1;
    feibo[2] = 1;
    for (int i = 3; i <= 1002;i++)
    {
        feibo[i] = feibo[i-1]+feibo[i-2];
    }
    int time=0;
    cin >> time;
    while(time--)
    {
        int num = 0;
        cin >> num;
        cout << feibo[num] << endl;
    }
    return 0;
}