#include<bits/stdc++.h>
using namespace std;
int matrix[108][108];
bool iseven(int x)
{
    return x%2==0?true:false;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int flag=0;
        int x=0,y=0;
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            for(int j=1;j<=n;j++)
            {
                cin>>matrix[i][j];
                tmp+=matrix[i][j];
            }
            matrix[i][n+1]=tmp;
        }
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            for(int j=1;j<=n;j++)
            {
                tmp+=matrix[j][i];
            }
            matrix[n+1][i]=tmp;
        }
        for(int i=1;i<=n;i++)
        {
            if(!iseven(matrix[i][n+1]))
            {
                flag=2;
                for(int j=1;j<=n;j++)
                {
                    if(!iseven(matrix[n+1][j]))
                    {
                        x=i;
                        y=j;
                        flag=1;
                        matrix[i][j]++;
                        matrix[n+1][j]++;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!iseven(matrix[n+1][i]))
            {
                flag=2;
                for(int j=1;j<=n;j++)
                {
                    if(!iseven(matrix[j][n+1]))
                    {
                        x=j;
                        y=i;
                        matrix[j][i]++;
                        matrix[j][n+1]++;
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==0)
        {
            cout<<"OK"<<endl;
        }
        else if(flag==1)
        {
            cout<<"Change bit ("<<x<<","<<y<<")"<<endl;
        }
        else
        {
            cout<<"Corrupt"<<endl;
        }
    }
    return 0;
}