#include<bits/stdc++.h>
int main()
{
    int t;
    int *p = new int[25];
    p[0] = 0;
    int *pair = new int[25];
    char *S = new char[45];
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int i;
        for (i = 1; i <= n;i++)
            scanf("%d", &p[i]);
        int j = 1, k = 0;
        int cp;
        for (i = 1; i <= n;i++)
        {
            cp = p[i] - p[i - 1];
            for (k = 1; k <= cp;k++)
                S[j++] = '(';
            S[j++] = ')';
        }
        S[j] = '\0';
        n *= 2;
        j = 1;
        for (i = 1; i <= n;i++)
        {
            if(S[i]=='(')
                pair[j++] = i;
            else
            {
                printf("%d", (i - pair[j - 1]+1) / 2);
                j--;
                if(i!=n)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
//My wrong answer program,but the bug I don't konw
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t=0;
//     cin >> t;
//     while(t--)
//     {
//         int n = 0;
//         int g=0;
//         string ss;
//         cin >> n;
//         int *ps = new int[n];
//         string ws;
//         for (int i = 0; i < n;i++)
//         {
//             cin >> ps[i];
//         }
//         for (int i = 0; i < n;i++)
//         {
//             for (g; g < ps[i]; g++)
//             {
//                 ss += '(';
//             }
//             ss += ')';
//         }
//         int z = ss.length();
//         bool *bss = new bool[z];
//         memset(bss, false, z);
//         int x = 0;
//         for (int i = 0; i < z;i++)
//         {
//             if(ss[i]==')')
//             {
//                 int tmp = 0;
//                 for (int j = i - 1; j >= 0;j--)
//                 {
//                     if(ss[j]=='('&&bss[j]==false)
//                     {
//                         tmp++;
//                         bss[j] = true;
//                         ws+= (char)(tmp+'0');
//                         x++;
//                         break;
//                     }
//                     else if(ss[j]=='(')
//                     {
//                         tmp++;
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if(i!=n-1)
//             {
//                 cout << ws[i] << " ";
//             }
//             else
//             {
//                 cout << ws[i] << endl;
//             }
//         }
//     }
//     return 0;
// }