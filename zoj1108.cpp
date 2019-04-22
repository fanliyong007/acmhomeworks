#define local
#include<bits/stdc++.h>
using namespace std;
struct ms
{
    int weight;
    int speed;
    int site;
}mouse[1008];
list<ms>ans;
bool compare(ms a,ms b)
{
    if(a.weight!=b.weight)
        return a.weight<b.weight;
    else
        return a.speed>b.speed;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int weight=0;
    int speed=0;
    int site=1;
    while(cin>>weight>>speed)
    {
        mouse[site].weight=weight;
        mouse[site].speed=speed;
        mouse[site].site=site;
        site++;
    }
    sort(mouse+1,mouse+site,compare);
    for(int i=1;i<site;i++)
    {
        cout<<mouse[i].site<<" "<<mouse[i].weight<<" "<<mouse[i].speed<<endl;
    }

    #ifdef local
    system("pause");
    #endif
    return 0;
} 