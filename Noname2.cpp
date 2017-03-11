#include<iostream>
using namespace std;
int main(){
int a=0,b[6],max=0,min=0,temp=0;
while(true){
	cin>>a;
	while(a!=851742){
		b[0]=a/100000;
		b[1]=a/10000%10;
		b[2]=a/1000%10;
		b[3]=a/100%10;
		b[4]=a/10%10;
		b[5]=a%10;
		for(int i=0;i<5;++i)
			for(int k=i;k<5;++k)
				if(b[i]>b[k+1]){
					temp=b[i];
					b[i]=b[k+1];
					b[k+1]=temp;
				}
	min=b[0]*100000+b[1]*10000+b[2]*1000+b[3]*100+b[4]*10+b[5];
	max=b[5]*100000+b[4]*10000+b[3]*1000+b[2]*100+b[1]*10+b[0];
	a=max-min;
	cout<<max<<"-"<<min<<"="<<a<<endl;
	}
	a=0;
	max=0;
	min=0;
	temp=0;
}

return 0;
}