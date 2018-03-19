#include<iostream>
#include<cstring>
#include <vector>  
#include <algorithm>  
using namespace std;
struct gamer
{
    string name;
    int time1 = 0;
    int time2 = 0;
    int sumtime = 0;
};

bool comparison(struct gamer a,struct gamer b)
{  
    return a.sumtime<b.sumtime;  
}  

int main()
{
    int time = 1;
    while(true)
    {
        int n = 0;
        cin >> n;
        vector<struct gamer> man(n);
        if(n==0)
            break;
        if(time!=1)
            cout << endl;
        char shit;
        for (int i = 0; i < n;i++)
            cin >> man[i].name >> man[i].time1 >> shit >> man[i].time2;
        for (size_t i = 0; i < n; i++)
        {
            man[i].sumtime = man[i].time1 * 60 + man[i].time2;
        }
        sort(man.begin(),man.end(),comparison);
        cout << "Case #" << time << endl;
        time++;
        for(int i=0;i<n;i++)  
        {  
            if(i>0&&man[i].sumtime==man[i-1].sumtime)
                cout<<man[i].name<<" "<<i<<endl;  
            else
                cout<<man[i].name<<" "<<i+1<<endl;
        }  
    }
    return 0;
}