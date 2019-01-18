#define local
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    string character = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    while (getline(cin,word))
    {
        for (int i = 0; i < word.length();i++)
        {
            if(word[i]==' ')
                printf(" ");
            else
                for (int j = 0; j < character.length();j++)
                {
                    if(word[i]==character[j])
                    {
                        printf("%c", character[j - 1]);
                        break;
                    }
                    else if(word[j]=='`'||word[j]=='Q'||word[j]=='A'||word[j]=='Z')
                    {
                        printf("%c",word[i]);
                        break;
                    }
                }
        }
        printf("\n");
    }
    #ifdef local
    system("pause");
#endif
    return 0;
}