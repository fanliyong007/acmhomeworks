#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        string tmp;
        cin >> tmp;
        int same = 1;
        for (int j = 0; j < tmp.length();j++)
        {
            if(tmp[j]!=tmp[j+1])
            {
                if(same==1)
                    cout << tmp[j];
                else 
                    cout << same << tmp[j];
                same = 1;
            }
            else
            {
                same++;
            }
            
        }
        cout << endl;
    }
    return 0;
}