#include<bits/stdc++.h>
using namespace std;
map<char, int> message;
void init()
{
    message['_'] = 0;
    message['a'] = 1;
    message['b'] = 2;
    message['c'] = 3;
    message['d'] = 4;
    message['e'] = 5;
    message['f'] = 6;
    message['g'] = 7;
    message['h'] = 8;
    message['i'] = 9;
    message['j'] = 10;
    message['k'] = 11;
    message['l'] = 12;
    message['m'] = 13;
    message['n'] = 14;
    message['o'] = 15;
    message['p'] = 16;
    message['q'] = 17;
    message['r'] = 18;
    message['s'] = 19;
    message['t'] = 20;
    message['u'] = 21;
    message['v'] = 22;
    message['w'] = 23;
    message['x'] = 24;
    message['y'] = 25;
    message['z'] = 26;
    message['.'] = 27;

}
int main()
{
    int k = 0;
    const char pt[] = { '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.' };
    init();
    while(cin>>k)
    {
        int pc[78];
        int cc[78];
        string word;
        if(k==0)
            break;
        cin >> word;
        int n = word.length();
        for (int i = 0; i < n;i++)
        {
            cc[i] = message[word[i]];
            if((cc[i] + i)==-1)
            {
                pc[k * i % n] = 27;
            }
            else
            {
                pc[k * i % n] = (cc[i] + i) % 28;
            }
        }
        for (int i = 0; i < n;i++)
        {
            cout << pt[pc[i]];
        }
        cout << endl;
    }
}