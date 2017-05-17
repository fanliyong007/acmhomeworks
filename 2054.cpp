#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
void change(char *s)
{
    int len=strlen(s);
    char*p=s+len-1;
    if(strchr(s,'.'))
        while(*p=='0')
            *p--='\0';
    if(*p=='.')
        *p='\0';
}
int main()
{
    char a[100000],b[100000];
    char *a_x,*b_x;
    while(scanf("%s%s",a,b)!=EOF)
    {
        a_x=a;
        b_x=b;
        while(*a_x=='0')
            a_x++;
        while(*b_x=='0')
            b_x++;
        change(a);
        change(b);
        puts(strcmp(a_x,b_x)==0?"YES":"NO");
    }
    return 0;
}