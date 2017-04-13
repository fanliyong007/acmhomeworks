#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int a,b;
    queue<int>que;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        int n=0;
        que.push(1);
        que.push(1);
        cin>>n;
        int ans=0;
        for(int i=n;i>2;i--)
        {
            int one=que.front();
            cout<<"one: "<<one<<" ";
            que.pop();
            int two=que.front();
            cout<<"two: "<<two<<" ";
            ans=(a*two+b*one)%7;
            cout<<"ans: "<<ans<<endl;
            que.push(ans);
        }
        while(!que.empty())
            que.pop();
        cout<<ans<<endl;

    }
    return 0;
}