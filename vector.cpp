C++标准库vector容器 

我们可以将vector看成是数组的升级，是广义上的数组并且数据类型自己定义，数组元素个数不限
vector的定义方式：vector<类型> 变量名
初始化方式：
vector<T> v1        //默认构造函数v1为空
vector<T> v2(v1)  //v2成为v1的副本
vector<T> v3(n,i) //v3含有n个i元素
vector<T> v4(n)   //v4含有初始化的元素的个副本
在第三种初始化方式中有元素个数和元素值确定了一个vector对象，v
ector对象而言它希望达到的目的是动态的分配内存，增加元素，而不是预先确定内存大小
vector对象的操作
v.empty()          //若v为空，返回true,否则返回false
v.size()           //返回v的当前元素个数
v.push_back()      //在v的末尾插入一个元素
v[n]               //访问v中的第n个元素
v1=v2              //将v1中元素替换为v2的元素
==,!=,<,<=,>=,>    //都保留惯有的意义
与string类似的v.size()返回值也是size_type类型的
对vector对象可以采用下表访问的方式vector<int> kk;           kk[n]
for(vector<int>::size_type num=0;num!=10;num++) 
采用!=来作为判定条件是安全的，这个也是c++和c不同之处，没有采取防止溢出<=作为条件
但是下标表示[]仅能提取确实已存在的元素（即可以理解为在数组中不能越界访问一样），
尤其是当刚定义一个vector对象时，默认的对象的元素个数为0，此时的下标访问会出现错误
 一般c++程序员都是用迭代器作为访问容器的工具
vector<T>::iterator v1;
每一个容器都有begin和end函数用来返回迭代器，
begin函数将返回指向第一个元素的迭代器，而end函数则返回指向最后一个元素的后一位的迭代器
可以通过解引用操作符（*）访问迭代器指向的元素，
并且迭代器具有自加功能，就是指向容器中的下一位，由end函数的返回值可知不能对end函数的返回值用*进行访问
vector<T> kk;
for(vector<T>::iterator k=kk.begin();k!=kk.end();k++)
通过如此遍历整个容器,在此处是用!=也是安全的
（其实我们可以将迭代器看成是指针，一类用来遍历vector容器的指针）
函数
表述
c.assign(beg,end)
将[beg; end)区间中的数据赋值给c。
c.assign(n,elem)
将n个elem的拷贝赋值给c。
c.at(idx)
传回索引idx所指的数据，如果idx越界，抛出out_of_range。
c.back()
传回最后一个数据，不检查这个数据是否存在。
c.begin()
传回迭代器重的可一个数据。
c.capacity()
返回容器中数据个数。
c.clear()
移除容器中所有数据。
c.empty()
判断容器是否为空。
c.end()
指向迭代器中的最后一个数据地址。
c.erase(pos)
c.erase(beg,end)
删除pos位置的数据，传回下一个数据的位置。
删除[beg,end)区间的数据，传回下一个数据的位置。
c.front()
传回地一个数据。
get_allocator
使用构造函数返回一个拷贝。
c.insert(pos,elem)
c.insert(pos,n,elem)
c.insert(pos,beg,end)
在pos位置插入一个elem拷贝，传回新数据位置。
在pos位置插入n个elem数据。无返回值。
在pos位置插入在[beg,end)区间的数据。无返回值。
c.max_size()
返回容器中最大数据的数量。
c.pop_back()
删除最后一个数据。
c.push_back(elem)
在尾部加入一个数据。
c.rbegin()
传回一个逆向队列的第一个数据。
c.rend()
传回一个逆向队列的最后一个数据的下一个位置。
c.resize(num)
重新指定队列的长度。
c.reserve()
保留适当的容量。
c.size()
返回容器中实际数据的个数。
c1.swap(c2)
swap(c1,c2)
将c1和c2元素互换。
同上操作。
vector<Elem> c
vector <Elem> c1(c2)
vector <Elem> c(n)
vector <Elem> c(n, elem)
vector <Elem> c(beg,end)
c.~ vector <Elem>()
创建一个空的vector。
复制一个vector。
创建一个vector，含有n个数据，数据均已缺省构造产生。
创建一个含有n个elem拷贝的vector。
创建一个以[beg;end)区间的vector。
销毁所有数据，释放内存。