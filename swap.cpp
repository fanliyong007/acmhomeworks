// 自定义的swap函数是一个老掉牙的问题，而这个问题对于理解指针和内存中的栈是很有帮助的
// 一般自定swap函数是这样的：
// 1.swap函数的功能是实现两个的相互替换
// 2.在main函数中调用swap函数，以实现main栈中两个数的相互替换
void swap1(int x, int y)
{//当swap1传入的是整形变量时，swap1栈中会开辟了2个整形变量副本，
// 当swap1运行结束时，swap1栈会销毁，所以这两个副本也会销毁。
// 这时，swap1里面的任何操作对man函数栈中的a，b是没有任何作用的，所以是不能交换的
 
Int temp;
temp = x;
X = y;
Y = temp;
 
}
void swap2(int *x, int *y)
{//这里边很多人可能就不能理解了！
// 在main栈中，&a指向4的地址，&b指向5的地址，
// Swap2函数在swap2栈中定义了两个整形变量指针x,y;
// 一开始x 指向 4的地址，y指向5的地址,函数运行完最后一步时(swap2栈还没销毁前)，
// x指向5的地址，y指向4的地址，这时*x和*y值交换是成功的。
// 但是这种交换并没有改变main栈中&a和&b的指向，&a依然指向的是4的地址，
// &b依然指向的是5的地址。简单总结一下就是，swap2函数只是交换了x和y的指向的地址，
// 却并没有影响到&a和&b指向的地址
Int *temp;
temp = x;
X = y;
Y = temp;
}
void swap3(int *x, int *y)
{//在main栈中，&a指向4的地址，&b指向5的地址，
// Swap2函数在swap2栈中定义了两个整形变量指针x,y;
// 一开始x 指向 4的地址，y指向5的地址。也就是说&a和x指向同一个地址，
// &b和y指向同一个地址！函数运行完最后一步时(swap2栈还没销毁前)，
// x和y把自己指向的地址的值改变了，
// 这时候的改变就影响到了main栈中&a和&b指向的地址的值，所以交换就成功了
Int temp;
temp = *x;
*x = *y; 
*y = temp;
}
Void swap4(int *x, int *y)
{//这个程序运行时是会报段错误的，
// 因为temp没有初始化指针，但是却马山用了它，这是很危险的
Int *temp;
*temp = *x;
*x = *y;
*y = *temp;
}
Int main(void)
{
Int a = 4;
Int b = 5;
swap1(a, b);
Swap2(&a, &b);
Swap3(&a, &b);
return 0;
}