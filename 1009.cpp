#include<iostream>
using namespace std;
double javabean(int f[],int j[],int m,int n)
{
        double maxbean=0;
        double bean[n];
        int zf=0,zj=0;
        double zbean=0;
        for(int i=0;i<n;i++)
            bean[i]=f[i]*1.0/j[i];
        for(int i=0;i<n-1;i++)
        {
            for(int k=i;k<n;k++)
            {
                if(bean[i]<bean[k])
                {
                    zbean=bean[i];
                    bean[i]=bean[k];
                    bean[k]=zbean;
                    zf=f[i];
                    f[i]=f[k];
                    f[k]=zf;
                    zj=j[i];
                    j[i]=j[k];
                    j[k]=zj;
                }
            }
        }
        for(int k=0;k<n;k++)
        {
            if(m>=j[k])
            {
                maxbean=maxbean+f[k];
                m=m-j[k];
            }
            else
            {
                maxbean=maxbean+m*bean[k];
                m=0;
            }
        }
        return maxbean;
    }
int main()
{
        int n=0,m=0;
        while(true)
        {
            cin>>m>>n;
            if(m==-1&&n==-1)
                break;
            int f[n];
            int j[n];
            for(int i=0;i<n;i++)
            {
                cin>>f[i];
                cin>>j[i];
            }
            printf("%.3f", javabean(f, j, m, n));
            cout<<endl;
        }
    
    
return 0;  
}