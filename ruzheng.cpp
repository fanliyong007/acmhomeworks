#include<iostream>
using namespace std;
int main(){
	unsigned long  a=17,b=17;
	for(int i=0;i<17;++i){
	
		cout<<a<<"*"<<b<<"="<<a*b<<endl;
		b=a*b;
	}
	return 0;
}
