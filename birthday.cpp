#include<iostream>
#include<set>
#include<cstdlib>
using namespace std;
int man;
bool birth()
{
    set<int>st;
    for(int i=0;i<man;i++)
    {
        st.insert(1+rand()%365);
    }
    return st.size()<man?true:false;
}
int main()
{
    int sum=0;
    cin>>man;
    for(int i=0;i<100000;i++)
        if(birth())
            sum++;
    cout<<sum*1.00/(100000*1.00)*100<<"%"<<endl;
    cin.get();
    return 0;
}