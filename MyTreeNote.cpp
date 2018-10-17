#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
    int data;
    BinTree Left;
    BinTree Right;
};
//递归的方法
void PreOrderTraveral(BinTree BT)//前序遍历
{
    if(BT)
    {
        printf("%d",BT->data);
        PreOrderTraveral(BT->Left);
        PreOrderTraveral(BT->Right);
    }
}
void InOrderTraveral(BinTree BT)//中序遍历
{
    if(BT)
    {
        PreOrderTraveral(BT->Left);
        printf("%d",BT->data);
        PreOrderTraveral(BT->Right);
    }
}
void PostOrderTraveral(BinTree BT)//后序遍历
{
    if(BT)
    {
        PreOrderTraveral(BT->Left);
        PreOrderTraveral(BT->Right);
        printf("%d",BT->data);
    }
}
//非递归的方法
void PreOrderTraveral2(BinTree BT)//前序遍历
{
    stack<BinTree>tree;
    BinTree T=BT;
    while(T||!tree.empty())
    {
        while (T)/*一直向左并将沿途节点压入堆栈*/
        {
            tree.push(T);
            printf("%5d",T->data);/*(访问）打印节点*/
            T=T->Left;
        }
        if(!tree.empty())
        {
            T=tree.top();
            tree.pop();/*节点弹出堆栈*/
            T=T->Right;/*转向右子树*/
        }
    }
}
void InOrderTraveral2(BinTree BT)//中序遍历
{
    stack<BinTree>tree;
    BinTree T=BT;
    while(T||!tree.empty())
    {
        while (T)/*一直向左并将沿途节点压入堆栈*/
        {
            tree.push(T);
            T=T->Left;
        }
        if(!tree.empty())
        {
            T=tree.top();
            tree.pop();/*节点弹出堆栈*/
            printf("%5d",T->data);/*(访问）打印节点*/
            T=T->Right;/*转向右子树*/
        }
    }
}
void PostOrderTraversal2(BinTree BT)//后序遍历
{
    stack<BinTree>tree;
    BinTree T=BT;
    while(T||!tree.empty())
    {
        while (T)/*一直向左并将沿途节点压入堆栈*/
        {
            tree.push(T);
            T=T->Left;
        }
        if(!tree.empty())
        {
            T=tree.top();
            tree.pop();/*节点弹出堆栈*/
            if(!T->Right)
                printf("%5d",T->data);/*(访问）打印节点*/
            T=T->Right;/*转向右子树*/
        }
    }
}
void LevelOrderTraversal(BinTree BT)//层序遍历，通过队列
{
    queue<BinTree>Q;
    BinTree T;
    if(!BT)
    {
        return;
    }
    Q.push(BT);
    while (!Q.empty())
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
void PreOrderPrintLeaves(BinTree BT)//通过前序遍历输出叶子节点
{
    if(BT)
    {
        if(!BT->Left && !BT->Right)
            printf("%d",BT->data);
        PreOrderTraveral(BT->Left);
        PreOrderTraveral(BT->Right);
    }
}
int PostOrderGetHeight(BinTree BT)
{
    int HL, HR, MaxH;
    if(BT)
    {
        HL = PostOrderGetHeight(BT->Left);//求左子树高度
        HR = PostOrderGetHeight(BT->Right);//求右子树高度
        MaxH = (HL > HR) ? HL : HR;//取左右子树较大的深度
        return (MaxH + 1);//返回树的高度
    }
    else
    {
        return 0;//空树高度为0
    }
}
int main()
{
    return 0;
}
