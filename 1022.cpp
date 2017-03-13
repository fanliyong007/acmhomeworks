#include<iostream>
#include<stack>
#include<cstring>
using namespace  std;
void fan(string a,string b,int cs)
{
    stack<char>stk(9);
    char* achar=a.c_str();
    char* bchar=b.c_str();
    bool flag1[n];
    bool flag2=true;

//     for(int i=0;i<cs;i++)
//     {   
//         if(i==0)
//             stk.push(achar[0]);
//         if(stk.top()==bchar[i])
//         {
//             stk.pop();
//             flag1[i]=true;
//         }
//         else
//         {
//             stk.push(achar[i])
//             flag1[i]=false;           
//         }
//     }
//     for(int j=n;j>;j--)
//     {
//         if(stk.top==bchar[j])
//             stk.pop();
//         else
//             flag2=false;
//     }
//     if(flag2==true)
//     {
//         cout<<"No."<<endl;
//     }
//     else
//     {
//         cout<<"Yes."<<endl;
//         for(int k=0;k<cs;k++)
//         {
//             if(flag1[k])
//                 cout<<"in"<<endl;
//             else
//                 cout<<"out"<<endl;
//         }        
//     }
// }
int main()
{
    int n;
    string astring;
    string bstring;
    while(cin>>n)
    {
        cin>>astring;
        cin>>bstirng;
        fan(astring,bstring,n);
        cout<<"FINISH"<<endl;
    }
    return 0;
}