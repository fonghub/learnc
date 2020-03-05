#include <stdio.h>

//声明一个结构体，struct为结构体关键字，point为结构体标记，用于为结构体命名
//花括号内是结构体成员，结构体成员可以是普通类型变量，也可以是一个结构体类型变量
//花括号后可以跟一个变量表，表示该结构体类型变量
struct point{
    int x;
    int y;
};
struct rect{
    struct point pt1;
    struct point pt2;
};
int main()
{
    //结构体类型变量
    struct rect screen;
    //结构体类型变量初始化
    struct point pt1 = {0,0};
    struct point pt2 = {2,2};

    //赋值与访问
    //通过 结构变量.成员 的方式访问
    screen.pt1 = pt1;
    screen.pt2 = pt2;
    
    printf("%d,%d\n",screen.pt1.x,screen.pt1.y);
    printf("%d,%d\n",screen.pt2.x,screen.pt2.y);
    
}