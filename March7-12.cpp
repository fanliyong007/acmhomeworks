#define debug
#include<iostream>
using namespace std;
int main()
{
    char word;
    cin>>word;
    int asc=(int)word;
    for(int j='A';j<=asc;j++)
    {
        cout.width(40-j+'A');
        for(int i=asc-j;i>0;i--)
        {
            cout<<" ";
        }
        cout<<(char)j;
        for(int l=2*(j-'A')-1;l>0;l--)
        {
            if(j!=asc)
                cout<<" ";
            else
                cout<<(char)asc;
        }
        if(j!='A')
            cout<<(char)j;
        cout<<endl;
    }
    #ifdef debug
    system("pause");
    #endif
    return 0;
}