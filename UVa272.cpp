#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    bool flag = true;
    while(getline(cin,word))
    {
        for (int i = 0; i < word.length();i++)
        {
            if(word[i]=='\"'&&flag)
            {
                printf("``");
                flag = !flag;
            }
            else if(word[i]=='\"'&&!flag)
            {
                printf("''");
                flag = !flag;
            }
            
            else
            {
                printf("%c", word[i]);
            }
            
        }
        printf("\n");
    }
    return 0;
}