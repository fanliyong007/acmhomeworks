#include<iostream>
#include <vector>   //vector��һ��������������Դ�Ÿ������͵�����
using namespace std;
int main()
{
	int a,b,c,s;
	vector <int> num;  //����һ��int���͵�����
	while(1)
	{
		cin>>a;
		b=a%10;
		num.push_back(b);  //�׸����ɷ�������ĩλ
		c=a%10;
		//�ҳ����ɣ���������ͬʱ��˵������������
        while(1)
		{
			b=b*c%10;//�õ��µ�β��
			if(b==c)
				break;//�µ�β����ԭβ����ͬ��˵�����еĹ������ҵ�
			else
				num.push_back(b);//���µ�β�����뵽����ĩβ
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
