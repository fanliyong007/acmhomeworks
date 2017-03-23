#include<iostream>
#include<set>
#include<cstring>
using namespace std;
int main()
{
    string a;
    set<string>st;
    while(true)
    {
        int flag=0;
        string b="";
        getline(cin,a,'\n');
        if(a=="#")
            break;
        int count=a.length();
        for(int i=0;i<count;i++)
        {
            if(a[i]<=122&&a[i]>=97)
            {  
                if(i==count-1)
                    st.insert(b);  
                b+=a[i];           
            } 
            else //if(b[0]!=' ')
            {
                st.insert(b);
                b="";
            }
        }
        // if(flag==count-1)
        cout<<st.size()<<endl;
        // else
        //     cout<<st.size()+1<<endl;
        st.clear();
    }
    return 0;
}