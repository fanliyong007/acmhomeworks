#include<iostream>

using namespace std;
int main(){
	int  a[2701]={0};
	int x,y,z,b,c=0;
	for(int j=2;j<2701;++j){
	  for(int k=2;k<j;++k){
		if(j%k!=0)
		  b++;
	  }
	  if(b==(j-2))
		a[j]=1;
	  b=0;
	}
	while(true){
		cin>>x>>y;
		if(x==0&&y==0)
		  break;
		else{
			for(x;x<=y;++x){
				z=x*x+x+41;
				if(a[z])
					++c;
			}
				if(c>=(y-x+1))
					cout<<"OK"<<endl;
				else
				  cout<<"Sorry"<<endl;
	}
	}
return 0;
}
