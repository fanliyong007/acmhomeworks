//解题思路：该题是输入一个数，对输入的一个数进行连乘，有多少个就乘多少次，输出最后乘积的末位。
//因为输入的数可以很大，所以保留是不可能的
//要求输出是末位的数，而末位数只和每次相乘的末位有关，但如果采用末位数相乘余数继续乘原来的数，结果可以得到，但会导致超时
//正确思路：找出相乘后末位数的变化规律，保存，然后利用乘的次数对应规律得出结果
#include<iostream>
#include <vector>   //vector是一个容器，里面可以存放各种类型的数据
using namespace std;
int main()
{
	int m,n,b,c,s;
	vector <int> num;  //定义一个int类型的容器
	while(cin>>m>>n&&(m!=0||n!=0))
	{
		b=m%1000;
		num.push_back(b);  //首个规律放入容器末位
		c=m%1000;
		//找出规律，当有数相同时，说明规律已找齐
        for(int i=1;i<n;i++)
		{
			b=b*c%1000;//得到新的尾数
			if(b==c)
				break;//新的尾数和原尾数相同，说明所有的规律已找到
			else
				num.push_back(b);//将新的尾数插入到容器末尾
		}
        s=n%num.size();//找出容器中的元素个数,求余
        if(s==0)  //vector和数组一样，起始是0，余数为0，说明是最后一个，否则就是个数减1的位置那个
		    b=num[num.size()-1];
		else
            b=num[s-1];
		cout<<b<<endl;
		num.clear();   //清空容器，可以进行下一个的计算
	}
	return 0;
}