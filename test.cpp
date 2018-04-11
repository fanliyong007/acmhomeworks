#include<bits/stdc++.h>
using namespace std;

typedef struct rect
{
    int id;
    int length;
    int width;
    bool operator< (const rect &a)  const
    {
        if(id!=a.id)
            return id<a.id;
        else
        {
            if(length!=a.length)
                return length<a.length;
            else
                return width<a.width;
        }
    }
}Rect;

int main()
{
    int x = 'a' - 'A';
    cout <<x << endl;
    system("pause");
    return 0;
}