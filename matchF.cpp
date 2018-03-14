#include<iostream>
#include<cstring>
using namespace std;
struct gamer
{
    string name;
    int time1 = 0;
    int time2 = 0;
    int sumtime = 0;
};
struct gamer man[10000];
int main()
{
    
    while(true)
    {
        int n = 0;
        cin >> n;
        if(n==0)
            break;
        char shit;
        for (int i = 0; i < n;i++)
            cin >> man[i].name >> man[i].time1 >> shit >> man[i].time2;
        for (size_t i = 0; i < n; i++)
        {
            man[i].sumtime = man[i].time1 * 60 + man[i].time2;
        }
        

    }
    return 0;
}