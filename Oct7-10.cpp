#define local
#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
    int data;
    BinTree Left;
    BinTree Right;
};
BinTree root = new TreeNode();
BinTree FindRoot(int *a,int *b,int n)
{
    if(n <= 0) return NULL;
    BinTree tmp = new TreeNode();
    int findroot = a[n - 1];
    int i;
    for(i = 0; i < n; i++) {
        if(b[i] == findroot) {
            break;
        }
    }
    tmp->data = findroot;
    tmp->Left = FindRoot(a, b, i);
    tmp->Right = FindRoot(a + i, b + i + 1, n - i - 1);
    return tmp;
}
void Levelprint()
{
    queue<BinTree> Q;
    Q.push(root);
    while(!Q.empty())
    {
        BinTree T=Q.front();
        Q.pop();
        if(T==root)
            cout << T->data;
        else
            cout << " " << T->data;
        if(T->Left)
            Q.push(T->Left);
        if(T->Right)
            Q.push(T->Right);
    }
}
int main()
{
    int inOrder[38];
    int postOrder[38];
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> postOrder[i];
    }
    for (int i = 0; i < N;i++)
    {
        cin >> inOrder[i];
    }
    root=FindRoot(postOrder, inOrder, N);
    Levelprint();
    cout << endl;
    #ifdef local
    system("pause");
    #endif
    return 0;
}