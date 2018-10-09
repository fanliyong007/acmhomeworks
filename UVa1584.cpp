#include<bits/stdc++.h>
using namespace std;
int getsize(string x,int position,int ans)
{
    int len = x.length();
    for (int i = position;i < len+position;i++)
    {
        if(x[i%len]<x[ans+i-position])
        {
            return i;
        }
        if(x[i%len]>x[ans+i-position])
            break;
    }
    return 0;
}
int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        
        string word;
        cin >> word;
        int len = word.length();
        int ans = 0;
        for (int i = 0; i < len;i++)
        {
            if(getsize(word,i,ans))
                ans = i;
        }
        for (int i = ans; i < len+ans;i++)
        {
            cout << word[i%len];
        }
        cout << endl;
    }
    return 0;
}