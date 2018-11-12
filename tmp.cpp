#include<bits/stdc++.h>
using namespace std;
int main()
{
    string code[10];
    map<string, int> mp;
    code[0] = "-----";
    code[1] = ".----";
    code[2] = "..---";
    code[3] = "...--";
    code[4] = "....-";
    code[5] = ".....";
    code[6] = "-....";
    code[7] = "--...";
    code[8] = "---..";
    code[9] = "----.";
    mp["AV"] = 1;
    mp["AH"] = 2;
    mp["CH"] = 3;
    mp["EP"] = 4;
    mp["FA"] = 5;
    mp["KC"] = 61;
    mp["HH"] = 62;
    mp["OH"] = 63;
    mp["UH"] = 64;
    mp["MH"] = 65;
    string tmp;
    int x;
    int y;
    int pos;
    while(cin >> tmp >> pos)
    {
        x = pos / 10;
        y = pos % 10;
        if(mp[tmp]<10)
            cout << code[0] << code[mp[tmp]] << code[x] << code[y];
        else
            cout << code[mp[tmp]/10] <<code[mp[tmp]%10] << code[x] << code[y];
        cout << endl;
    }
    return 0;
}