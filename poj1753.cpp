#include<iostream>
using namespace std;
bool pieces[4][4];//black is false,white is true
int mymin = 33;
void turn(int x,int y)
{
    if(x>=0&&x<=3&&y>=0&&y<=3)
        pieces[x][y] = !pieces[x][y];
}
void filp(int s)
{
    int x = s / 4;
    int y = s % 4;
    turn(x, y);
    turn(x + 1, y);
    turn(x - 1, y);
    turn(x, y + 1);
    turn(x, y - 1);
}
bool complete()
{
    int flag = 0;
    for (int i = 0; i < 4;i++)
        for (int j = 0; j < 4;j++)
        {
            if(pieces[i][j]==false)
            {
                flag++;
            }
        }
    return flag%16==0?true:false;
}
void dfs(int s,int time)
{
    if (complete())
    {
        if(time<mymin)
            mymin = time;
        return;
    }
    if(s>=16)
        return;
    dfs(s + 1, time);
    filp(s);
    dfs(s + 1, time + 1);
    filp(s);
}
int main()
{
    char c;
    for(int i=0;i<4;i++)
        for (int j = 0; j < 4;j++)
        {
            cin >> c;
            if(c=='b')
            {
                pieces[i][j] = false;
            }
            else
            {
                pieces[i][j] = true;
            }
        }
    dfs(0, 0);
    if(mymin==33)
        cout<<"Impossible"<<endl;
    else
        cout << mymin << endl;
    return 0;
}