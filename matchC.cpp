// b is ' ', q is ',', t is '!', m is l, i is e, c is a, a is c, e is i, l is m.
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    map<char,char> mp;
    mp['b']= ' ';
    mp['q']= ',';
    mp['t']= '!';
    mp['m']= 'l';
    mp['i']= 'e';
    mp['c']= 'a';
    mp['a']= 'c';
    mp['e']= 'i';
    mp['l']= 'm';
    // mp['0']= '0';
    string word;
    while(cin>>word)
    {
        for (int i = 0; i < word.length();i++)
        {
            map<char, char>::iterator q = mp.find(word[i]);
            if(!(q==mp.end()))
            {
                cout << mp[word[i]];
            }
            else
            {
                cout << word[i];
            }
        }
        cout << endl;
    }
    return 0;
}