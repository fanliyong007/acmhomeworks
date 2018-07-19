#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Q1, Q2, D, A, t, s, R, u1, u2, lamda1, lamda2, T1, T2, Tg;
    cout << "please write Q1, Q2, D, A, t, s, R" << endl;
    lamda1 = rand();
    lamda2 = rand();
    T1 = rand();
    T2 = rand();
    Tg = rand();
    cin >> Q1 >> Q2 >> D >> A >> t >> s >> R;
    while(t!=Tg)
    {
        t++;
        u1 = rand();
        if(u1<=lamda1)
            Q1++;
        u2 = rand();
        if(u2<=lamda2)
            Q2++;
        if(t>=R)
        {
            s = 0;
            if(Q1>0)
            {
                Q1--;
                A++;
                s = 1;
                R = t + T1;
                cout << Q1 << Q2 << D << A << t << s << R << endl;
            }
            else
            {
                if(Q2>0)
                {
                    Q2--;
                    D++;
                    s = 2;
                    R = t + T2;
                    cout << Q1 << Q2 << D << A << t << s << R << endl;
                }
                else
                {
                    cout << Q1 << Q2 << D << A << t << s << R << endl;
                }
            }
        }
        else
        {
            cout << Q1 << Q2 << D << A << t << s << R << endl;
        }
    }
} 