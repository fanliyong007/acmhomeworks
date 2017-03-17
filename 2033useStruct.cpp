#include <iostream>  
using namespace std;  
typedef struct time{  
    int h;  
    int m;  
    int s;  
}T;  
  
int main() {  
    int count;  
    cin>>count;  
    for(int i=0;i<count;i++){  
        T a,b;  
        T result;  
        cin>>a.h>>a.m>>a.s;  
        cin>>b.h>>b.m>>b.s;  
        result.s = (a.s+b.s)%60;  
        result.m = (a.m+b.m)%60+(a.s+b.s)/60;  
  
        result.h = (a.h+b.h)+(a.m+b.m)/60;  
        cout<<result.h<<" "<<result.m<<" "<<result.s<<endl;  
    }  
  
    return 0;  
}  