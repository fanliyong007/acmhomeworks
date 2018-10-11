#define LOCAL
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    string del;
    set<char> tmp;
    getline(cin,word);
    getline(cin,del);
    for (unsigned int i = 0; i < del.length();i++)
    {
        tmp.insert(del[i]);
    }
    for (unsigned int i = 0; i < word.length();i++)
    {
        set<char>::iterator it = tmp.find(word[i]);
        if(it!=tmp.end())
        {
            word.erase(word.begin()+i);
        }
    }
    cout << word << endl;
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}