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
        scanf("%d %d %lf %lf %lf", &data.y, &data.q, &data.e, &data.f, &data.g);
        ans = data.y * (1 + data.e /100*data.q/ 365);
        ans = ans * (1 + data.g / 100 );
        printf("%.1lf\n", ans);
        ans = 0;
        ans = data.y * (1 + data.f/ 100 * (data.q + 365) / 365);
        printf("%.1lf\n", ans);

    }
    return 0;
}