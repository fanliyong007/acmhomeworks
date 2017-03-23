#include<iostream>
using namespace std;
int tree1[1001],tree2[1001];
void postorder(int a,int b,int n,int f)
{     
	    if(n==1)	
	    {
	       cout<<tree1[a]<<" ";
	        return ;
	    }
	    else if(n<=0)	
	       return ;
	    int i;	
	    for(i=0;tree1[a]!=tree2[b+i];i++) ;
	    postorder(a+1,b,i,0);	
	    postorder(a+i+1,b+i+1,n-i-1,0);	
	    if(f==1)	
	        cout<<tree1[a];
	    else	
	        cout<<tree1[a]<<" ";
	}
	int main()
	{
	    int n,i;
	    while(cin>>n)
	    {
	        for(i=1;i<=n;i++)
	            cin>>tree1[i];	
	        for(i=1;i<=n;i++)	
	            cin>>tree2[i];
	        postorder(1,1,n,1);
	        cout<<endl;
	    }
	    return 0;
}
