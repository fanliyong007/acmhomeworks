#include<iostream>
#include<cstring>
#define N 1008
using namespace std;
int a[N];
int b[N];
int num = 0;
string one,two;

void myplus();

int main()
{
    
    cin >> num;
    for (int i = 1; i <= num;i++)
    {
        cin >> one >> two;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0] = one.length();
        b[0] = two.length();
        for (int k = 1; k <= a[0];k++)
            a[k] = one[a[0] - k] - '0';
        for (int k = 1; k <= b[0];k++)
            b[k] = two[b[0] - k] - '0';
        myplus();
        cout << "Case " << i << ":" << endl<< one << " + " << two << " = ";
        for (int j = (a[0]>=b[0]?a[0]:b[0]); j >0 ;j--)
        {
            cout << a[j];
        }
        cout << endl;
    }
    return 0;
}
void myplus()
{
    int i, k;
    k = a[0] >= b[0] ? a[0] : b[0];
    for (i = 1; i <= k;i++)
    {
        a[i + 1] += (a[i] + b[i]) / 10;
        a[i] = (a[i] + b[i]) % 10;
    }
    if(a[k+1]>0)
        a[0] = k + 1;
    else
        a[0] = k;

}