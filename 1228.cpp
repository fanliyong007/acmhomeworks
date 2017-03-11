#include <iostream>
#include <cstring>

using namespace std;
int fun(string x){
	
	if(!x.compare("zero")) return 0;   
    else if(!x.compare("one")) return 1;  
    else if(!x.compare("two")) return 2;  
    else if(!x.compare("three")) return 3;  
    else if(!x.compare("four")) return 4;  
    else if(!x.compare("five")) return 5;  
    else if(!x.compare("six")) return 6;  
    else if(!x.compare("seven")) return 7;  
    else if(!x.compare("eight")) return 8;  
    else if(!x.compare("nine")) return 9; 
    else if(!x.compare("+")) return 10;
    else if(!x.compare("=")) return 11;
		
}
int main(){
	string  a,b,c,d,e,f;
	int x1=0,x2=0,x3=0,x4=0,x5=0,sum=0;
	while(true){
		cin>>a;
		x1=fun(a);
		cin>>b;
		x2=fun(b);
		if(x2==10){
			cin>>c>>d;
			x3=fun(c);
			x4=fun(d);
			if(!(x4==11)){
				cin>>e;
				x5=fun(e);
			}
		}
		else{
			cin>>c;
			x3=fun(c);
			if(x3==10){
				cin>>d>>e;
				x4=fun(d);
				x5=fun(e);
				if(fun(e)!=11)
					cin>>f;
			}
		}
		if(x1==0&&x3==0)
			break;
		else if(x2==10&&x4==11){
			sum=x1+x3;
		}
		else if(x3==10&&x5==11){
			sum=x1*10+x2+x4;
		}
		else if(x3==10&&x5!=11){
			sum=x1*10+x2+x4*10+x5;
		}
		else if(x2==10&&x5==11){
			sum=x1+x3*10+x4;
		}
		cout<<sum<<endl;
		x1=0;x2=0;x3=0;x4=0;x5=0;sum=0;
	}
	return 0;
}