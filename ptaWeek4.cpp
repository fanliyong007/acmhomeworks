#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k = 0;
    int t = 0;
    cin >> k;
    while(true)
    {
        string tmp;
        cin >> tmp;
        if(tmp=="End")
            break;
        if(t==k)
        {
            t = 0;
            cout << tmp << endl;
        }
        else
        {
            if(tmp=="ChuiZi")
                cout << "Bu" << endl;
            if(tmp=="Bu")
                cout << "JianDao" << endl;
            if(tmp=="JianDao")
                cout << "ChuiZi" << endl;
            t++;
        }
        
    }
    system("pause");
    return 0;
}