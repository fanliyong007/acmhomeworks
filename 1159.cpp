#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[1001][1001];
int main()
{
    string X, Y;
    while(cin>>X>>Y)
    {
        int len1 = X.length();
        int len2 = Y.length();
        for (int i = 0; i <= len1;i++)
            ans[i][0] = 0;
        for (int i = 0; i <= len2;i++)
            ans[0][i] = 0;
        for (int i = 1; i <= len1;i++)
            for (int j = 1; j <= len2;j++)
            {
                if(X[i-1]==Y[j-1])
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                else
                    ans[i][j] = ans[i][j - 1] > ans[i - 1][j] ? ans[i][j - 1] : ans[i - 1][j];
            }
        cout << ans[len1][len2] << endl;
    }
    return 0;
}