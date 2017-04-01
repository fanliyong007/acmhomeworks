#include<iostream>
using namespace std;
void  hanio(int count,const char* begin,const char* middle,const char* end)
{
    if(count==1)
    {
        cout<<begin<<"->"<<end<<endl;
        return;
    }
    hanio(count-1,begin,end,middle);
    cout<<begin<<"->"<<end<<endl;
    hanio(count-1,middle,begin,end);
    return;
}
int main()
{
    int n=0;
    cin>>n;
    hanio(n,"a","b","c");
    cin>>n;
    return 0;
}