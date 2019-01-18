#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    int times = 0;
    cin >> times;
    while(times--)
    {
        cin >> word;
        int len = word.length();
        int j;
        for (int i = 1; i <= len;i++)
        {
            if(len%i==0)
            {
                for (j = i; j <= len;j++)
                {
                    if(word[j]!=word[j%i])
                        break;
                }
                if(j==len)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    // system("pause");
    return 0;
}