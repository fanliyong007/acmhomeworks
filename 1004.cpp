#include <iostream>
#include <cstring>
using namespace std;
 string Maxcolour(string ys[],int sl)
    {
        int count=0,maxcount=0;
        string maxcl ="";
        for(int i=0;i<sl;i++)
        {
            for(int k=i+1;k<sl;k++)
            {
                
                if(ys[i]==(ys[k]))
                {
                    count++;
                }
            
            }
            if(count>=maxcount)
            {
                maxcount=count;
                maxcl=ys[i];
            }
            count=0;
                
        }
        return maxcl;
    }
int main(){
        while(true)
        {
            int n;
			cin>>n;
            if(n==0)
                break;
            string colour[n];
            for(int i=0;i<n;i++)
                cin>>colour[i];
            cout<<Maxcolour(colour,n)<<endl;   
		}      
	return 0;
}