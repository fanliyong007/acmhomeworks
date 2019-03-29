#define debug
#include<bits/stdc++.h>
using namespace std;
struct man
{
    string name;
    int birth;
    string phone;
};
man m[18];
int compare(man a,man b)
{
    return a.birth<b.birth;
}
int main()
{ 
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m[i].name>>m[i].birth>>m[i].phone;
    }
    sort(m,m+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<m[i].name<<" "<<m[i].birth<<" "<<m[i].phone<<endl;
    }
    #ifdef debug
        system("pause");
    #endif
    return 0;
}