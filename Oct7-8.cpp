// #define debug
#define LOCAL
#include<bits/stdc++.h>
using namespace std;
const char mCode[]={'1','0','X','9','8','7','6','5','4','3','2'};
const int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
string word[108];
int main()
{
    int n=0;
    bool flag=true;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>word[i];
    }
    for(int j=0;j<n;j++)
    {
        int sum=0;
        bool flag2 = true;
        for(int i=0;i<17;i++)
        {
            if(word[j][i]>'9'&&word[j][i]<'0')
            {
                cout<<word[j]<<endl;
                flag2 = false;
                break;
            }
            sum+=weight[i]*((int)word[j][i]-48);
            #ifdef debug
                cout << "sum" <<sum << endl;
            #endif
        }
        if(mCode[sum%11]!=word[j][17]&&flag2)
        {
            #ifdef debug
                cout << "weight[sum\%11]=" <<weight[sum%11] << endl;
                cout << "word[j][17]=" <<word[j][17] << endl;
            #endif
            flag=false;
            cout<<word[j]<<endl;
        }
    }
    if(flag)
    {
        cout<<"All passed"<<endl;
    }
    #ifdef LOCAL
        system("pause");
    #endif
}