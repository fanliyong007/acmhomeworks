#define debug
#include<bits/stdc++.h>
using namespace std;
map<char,char>mp;
int main()
{
    mp['A']='Z';
    mp['B']='Y';
    mp['C']='X';
    mp['D']='W';
    mp['E']='V';
    mp['F']='U';
    mp['G']='T';
    mp['H']='S';
    mp['I']='R';
    mp['J']='Q';
    mp['K']='P';
    mp['L']='O';
    mp['M']='N';
    mp['N']='M';
    mp['O']='L';
    mp['P']='K';
    mp['Q']='J';
    mp['R']='I';
    mp['S']='H';
    mp['T']='G';
    mp['U']='F';
    mp['V']='E';
    mp['W']='D';
    mp['X']='C';
    mp['Y']='B';
    mp['Z']='A';
    string word;
    getline(cin,word);
    for(int i=0;i<word.length();i++)
    {
        if(word[i]>='A'&&word[i]<='Z')
        {
            cout<<mp[word[i]];
        }
        else
        {
            cout<<word[i];
        }
    }
    cout<<endl;
    #ifdef debug
        system("pause");
    #endif
    return 0;
}