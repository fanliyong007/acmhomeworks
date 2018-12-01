#include<bits/stdc++.h>
using namespace std;
struct Book
{
    bool in;
    bool out;
    int begin;
    int end;
};
Book book[1008];
void init()
{
    for (int i = 0; i < 1008;i++)
    {
        book[i].in = false;
        book[i].out = false;
        book[i].begin = 0;
        book[i].end = 0;
    }
}
int main()
{
    int t = 0;
    while (cin >> t && t != 0)
    {
        for (int xxx = 0; xxx < t;xxx++)
        {
            init();
            int booknum;
            char flag;
            char tmp;
            int hour, mins;
            int sumtimes=0, sumcount = 0;
            while(cin>>booknum>>flag>>hour>>tmp>>mins)
            {
                if(booknum==0)
                    break;
                if(flag=='S'&&book[booknum].out==false)
                {
                    book[booknum].begin = hour * 60 + mins;
                    book[booknum].out = true;
                }
                if(flag=='E'&&book[booknum].in==false)
                {
                    book[booknum].end = hour * 60 + mins;
                    book[booknum].in = true;
                }
                if(book[booknum].in==true&&book[booknum].out==true)
                {
                    sumtimes += book[booknum].end - book[booknum].begin;
                    sumcount++;
                    book[booknum].in = false;
                    book[booknum].out = false;
                }
            }
            if(sumcount==0)
                cout << "0"
                    << " "
                    << "0" << endl;
            else
                printf("%d %0.lf\n", sumcount, sumtimes*1.0 / (sumcount*1.0));
        }
    }
    system("pause");
    return 0;
}