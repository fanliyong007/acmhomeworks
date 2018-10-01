#include<iostream>
using namespace std;
int Min = 0, Max = 0;
int arr[12];
void Read()
{
    for (int n = 1; n <= 10;n++)
    {
        cin >> arr[n];
        if(arr[n]>=Max)
            Max = arr[n];
        if(arr[n]<=Min)
            Min = arr[n];
    }
}
void Do()
{
    int first = arr[1];
    int end = arr[10];
    for (int i = 1; i <= 10;i++)
    {
        if(arr[i]==Max)
            arr[i] = end;
        if(arr[i]==Min)
            arr[i] = first;
    }
    arr[1] = Min;
    arr[10] = Max;
}
void Out()
{
    for (int i = 1; i <= 10;i++)
        cout << arr[i] << " ";
}
int main()
{
    Min = 999999999;
    Max = -999999999;
    Read();
    Do();
    Out();
    system("pause");
    return 0;
}