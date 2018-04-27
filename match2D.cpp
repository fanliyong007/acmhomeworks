#include<bits/stdc++.h>
using namespace std;
int num1[10008];
int num2[10008];

int main()
{
    int N = 0;
    int M = 0;
    int max = -1;
    while (cin >> N >> M)
    {
        for (int i = 0; i < N;i++)
            cin >> num1[i];
        for (int i = 0; i < M;i++)
            cin >> num2[i];
        sort(num1, num1 + N);
        sort(num2, num2 + M);
        int min = N < M ? N : M;
        int countx = 0;
        for (int i = 0; i < N;i++)
        {
            for (int j = 0; j < M;j++)
            {
                if(num1[i]==num2[j]&&(num1[i]!=-1))
                {
                    countx++;
                    num1[i] = -1;
                    num2[j] = -1;
                }
            }
        }
        cout << countx << endl;
    }
}