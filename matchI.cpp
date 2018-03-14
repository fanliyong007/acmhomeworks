#include<iostream>
using namespace std;
int main()
{
    string s1, s2;
    while(cin>>s1>>s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        bool flag = false;
        if(len2>len1)
        {
            cout << "no" << endl;
            continue;
        }
        for (int i = 0; i < len1;i++)
        {
            if(s1[i]==s2[0])
            {
                if(i+len2<=len1)
                {
                    if(s1.substr(i,len2).compare(s2)==0)
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if(s1.substr(i,len1).compare(s2.substr(0,len1-i))==0)
                    {
                        if(s1.substr(0,len2-(len1-i)).compare(s2.substr(len1-i,len2))==0)
                        {
                            flag = true;
                            break;
                        }
                    }
                    
                }
            }
        }
        flag == true ? cout << "yes" << endl : cout << "no" << endl;
    }
    return 0;
}