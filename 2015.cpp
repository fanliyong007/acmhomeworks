#include<iostream>
using namespace std;
int main()
{
    int n=0,m=0;
    while(cin>>n>>m)
    {
        int a[n];
        int x=2;
        for(int i=0;i<n;i++)
        {
            a[i]=x;
            x+=2;
        }
        int yu=n%m;
        int y=0;
        int sum=0;
        if(yu==0)
        {
            yu=n/m;
            for(int j=0;j<yu;j++){
                for(int k=0;k<m;k++)
                     sum+=a[k+y];
                y+=m;
                if(j!=(yu-1))
                    cout<<sum/m<<" ";
                else
                    cout<<sum/m;
                sum=0;
            }
            y=0;
        }
        else if(yu==0&&n<m)
        {
            for(int j=0;j<n;j++)
                sum+=a[j];
            cout<<sum/n;
        }
        else
        {
            int exyu=n/m;
            for(int j=0;j<exyu;j++){
                for(int k=0;k<m;k++)
                     sum+=a[k+y];
                y+=m;
                cout<<sum/m<<" ";
                sum=0;
            }
            for(int l=y;l<n;l++)
                sum+=a[l];
            cout<<sum/(n-y);
            y=0;

        }     
        cout<<endl;
    }
    return 0;
}