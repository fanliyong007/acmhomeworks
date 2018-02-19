#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    
      while(true)
      {
          string a;
          cin >> a;
          cout << a.length()<<endl;
          for (int i = 0; i <= a.length();i++)
              cout << a[i];
      }
    // -2147483648 < 2147483647 ? printf("true") : printf("false");
    // cin.get();
    // return 0;
}