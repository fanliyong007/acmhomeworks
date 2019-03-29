#define debug
#include<iostream>
using namespace std;
int main()
{
    int y,m,d;
    char tmp;
    cin>>m>>tmp>>d>>tmp>>y;
    printf("%d-%02d-%02d\n",y,m,d);
    #ifdef debug
    system("pause");
    #endif
    return 0;
}