#define debug
#include<bits/stdc++.h>
using namespace std;
bool num[11];
int arr[11];
int main()
{ 
    string phone;
    memset(num,false,sizeof(num));
    memset(arr,-1,sizeof(arr));
    cin>>phone;
    for(int i=0;i<phone.length();i++)
    {
        num[phone[i]-'0']=true;
    }
    int index=0;
    int flag=0;
    for(int i=9;i>=0;i--)
    {
        if(num[i])
        {
            arr[i]=index;
            index++;
            flag=i;
        }
    }
    cout<<"int[] arr = new int[]{";
    for(int i=10;i>=0;i--)
    {
        if(arr[i]!=-1)
        {
            if(i!=flag)
                cout<<i<<",";
            else
                cout<<i; 
        }
    }
    cout<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    for(int i=0;i<phone.length();i++)
    {
        if(i!=phone.length()-1)
            cout<<arr[phone[i]-'0']<<",";
        else
            cout<<arr[phone[i]-'0'];
    }
    cout<<"};"<<endl;
    #ifdef debug
        system("pause");
    #endif
    return 0;
}