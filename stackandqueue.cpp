//队列
#include <queue>
push(x) 将x压入队列的末端
pop() 弹出队列的第一个元素(队顶元素)，注意此函数并不返回任何值
front() 返回第一个元素(队顶元素)
back() 返回最后被压入的元素(队尾元素)
empty() 当队列为空时，返回true
size() 返回队列的长度
1、普通声明
queue<int>q;
2、结构体
struct node
{
    int x, y;
};
queue<node>q;
//优先队列
头文件： 
#include <queue>
empty() 如果队列为空返回真
pop() 删除对顶元素
push() 加入一个元素
size() 返回优先队列中拥有的元素个数
top() 返回优先队列对顶元素
在默认的优先队列中，优先级高的先出队。在默认的int型中先出队的为较大的数。
声明方式： 
1、普通方法：
priority_queue<int>q;
//通过操作，按照元素从大到小的顺序出队

2、自定义优先级： 
struct cmp
{
    operator bool ()(int x, int y)
    {
        return　x > y; // x小的优先级高
      //也可以写成其他方式，如： return p[x] > p[y];表示p[i]小的优先级高
}
};
priority_queue<int, vector<int>, cmp>q;//定义方法
//其中，第二个参数为容器类型。第三个参数为比较函数。
  
3、结构体声明方式：
struct node
{
    int x, y;
    friend bool operator < (node a, node b)
    {
        return a.x > b.x; //结构体中，x小的优先级高
    }
};
priority_queue<node>q;//定义方法
//在该结构中，y为值, x为优先级。
//通过自定义operator<操作符来比较元素中的优先级。
//在重载”<”时，最好不要重载”>”，可能会发生编译错误
//栈
#include <stack>
push(x) 将x加入栈中，即入栈操作
pop() 出栈操作(删除栈顶)，只是出栈，没有返回值
top() 返回第一个元素(栈顶元素)
size() 返回栈中的元素个数
empty() 当栈为空时，返回 true
普通声明
stack<int>s1;//入栈元素为 int 型
stack<string>s2;// 入队元素为string型
stack<node>s3;//入队元素为自定义型