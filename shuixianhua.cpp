#include<iostream>
using namespace std;
int main(){
int n,a,b,c,g,ts,e[10];
while(cin>>n>>g){
	ts=0;
	for(;n<=g;++n){
		a=n%10;
		b=(n%100)/10;
		c=n/100;
		
		if(n==(a*a*a+b*b*b+c*c*c)){
			e[ts]=n;
			ts+=1;
		}
	}
	if(ts>0){
		for(int i=0;i<ts;i++){
			if(ts-1==i)
			  cout<<e[i]<<endl;
			else
			  cout<<e[i]<<" ";
		}
	}
	else if(ts==0)
	  cout<<"no"<<endl;

}

return 0;
}
