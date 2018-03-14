#include<iostream>
using namespace std;
int main()
{
    long long int a, b;
    while (cin>>a>>b)
    {
        (a + b) % 86 == 0 ? cout << "yes" << endl : cout << "no" << endl;
    }
    return 0;
}