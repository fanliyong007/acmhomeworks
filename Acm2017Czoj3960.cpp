// 题目大意是一个叫做Kaban的小姑娘在Japari Park这个动物园寻找伙伴。
// 寻找的方法就是她询问每个人几个问题，他们会做出yes或者no的回答。
// 第一行输入测试用例的个数t，第二行第一个是她要寻找的朋友个数n，第二个是她询问的问题的个数q
// 第三行第一个输入的是询问的人的个数c，接下来是他们的名字。
// 接下来q行即第i-th个问题回答yes的人个数m和这m个人的名字
// 接下来n行每行有q个数字，每一行表示她要寻找的朋友每个问题的回答情况，0代表no，1代表yes。
// 对于符合的朋友输出他们的名字，没有符合的朋友则输出“Let's go to the library!!”
// 拿输入事例来说第一行代表有两个事例要检测，第二行第一个数字3表示她要寻找她要寻找3个朋友
// 第二个数字4表示她问了这些人4个问题。第三行第一个数字表示她问了5个人分别是Serval Raccoon Fennec Alpaca Moose
// 第四行表示第一个问题有4个人回答yes分别是Serval Raccoon Alpaca Moose，第五行第六行第七行以此类推。
// 第八行开始到第十行结束这三行表示每个问题的回答情况如第八行表示第一个朋友在第1、2、4这三个问题回答了yes，由此推断
// 第一个朋友是Serval，第九行和第十行没有人符合则输出“Let's go to the library!!”
// 如果有两个及以上符合则也输出“Let's go to the library!!”
// 解体思路：使用一个结构体fri，创建结构体数组Kf，fri有两个属性一个是name即fri的名字，另一个是que即他对每个问题的回答，
// 根据最后几行给出的回答问题情况去比较每个fri的回答，如果符合输出他的名字。
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct fri
{
    string name;
    bool que[22];
};
int main()
{
    int t = 0;//测试用例数
    int n = 0;//需要寻找的朋友个数1<=n&&n<=100
    int q = 0;//问题的个数1<=q&&q<=21
    cin >> t;
    while(t--)
    {
        int num = 0;
        struct fri kf[201];
        int flag = 0;//符合条件朋友的个数
        int g[22];
        string ans;//符合条件朋友的名字
        cin >> n >> q;
        cin >> num;
        for (int i = 0; i < 201;i++)
        {
            memset(kf[i].que, false, sizeof(kf[i].que));
        }//初始化每个friend的问题回答情况
        for (int i = 0; i < num; i++)
        {
            cin >> kf[i].name;
        }
        for (int i = 0; i < q;i++)
        {
            int x = 0;
            cin >> x;
            for (int k = 0; k < x;k++)
            {
                string tmp;
                cin >> tmp;
                for (int j = 0; j < num;j++)
                {
                    if(tmp.compare(kf[j].name)==0)
                    {
                        kf[j].que[i] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n;i++)
        {
            bool flag2 = true;
            for (int j = 0; j < q;j++)
            {
                cin >> g[j];
            }
            for (int j = 0; j < num;j++)
            {
                flag2 = true;
                for (int k = 0; k < q;k++)
                {
                    if((int)kf[j].que[k]!=g[k])
                    {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2)
                {
                    ans = kf[j].name;
                    flag++;
                }
                if(flag>=2)
                    break;
            }
            if(flag>=2||flag==0)
            {
                cout << "Let's go to the library!!" << endl;
            }
            else
            {
                cout << ans << endl;
            }
            flag = 0;
        }
    }
    return 0;
}



// for (int i = 0; i < num;i++)
//         {
//             cout << kf[i].name << " ";
//             for (int j = 0; j < q;j++)
//                 cout << kf[i].que[j] << " ";
//         }