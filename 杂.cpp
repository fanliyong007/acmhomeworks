//atof
功 能： 把字符串转换成浮点数
用 法： double atof(const char *nptr);
头文件：#include <stdlib.h>
//atoi
功 能： Convert string to integer
int atoi (const char * str);
头文件：#include <stdlib.h>
//cin.peeek()
功 能：看一个字符不取走
//freopen与fopen需要头文件stdio.h
C语言中freopen()函数是用来重新定向的，所谓重新定向是给输入和输出的位置重新定向。
原本输入位置是键盘缓存区，输出在屏幕上，用了重新定向后可以将输入位置改变成一个文件，
而输出位置也可以输出到一个文件中，具体代码可以这么写：
freopen ("text.txt","r",stdin); 
freopen ("text1.txt","w",stdout);
这里输入和输出便都在文件中操作了。
可是这样做有一个弊端，就是所有输入输出都将在文件中操作，如何灵活控制呢
？这就要用到fopen()函数了，可以自由在文件输入输出中转换，具体语法是：
FILE *fin,*fout;
fin = fopen("text.txt","rb");  
fout = fopen("text1.txt","wb");  
fscanf (fin,"%d",&amp;x);  
fprintf (fout,"%d",x);  
fclose(fin);  
fclose(fout);
这里函数稍微复杂了些，不过仔细看看也蛮简单的，最重要的是多了文件关闭操作，
这样是为了不持续占用系统资源。在读取、写入操作时用“rb”的原因是为了兼容Linux系统，
只在windows下运行只要“r”即可，同样，scanf和printf函数都要改成fscanf和fprintf，
在前面加上你要输入的文件和输出的文件名,这样就可以有选择性的操作文件了。
//memset()在c++中头文件<memory.h>可用在g++中使用<string.h>或<cstring>
void * memset ( void * ptr, int value, size_t num );
ptr指向要填充的内存块的指针。
Pointer to the block of memory to fill.
value 要设置的值。值传递为int，但函数填充使用此值的无符号的字符转换的内存块.
Value to be set. The value is passed as an int, 
but the function fills the block of memory using the unsigned char conversion of this value.
num要设置的值的字节数.size_t是无符号的整数类型。Number of bytes to be set to the value.
size_t is an unsigned integral type.
%d
读入或输出int变量
%c
读入或输出char变量
%f
读入或输出float变量，输出时保留小数点后面6位
%lf
读入或输出double变量，输出时保留小数点后面6位
%x
以十六进制读入或输出整型变量
%lld
读入或输出long long 变量(64位整数）
%nd（如%4d,%12d）
以n字符宽度输出整数，宽度不足时用空格填充
%0nd（如%04d,%012d）
以n字符宽度输出整数，宽度不足时用0填充
%.nf（如%.4f,%.3f）
输出double或float值，精确到小数点后n位