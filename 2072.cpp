#include<iostream>
#include<set>
#include<cstring>
using namespace std;
int main()
{
    string a;
    set<string> words;
    while(true)
    {
        getline(cin,a,'\n');
        if (a == "#")
            break;
        const char *expr = a.c_str();
        char *word = new char[strlen(expr) + 1];
        strcpy(word, expr);    
        const char *space = " ";
        char *p;
        p = strtok(word, space);
        while(p)
        {
            string tmp = p;
            words.insert(tmp);
            // p = strtok(word, space);
            p=strtok(NULL,space);
        }
        cout << words.size() << endl;
        words.clear();
    }
    return 0;
        

}