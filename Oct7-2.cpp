#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int main()
{
    LL num[3];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    cout << num[0] << "->" << num[1] << "->" << num[2] << endl;
    system("pause");
    return 0;
}