#include <stdio.h>
void main()
{
    int num = 1000;    //内存中的变量
    int *p1 = &num;     //一级指针，保存普通类型变量的地址
    int **p2 = &p1;     //二级指针，保存一级指针变量的地址
    int ***p3 = &p2;    //三级指针，保存二级指针变量的地址
    printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);

    printf("*p1=%d,**p2=%d,***p3=%d\n",*p1,**p2,***p3);

}