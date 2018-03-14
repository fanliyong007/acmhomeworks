// #include<iostream>
// #include<vector>
// #include<cmath>
// using namespace std;
// vector<int> num;
// void makelucky()
// {
    
// }
// int main()
// {
//     int n;
//     makelucky();
//     while(cin>>n)
//     {
//         if(n==0)
//             break;
        
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
vector<int >vt;
int main(){
	 for(int i=2;i<=40000;i++)
		vt.push_back(i);
	for(vector<int >::iterator it=vt.begin();it!=vt.end();)
	{
		for(vector<int >::iterator it2=it+(*it);it2<vt.end();it2+=(*it))
		{
			it2=vt.erase(it2);//erase 返回的是下一个位置
			it2--;
		}
		it++;
	}
	int t;
	while(cin>>t&&t){
		cout<<vt[t-1]<<endl;
	}  
}