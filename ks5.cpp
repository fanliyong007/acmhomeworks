#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int ca[100005];
int main(){
    int T;
    //cin>>T;
    scanf("%d",&T);
    while(T--)
    {
        int N,S;
        //cin>>N>>S;
        scanf("%d %d",&N,&S);
        int haha,heihei;
        for(int i=0;i<N;i++)
        {
            //cin>>ca[i];
            scanf("%d",&ca[i]);
        }
        int sum=0;
        bool flag=false;
        bool go=true;
        int Co=1;
        int min=9999999;
        int index = -1;
        for(haha=0;haha<N;haha++)
        {
            sum+=ca[haha];
            Co++;
            if(sum>=S)
            {
                
                if(Co<min)
                {
                    min=Co;
                }
                int pos=haha;
                for(int j=0;j<pos;j++)
                {
                    sum-=ca[j];
                    if(sum>=S)
                    {
                        min--;
                    }
                    else
                    {
                        haha=pos-1;
                        break;
                    }
                }
                Co=1;
                sum=0;
            }
            if(sum<S&&haha==N-1)
            {
                flag=false;
                break;
            }
        }
            if(!go)
                break;
        if(flag)
            printf("%d\n",min);
            //cout<<cs[0]<<endl;
        else
            printf("%d\n",0);
            //cout<<"0"<<endl;
       
    }
}