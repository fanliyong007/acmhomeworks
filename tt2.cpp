#define debug
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num=0;
    cin>>num;
    cout<<"2^"<<num<<" = "<<(int)pow(2,num)<<endl;
    #ifdef debug
        system("pause");
    #endif
    return 0;
}