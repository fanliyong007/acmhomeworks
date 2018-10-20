#include<bits/stdc++.h>
using namespace std;
int inOrder[58];
int postOrder[58];
int N;
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
    int data;
    BinTree Left;
    BinTree Right;
};
BinTree root = NULL;
BinTree cur = NULL;
void addNode(int x,bool flag)
{
    BinTree tmp;
    if(!root)
    {
        root->data = x;
        cur = root;
    }
    else
    {
        tmp->data = x;
        if(flag)
        {
            cur->Left = tmp;
            cur = tmp;
        }
        else
        {
            cur->Right = tmp;
            cur = tmp;
        }
        
    }
}
void FindRoot(int begin,int end,bool flag)
{
    if(end<0)
        return;
    for (int i = begin; i < end;i++)
    {
        if(inOrder[i]==postOrder[end])
        {
            addNode(postOrder[end],flag);
            FindRoot()
            FindRoot()
        }
    }
}
void Levelprint()
{
    queue<BinTree> Q;
    Q.push(root);
    BinTree T;
    while(!Q.empty())
    {
        T=Q.front();
        Q.pop();
        printf("%d\n",T->data);
        if(T->Left)
            Q.push(T->Left);
        if(T->Right)
            Q.push(T->Right);
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> postOrder[i];
    }
    for (int i = 0; i < N;i++)
    {
        cin >> inOrder[i];
    }
    FindRoot(0,N,true);
    Levelprint();
    return 0;
}