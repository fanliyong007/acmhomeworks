#include <iostream>
using namespace std;
int main()
{
   int i,n,m,s;
   cin>>n;
   for(i=0;i<n;i++)
   {
    s=1;
	cin>>m;
	for(int j=1;j<=m;j++)
	   s*=m%10;
	cout<<s<<endl;
   }
   return 0;
}