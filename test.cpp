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
    vector<Rect> vec;
    Rect rect;
    rect.id=1;
    rect.length=2;
    rect.width=3;
    vec.push_back(rect);
    vector<Rect>::iterator it=vec.begin();
    it++;
    cout<<(*it).id<<' '<<(*it).length<<' '<<(*it).width<<endl;    
    system("pause");
return 0;


}