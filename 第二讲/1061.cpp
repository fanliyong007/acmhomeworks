#include<iostream>
#include <vector>
using namespace std;
int main()
{
	int n,a,b,c,s;
	vector <int> num;
	cin>>n;
	for(int i=0;i<n;i++)
	{
    	cin>>a;
		b=a%10;
		num.push_back(b);
		c=a%10;
        while(1)
		{
			b=b*c%10;
			if(b==c)
				break;
			else
				num.push_back(b);
		}
        s=a%num.size();
        if(s==0)  
		    b=num[num.size()-1];
		else
            b=num[s-1];
		cout<<b<<endl;
		num.clear();  
	}
	return 0;
}