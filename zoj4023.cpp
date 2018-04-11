#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string f, s;
        cin >> f >> s;
        s[0] = (char)(s[0] - 32);
        cout << s + f << endl;
    }
    return 0;
}