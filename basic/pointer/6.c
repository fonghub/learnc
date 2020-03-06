#include <stdio.h>

void ptop(int num);
void makepoint1(int *num);
void makepoint2(int **num);

//二级指针
int main()
{
    int num = 1000;    //内存中的变量
    // ptop(num);
    int *q = &num;
    //以下输出变量num的值和地址
    printf("*q=%d\n",*q);
    printf("q=%p\n",q);

    makepoint1(q);
    //以下输出的依然是变量num的值和地址
    //证明指针经过函数makepoint1后，并没有改变地址或者内容
    //这是因为参数进入函数后，编译器为参数制作了一个副本参数，函数对副本参数做运算
    //函数makepoint1修改了副本参数的指向，因此对参数没有影响
    //但如果函数修改了副本参数指向的内容，由于副本参数和参数指向同一个内容，比如：*num = a
    //那么对调用者就有影响了
    printf("*q=%d\n",*q);
    printf("q=%p\n",q);

    makepoint2(&q);
    // 通过二级指针，成功修改了指针q的地址和内容
    printf("*q=%d\n",*q);
    printf("q=%p\n",q);
    return 0;
}
//参数为一级指针
void makepoint1(int *num)
{
    int a = 100;
    num = &a;
    //以下输出变量a的值和地址
    printf("num = %d\n",*num);
    printf("num=%p\n",num);
}

//参数为二级指针，几时一级指针的地址
void makepoint2(int **num)
{
    int a = 100;
    //取变量的地址，赋值给一级指针的，区别于：*num = a;
    //注意这里的一级指针保存的是地址，需要使用*才能取出值 *(*num) 或者 **num
    *num = &a;
    //以下输出变量a的值和地址
    printf("num = %d\n",**num);
    printf("num=%p\n",*num);
}

//多级指针
void ptop(int num)
{
    int *p1 = &num;     //一级指针，保存普通类型变量的地址
    int **p2 = &p1;     //二级指针，保存一级指针变量的地址
    int ***p3 = &p2;    //三级指针，保存二级指针变量的地址
    printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);

    printf("*p1=%d,**p2=%d,***p3=%d\n",*p1,**p2,***p3);
}
