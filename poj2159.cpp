#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    string one, two;
    int len1 = 0, len2 = 0;
    bool word[108];
    while(cin>>one>>two)
    {
        bool flag = true;
        int num1[27];
        int num2[27];
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        len1 = one.length();
        len2 = two.length();
        if(len1!=len2)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < len1;i++)
        {
            num1[one[i] - 'A']++;
            num2[two[i] - 'A']++;
        }
        sort(num1,num1+27);
        sort(num2,num2+27);
        for (int i = 0; i < 27;i++)
        {
            if(num1[i]!=num2[i])
                flag = false;
        }
        cout << (flag == true ? "YES" : "NO") << endl;
    }
    return 0;
}