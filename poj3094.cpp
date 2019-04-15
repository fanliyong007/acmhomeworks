#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    while(true)
    {
        getline(cin,word);
        if(word=="#")
        {
            break;
        }
        int sum=0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]!=' ')
                sum+=(i+1)*(word[i]-'A'+1);
        }
        cout<<sum<<endl;
    }
    return 0;
}