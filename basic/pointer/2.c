#include <stdio.h>
//两个数交换
//参数声明为两个指针
void swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp; 
}
void main()
{
    int a = 10,b = 20;
    printf("before swap:a=%d,b=%d\n",a,b);
    /*
    int *pa,*pb;
    pa = &a,pb = &b;
    swap(pa,pb);
    */
    //调用方法，实参为指针变量
    //实际上，注释区的作用与下面方法调用的作用一样，由此可知，地址就是指针
    //只不过下面的方法写法更加简洁
    swap(&a,&b);
    printf("after swap:a=%d,b=%d\n",a,b);
}