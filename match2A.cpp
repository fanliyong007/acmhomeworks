#include<bits/stdc++.h>
using namespace std;
string A = "^__^";
string B = "T.T";
string C = B + A;
int main()
{
    int N = 0;
    for (int i = 0; i < 35;i++)
    {
        A = B;
        B = C;
        C = B + A;
    }
    A.erase(0,A.length());
    B.erase(0,B.length());
    while (cin >> N)
    {
        cout << C[(N-1)%19286969]<<endl;
    }
    return 0;
}