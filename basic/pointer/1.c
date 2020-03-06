#include <stdio.h>
void main()
{
    int num;    //内存中的变量
    int *p;     //声明指针，使用*与普通变量区别
    p = &num;   //&符号为取内存中变量的地址，赋值给指针变量
    num = 100;
    printf("num=%d\n",num);
    //p与*p的区别：
    //首先指针是用来保存地址的变量
    //p的值就是一个变量，一个地址，通过格式控制符 %p 可以知道
    //*p是根据p的值，取到地址指向的变量的值，是一个普通类型变量，这里是整型 %d
    printf("*p=%d\n",*p);
    printf("p=%p\n",p);
    int *q;     //声明另一个指针变量
    q = p;      //赋值给另一个指针
    printf("q=%p\n",q);
    printf("*q=%d\n",*q);
}