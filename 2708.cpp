#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int word[26];
int flag=0;
bool pic[26][217];
char line[73];
void add();
void printpic();
int main()
{
    
    while(gets(line))
    {
        memset(word, 0, sizeof(word));
        add();gets(line);add();gets(line);add();gets(line);add();
        printpic();
        flag=0;
    }
    return 0;
}
void add()
{
    for (int i = 0; line[i]!='\0'; i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            word[line[i] - 'A']++;
            if(flag<word[line[i] - 'A'])
                flag=word[line[i] - 'A'];
        }
    }
}
void printpic()
{
    memset(pic, false, sizeof(pic));
    for (int i = 0; i < 26;i++)
    {
        for (int k = 216; k >216-word[i];k--)
        {
            pic[i][k] = true;
            
        }
    }
    for (int i = 217-flag; i < 217;i++)
    {
        int g=0;
        for(int l=0;l<26;l++)
        {
            if(pic[l][i])
                g=l;
        }
        for (int k = 0; k <= g;k++)
        {
            if(k==0)
            {
                if(pic[k][i])
                {
                    cout << "*";
                }
                else
                {
                    cout<<" ";
                }
            }
            else
           {
                if(pic[k][i])
                {
                    cout << " *";
                }
                else
                {
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    } 
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
}