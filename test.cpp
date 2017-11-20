#include<iostream>
using namespace std;
class Point
{
    private:
        double x,y;
    public:
        Point(){};
        Point(double a,double b)
        {
            x=a;
            y=b;
        }
        void SetXY(double a,double b)
        {
            x=a;
            y=b;
        }
        void Show()
        {
            cout<<"x="<<x<<",y="<<y<<endl;
        }

};
int main()
{
    Point a;
    Point b(18.5,10.6);
    a.SetXY(10.6,18.5);
    a.Show();
    b.Show(); 
    while(true)
    {}
    return 0;
}
