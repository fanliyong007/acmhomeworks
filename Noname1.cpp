#include<iostream>
using namespace std;
int main(){
int a=0,b[4],max=0,min=0,temp=0;
while(true){
	cin>>a;
	while(a!=6174){
		b[0]=a/1000;
		b[1]=a/100%10;
		b[2]=a/10%10;
		b[3]=a%10;
		for(int i=0;i<3;++i)
			for(int k=i;k<3;++k)
				if(b[i]>b[k+1]){
					temp=b[i];
					b[i]=b[k+1];
					b[k+1]=temp;
				}
	min=b[0]*1000+b[1]*100+b[2]*10+b[3];
	max=b[3]*1000+b[2]*100+b[1]*10+b[0];
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