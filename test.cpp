#include<bits/stdc++.h>
using namespace std;
class Base
{
public:Base(){}
public:
       virtual void print(){cout<<"Base";}
};
 
class Derived:public Base
{
public:Derived(){}
public:
       void print(){cout<<"Derived";}
};
 
int main()
{
       Base *point=new Derived();
       point->print();
       system("pause");
} 