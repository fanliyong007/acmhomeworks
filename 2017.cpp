#include<iostream>
#include<cstdio>
using namespace std;
int ct(char a[1000]);
int main(){
char a[1000];
for(int o=0;o<1000;++o)
  a[o]='s';
 int i=0,num,cs;
 cin>>cs;
 for(int j=0;j<cs;j++){
   cin>>a;
   num=ct(a);
   cout<<num<<endl;
   
 }
 return 0;
}
int ct(char a[1000]){
  int sum=0,ts;
  for(int i=0;i<1000;++i){
    ts=(int)a[i];
    if(ts>=48&&ts<=57)
      sum++;
  }
  return sum;
}
