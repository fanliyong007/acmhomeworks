#include<iostream>
#include <vector>   //vector是一个容器，里面可以存放各种类型的数据
using namespace std;
int main()
{
	int a,b,c,s;
	vector <int> num;  //定义一个int类型的容器
	while(1)
	{
		cin>>a;
		b=a%10;
		num.push_back(b);  //首个规律放入容器末位
		c=a%10;
		//找出规律，当有数相同时，说明规律已找齐
        while(1)
		{
			b=b*c%10;//得到新的尾数
			if(b==c)
				break;//新的尾数和原尾数相同，说明所有的规律已找到
			else
				num.push_back(b);//将新的尾数插入到容器末尾
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
