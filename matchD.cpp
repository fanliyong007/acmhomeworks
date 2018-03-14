#include<iostream>
#include<cstdio>
using namespace std;
struct money
{
    int y = 0;
    int q = 0;
    double e = 0;
    double f = 0;
    double g = 0;
};
int main()
{
    int t = 0;
    scanf("%d", &t);
    while(t--)
    {
        struct money data;
        double ans = 0;
        scanf("%d %d %f %f %f", &data.y, &data.q, &data.e, &data.f, &data.g);
        if(data.q<=100)
        {
            ans = data.y + (1 + 1.7 * data.y * data.q / 36500);
        }
        else
        {
            ans = data.y + (1 + 1.7 * data.y * data.q / 36500);
            ans =ans+(data.q-100)
        }
        ans = ans + ans * 3.9 / 100;
        printf("%.1f\n", ans);
        ans = 0;
        ans = data.y * (1 + 3.7 / 100 * (data.q + 365) / 365);
        printf("%.1f\n", ans);

    }
    return 0;
}