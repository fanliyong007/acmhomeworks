#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  //greater<int>() Ҫʹ��
using namespace std;
int main()
{
	vector <int> arrin;
	int n,m,num,i;
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
		{ 
			cin>>num;
			arrin.push_back(num);
		}
		sort(arrin.begin(),arrin.end()); //��������  sort(arrin.begin(),arrin.end(),greater<int>())����
		for(i=0;i<m;i++)
			cout<<arrin[i]<<" ";
		cout<<endl;
	}
	return 0;
}