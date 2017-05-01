    #include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<memory.h>
    using namespace std;
    void fun(int x)
    {
        int num[100];
        memset(num,0,sizeof(num));
        if(x==0)
            cout<<"0"<<endl;
        else if(x==1)
            cout<<"4"<<endl;
        else
        { 
            int g=0;
            x++;
            while(x)
            {
                num[g]=x%2;
                x/=2;
                g++;
            }
            for(int i=g-2;i>=0;i--)
            {
                num[i]==1?cout<<"7":cout<<"4";
            }
            cout<<endl;
        }

    }
    int main()
    {
        int n;
        while(cin>>n)
        {
            fun(n);
        }
        return 0;
    }