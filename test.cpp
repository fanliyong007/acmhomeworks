#define local
#include<bits/stdc++.h>
using namespace std;
int main() {

    string s = "I love you!";
    for( float y = 1.3 ; y >= -1.1 ; y -= 0.06 ){
        int index = 0;
        for( float x = -1.2 ; x <= 1.2 ; x += 0.025 )
            if( pow((x*x+y*y-1.0),3) - x*x*y*y*y <= 0.0 )
                cout<<s[(index++)%s.size()];
            else
                cout<<' ';
        cout<<endl;
    }
    #ifdef local
    system("pause");
    #endif
    return 0;
}
