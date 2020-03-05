#include <stdio.h>

struct point
{
    int x;
    int y;
};
struct rect{
    struct point pt1;
    struct point pt2;
};
//函数返回值为结构体类型
struct point makepoint(int x,int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
//函数的参数和返回值为结构体类型
struct rect printRect(struct point pt1,struct point pt2)
{
    struct rect screen;
    screen.pt1 = pt1;
    screen.pt2 = pt2;
    return screen;
}

//参数为结构体指针
void printPoint(struct point *pt3)
{
    //调用方式1：结构体变量.成员
    printf("%d,%d\n",(*pt3).x,(*pt3).y);
    //调用方式2：指针->成员
    printf("%d,%d\n",pt3->x,pt3->y);
}

int main()
{
    printf("---------------1-------------------\n");
    int x = 2,y = 2;
    struct point res;
    res = makepoint(x,y);
    printf("%d,%d\n",res.x,res.y);

    //----------------
    printf("---------------2-------------------\n");
    struct point pt1 = makepoint(0,0);
    struct point pt2 = makepoint(2,2);
    struct rect area;
    area = printRect(pt1,pt2);
    printf("%d,%d\n",area.pt1.x,area.pt1.y);
    printf("%d,%d\n",area.pt2.x,area.pt2.y);
    
    //----------------
    printf("---------------3-------------------\n");
    struct point origin = {10,10},*pt3 = &origin;
    printPoint(pt3);
    return 0;
}