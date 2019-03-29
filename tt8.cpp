#define debug
#include<bits/stdc++.h>
using namespace std;
map<string,int>p;
map<string,string>qq;
int main()
{
	int n;
	string cmd,num,pw;
	cin>>n;
	while(n--)
	{
		cin>>cmd>>num>>pw;
		if(cmd=="L")
		{
			if(p[num]==0) 
                cout<<"ERROR: Not Exist"<<endl;
			else 
			{
				if(qq[num]!=pw) 
                    cout<<"ERROR: Wrong PW"<<endl;
				else 
                    cout<<"Login: OK"<<endl;
			}
		}
		else
		{
			if(p[num]==1) 
                cout<<"ERROR: Exist"<<endl;
			else 
			{
				p[num]=1;
				qq[num]=pw;
				cout<<"New: OK"<<endl;
			}
		}
	}
    #ifdef debug
    system("pause");
    #endif
    return 0;
}