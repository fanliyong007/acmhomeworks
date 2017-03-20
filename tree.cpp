//c++实现
// 定义
// 二叉树(binary tree)是n(n>=0)个结点的有限集合,该集合为空集合称为空二叉树,或者有一个根结点和两棵互不相交的,分别称为树根结点的左孩子树和右孩子树组成.
// 二叉树的特点
// 每个结点最多有两棵子树,所以二叉树总没有度大于2的结点
// 左子树和右子树是有顺序的,次数不能任意颠倒
// 即使树中某结点只有一棵子树,也要区分是左子树还是右子树
// 特殊的二叉树
// 1. 斜树
// 所有的结点都只有左子树的二叉树称为左斜树; 
// 所有的结点都只有右子树的二叉树称为右斜树; 
// 这两者统称为斜树
// 2. 满二叉树
// 在一棵二叉树中,如果所有的分支节点都存在左子树和右子树, 并且所有的叶子都在同一层上,这样的二叉树称为满二叉树.
// 特点
// 叶子只能出现在最下一层,出现在其它层就不可能达成平衡.
// 非叶子结点的度一定是2.
// 在同样的深度的二叉树中,满二叉树的结点个数最多,叶子数也最多.
// 3. 完全二叉树
// 对一棵具有n个结点的二叉树按层序编号,如果编号为i(1 <= i <= n)的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同,则这棵二叉树称为完全二叉树.
// 满二叉树一定是完全二叉树, 但完全二叉树不一定是满二叉树
// 特点
// 叶子结点只能出现在最下两层.
// 最下层的叶子一定集中在左部连续位置.
// 倒数二层,若有叶子节点,一定在右部连续位置
// 如果结点度为1,则结点只有左孩子,即不存在只有右子树的情况
// 同样结点数的二叉树,完全二叉树的深度最小
// 二叉树的性质
// 性质1
// 在二叉树的第i层上至多有 2^(i-1) 个结点(i>=1)
// 性质2
// 深度为k的二叉树至多有 2^(k)-1 个结点(k>=1)
// 性质3
// 对任何一棵二叉树T,如果其终端结点数的n0, 度为2的结点数为n2 则n0 = n2 + 1 
// 树T结点的总数为n=n0+n1+n2 
// 分支结点数= n - 1 = n1 + 2*n2
// 性质4
// 具有n个结点的完全二叉树的深度为└ log2^n ┘ + 1 (└ x ┘表示不大于x的最大整数)
// 性质5
// 如果对一棵有n个结点的完全二叉树(其深度为 └ log2^n ┘ + 1 )结点按层序编号(从第1层到 └ log2^n ┘ + 1 层,每层从左到右)对任一结点i(1 <= i <=n)有
// 如果i=1,则结点i是二叉树的根,无双亲;如果i>1,则其双亲结点是: └ i/2┘
// 如果2i>n,则结点i无左孩子(结点i为叶子结点);否则器左孩子是结点2i
// 如果2i+1>n,则结点i无右孩子,否则其右孩子是结点2i+1
// 二叉树的存储结构
// 1. 顺序存储结构
// 由于二叉树的严格的定义 可以采用一维数组存储二叉树中的结点,并且结点的存储位置,也就是数组的下标要能提现结点之间的逻辑关系,比如双亲和孩子的关系,左右兄弟的关系等.
// 对于一般的二叉树,尽管层序编号不能反映逻辑关系, 可把不存在的结点设置为^便可.
// 顺序存储结构一般只用于完全二叉树
// 2. 二叉链表
// 二叉树每个结点做多有两个孩子,所以他设计一个数据域和两个指针域是比较自然的想法,我们称这样的链表为二叉链表.
// 左孩子指针域	数据域	  右孩子指针域
// lchild	     data	  rchild
// 遍历二叉树
// 二叉树的遍历是指(traversing binary tree): 从根结点出发,按照某种次序一次访问二叉树中所有的结点,使得每个结点被访问一次且仅被访问一次.
// 1. 前序遍历
// 若二叉树为空,则空操作返回,否则先访问根结点,然后前序遍历左子树,在前序遍历右子树.
// 2. 中序遍历
// 若二叉树为空,则空操作返回,否则先从根结点开始(并不是先访问根结点),中序遍历根结点的左子树,然后访问根结点,最后中序遍历右子树.
// 3. 后序遍历
// 若二叉树为空,则空操作返回,否则先从左到右先叶子后结点的方式遍历访问左右子树,最后是访问根结点.
// 4. 层序遍历
// 若二叉树为空,则空操作返回,否则先从树的第一层,也就是从根结点开始访问,从上而下逐层访问,在同一层中,按从左到右的顺序对结点逐个访问.
// 四种遍历方式,都是把树中的结点变成某种意义的线性序列,给程序的实现带来了好处
#include<iostream.h>
struct tree
{`
    int data;
    tree *left,*right;
};
class Btree
{
    static int n;
    static int m;
public:
    tree *root;
    Btree()
    {
        root=NULL;
    }
    void create_Btree(int);
    void Preorder(tree *);                  //先序遍历
    void inorder(tree *);                   //中序遍历
    void Postorder(tree *);                 //后序遍历
    void display1() {Preorder(root); cout<<endl;}
    void display2() {inorder(root);cout<<endl;}
    void display3() {Postorder(root); cout<<endl;}  
    int count(tree *);                      //计算二叉树的个数
    int findleaf(tree *);                   //求二叉树叶子的个数
    int findnode(tree *);                   //求二叉树中度数为1的结点数量,这是当初考数据结构时候的最后一道题目
};                                          
int Btree::n=0;
int Btree::m=0;
void Btree::create_Btree(int x)
{
    tree *newnode=new tree;
    newnode->data=x;
    newnode->right=newnode->left=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
        tree *back;
        tree *current=root;
        while(current!=NULL)
        {
            back=current;
            if(current->data>x)
                current=current->left;
            else
                current=current->right;
        }
        if(back->data>x)
            back->left=newnode;
        else
            back->right=newnode;
    }
}
int Btree::count(tree *p)
{
    if(p==NULL)
        return 0;
    else
        return count(p->left)+count(p->right)+1;      //这是运用了函数嵌套即递归的方法。
}
void Btree::Preorder(tree *temp)    //这是先序遍历二叉树，采用了递归的方法。
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
void Btree::inorder(tree *temp)      //这是中序遍历二叉树，采用了递归的方法。
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
void Btree::Postorder(tree *temp)     //这是后序遍历二叉树，采用了递归的方法。
{
    if(temp!=NULL)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        cout<<temp->data<<" ";
    }
}
int Btree::findleaf(tree *temp)
{
    if(temp==NULL)return 0;
    else
    {
        if(temp->left==NULL&&temp->right==NULL)return n+=1;
        else
        {
            findleaf(temp->left);
            findleaf(temp->right);
        }
        return n;
    }
}
int Btree::findnode(tree *temp)
{
    if(temp==NULL)return 0;
    else
    {
        if(temp->left!=NULL&&temp->right!=NULL)
        {
            findnode(temp->left);
            findnode(temp->right);
        }
        if(temp->left!=NULL&&temp->right==NULL)
        {
            m+=1;
            findnode(temp->left);
        }
        if(temp->left==NULL&&temp->right!=NULL)
        {
            m+=1;
            findnode(temp->right);
        }
    }
    return m;
}


void main()
{
    Btree A;
    int array[]={7,4,2,3,15,35,6,45,55,20,1,14,56,57,58};
    int k;
    k=sizeof(array)/sizeof(array[0]);
    cout<<"建立排序二叉树顺序: "<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<array[i]<<" ";
        A.create_Btree(array[i]);
    }
    cout<<endl;
    cout<<"二叉树节点个数： "<<A.count(A.root)<<endl;
    cout<<"二叉树叶子个数："<<A.findleaf(A.root)<<endl;
    cout<<"二叉树中度数为1的结点的数量为："<<A.findnode(A.root)<<endl;
    cout<<endl<<"先序遍历序列: "<<endl;
    A.display1();
    cout<<endl<<"中序遍历序列: "<<endl;
    A.display2();
    cout<<endl<<"后序遍历序列: "<<endl;
    A.display3();
}
//c语言实现
/*
    二叉树(binary tree) - 链式存储结构
    实现 二叉树的创建和遍历
    遍历和创建分为三种 前序,中序,后序 
    输入 数据参考 <AB D  C  > 空格是要输入 的 
*/

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0;

typedef int Status;
typedef char TElemType;

//结点定义
typedef struct BiTNode {
    TElemType data;     //数据域 
    struct BiTNode *lchild, *rchild;    //左右孩子指针 
}BiTNode, *BiTree;

//前序遍历(previous order traverse)
void preOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    } 
    printf("%c ", T->data);         //第一步 显示结点数据
    preOrderTraverse(T->lchild);    //第二步 前序遍历左子树 
    preOrderTraverse(T->rchild);        //第三步 前序遍历右子树 
}

//中序遍历(intermediate order traverse)
void inOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    } 
    inOrderTraverse(T->lchild); //第一步 中序遍历左子树 
    printf("%c ", T->data);     //第二步 显示结点数据
    inOrderTraverse(T->rchild); //第三步 中序遍历右子树 
}

//后序遍历(post order traverse)
void postOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    printf("%c ", T->data);
} 

//二叉树的建立  按前序输入二叉树中结点的值 (一个字符)
//' '表示空树 让每个结点确定是否有左右孩子,构造二叉链表表示二叉树 
//如果输入顺序按中序或后序 , 代码的66 67 68行顺序要换一下 ,可以参照遍历的代码这里就不实现了. 
void createBiTree(BiTree *T){
    TElemType e;
    scanf("%c",&e);
    if(e == ' '){
        *T = NULL;
    } 
    else{
        *T = (BiTree)malloc(sizeof(BiTNode));   //生成结点 
        if(!(*T)){  //创建失败 
            printf("结点申请失败\n"); 
            return; 
        }
        (*T)->data = e; //给结点赋值
        createBiTree(&(*T)->lchild); //构造左子树
        createBiTree(&(*T)->rchild);    //构造右子树 
    } 
}

int main(void){
    BiTree T;
    TElemType e;
    int option = 1;
    printf("\n 1.前序创建二叉树\n 2.前序遍历二叉树\n 3.中序遍历二叉树\n 4.后序遍历二叉树\n 0.退出\n");
    while(option){
        scanf("%d", &option);
        fflush(stdin);  //刷新缓冲区 这个是必须的 不然创建的时候输入数据会让你疑惑 
        switch(option){
            case 1:
                createBiTree(&T);
                printf("二叉树创建成功\n");
                break;
            case 2:
                preOrderTraverse(T);
                break;
            case 3:
                inOrderTraverse(T);
                break;
            case 4:
                postOrderTraverse(T);
                break;
            case 0:
                return OK; 
        }
    } 
    return OK;
}
//前序遍历 -- 非递归实现 -- 利用栈实现 
// 对于任一结点T：
// 1)访问结点T，并将结点T入栈;
// 2)判断结点T的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点T，循环至1);若不为空，则将T的左孩子置为当前的结点T;
// 3)直到T为NULL并且栈为空，则遍历结束。
void preOrderTraverse2 (BiTree T){
    stack<BiTree> s;    //初始化栈, 此时s 不为空的... 
    while(T != NULL || !s.empty()){ //栈为null并且当前结点也为null 退出循环 
        while(T != NULL){
            cout << T->data << " ";
            s.push(T);
            T = T->lchild;
        } 
        T = s.top();
        s.pop(); 
        T = T->rchild;
    }
}
//中序遍历 -- 非递归遍历 -- 用栈实现 -- 和前序遍历的顺序略有调整 
// 对于任一结点P，
// 1)若其左孩子不为空，则将T入栈并将P的左孩子置为当前的T，然后对当前结点T再进行相同的处理；
// 2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的T置为栈顶结点的右孩子；
// 3)直到T为NULL并且栈为空则遍历结束
void inOrderTraverse2 (BiTree T){
    stack<BiTree> s;
    while(T != NULL || !s.empty()){ //当前结点为null 并且 栈为null时 退出循环 
        while(T != NULL) {
            s.push(T);
            T = T->lchild;
        }
        T = s.top();
        cout << T->data << " ";
        s.pop();
        T = T->rchild; 
    }
}
//后序遍历(post order traverse) -- 先入右结点,后入左结点 
// 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点T，先将其入栈。如果T不存在左孩子和右孩子，则可以直接访问它；
// 或者T存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
// 若非上述两种情况，则将T的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
void postOrderTraverse2(BiTree T){
    stack<BiTree> s;
    s.push(T);
    BiTree cur; //当前访问的结点
    BiTree pre = NULL; //前一个访问的结点 
    while(!s.empty()){
        cur = s.top();
        //当前结点没有左右结点 或者 孩子结点都已经被访问过了 -- 输出当前的值 
        if((cur->lchild == NULL && cur->rchild == NULL)|| (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->data << " " ;
            s.pop();
            pre = cur;
        }else{
            //先入右结点
            if(cur->rchild != NULL){
                s.push(cur->rchild) ;
            } 
            if(cur->lchild != NULL){
                s.push(cur->lchild);
            }
        }
    }
}
//树的非递归遍历 
#include <iostream>
#include <stack>
#include<stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0;

typedef int Status;
typedef char TElemType;

//结点定义
typedef struct BiTNode {
    TElemType data;     //数据域 
    struct BiTNode *lchild, *rchild;    //左右孩子指针 
}BiTNode, *BiTree;

//前序遍历(previous order traverse) -- 递归实现 
void preOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    } 
    cout << T->data << " ";          //第一步 显示结点数据
    preOrderTraverse(T->lchild);    //第二步 前序遍历左子树 
    preOrderTraverse(T->rchild);        //第三步 前序遍历右子树 
}
//前序遍历 -- 非递归实现 -- 利用栈实现 
void preOrderTraverse2 (BiTree T){
    stack<BiTree> s;    //初始化栈, 此时s 不为空的... 
    while(T != NULL || !s.empty()){ //栈为null并且当前结点也为null 退出循环 
        while(T != NULL){
            cout << T->data << " ";
            s.push(T);
            T = T->lchild;
        } 
        T = s.top();
        s.pop(); 
        T = T->rchild;
    }
}
//中序遍历(intermediate order traverse)
void inOrderTraverse (BiTree T){
    if(T == NULL){
        return;
    } 
    inOrderTraverse(T->lchild); //第一步 中序遍历左子树 
    cout << T->data << " ";     //第二步 显示结点数据
    inOrderTraverse(T->rchild); //第三步 中序遍历右子树 
}

//中序遍历 -- 非递归遍历 -- 用栈实现 -- 和前序遍历的顺序略有调整 
void inOrderTraverse2 (BiTree T){
    stack<BiTree> s;
    while(T != NULL || !s.empty()){ //当前结点为null 并且 栈为null时 退出循环 
        while(T != NULL) {
            s.push(T);
            T = T->lchild;
        }
        T = s.top();
        cout << T->data << " ";
        s.pop();
        T = T->rchild; 
    }
}
//后序遍历(post order traverse)
void postOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    cout << T->data << " ";
} 

//后序遍历(post order traverse) -- 先入右结点,后入左结点 
void postOrderTraverse2(BiTree T){
    stack<BiTree> s;
    s.push(T);
    BiTree cur; //当前访问的结点
    BiTree pre = NULL; //前一个访问的结点 
    while(!s.empty()){
        cur = s.top();
        //当前结点没有左右结点 或者 孩子结点都已经被访问过了 -- 输出当前的值 
        if((cur->lchild == NULL && cur->rchild == NULL)|| (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->data << " " ;
            s.pop();
            pre = cur;
        }else{
            //先入右结点
            if(cur->rchild != NULL){
                s.push(cur->rchild) ;
            } 
            if(cur->lchild != NULL){
                s.push(cur->lchild);
            }
        }
    }
}

//二叉树的建立  按前序输入二叉树中结点的值 (一个字符)
//' '表示空树 让每个结点确定是否有左右孩子,构造二叉链表表示二叉树 
//如果输入顺序按中序或后序 , 代码的66 67 68行顺序要换一下 ,可以参照遍历的代码这里就不实现了. 
void createBiTree(BiTree *T){
    TElemType e;
    scanf("%c",&e);
    if(e == ' '){
        *T = NULL;
    } 
    else{
        *T = (BiTree)malloc(sizeof(BiTNode));   //生成结点 
        if(!(*T)){  //创建失败 
            printf("结点申请失败\n"); 
            return; 
        }
        (*T)->data = e; //给结点赋值
        createBiTree(&(*T)->lchild); //构造左子树
        createBiTree(&(*T)->rchild);    //构造右子树 
    } 
}

int main(void){
    BiTree T = NULL;
    TElemType e;
    int option = 1;
    cout << endl << "1.前序创建二叉树" << endl << "2.前序遍历二叉树" << endl << "3.中序遍历二叉树" << endl << "4.后序遍历二叉树";
    cout << endl << "0.退出" << endl;
    while(option){
        cin >> option;
        fflush(stdin);  //刷新缓冲区 这个是必须的 不然创建的时候输入数据会让你疑惑 
        switch(option){
            case 1:
                createBiTree(&T);
                cout << "二叉树创建成功" << endl;
                break;
            case 2:
                cout << endl << "递归遍历-- 前序遍历  的结果是:" << endl; 
                preOrderTraverse(T);
                cout << endl << "非递归遍历-- 前序遍历  的结果是:" << endl;
                preOrderTraverse2(T);
                cout<< endl; 
                break;
            case 3:
                cout << endl <<  "递归遍历-- 中序遍历  的结果是:" << endl; 
                inOrderTraverse(T);
                cout << endl <<  "非递归遍历-- 中序遍历  的结果是:" << endl;
                inOrderTraverse2(T);
                cout<< endl;
                break;
            case 4:
                cout << endl <<  "递归遍历-- 后序遍历  的结果是:" << endl; 
                postOrderTraverse(T);
                cout << endl <<  "非递归遍历-- 后序遍历  的结果是:" << endl;
                postOrderTraverse2(T);
                cout<< endl;
                break;
            case 0:
                return OK; 
            default:
                cout << endl << "1.前序创建二叉树" << endl << "2.前序遍历二叉树" << endl << "3.中序遍历二叉树" << endl << "4.后序遍历二叉树";
                cout << endl << "0.退出" << endl;
        }
    } 
    return OK;
}