#include <stdio.h>
//预处理定义常量
#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

void main()
{
    int area;

    area = LENGTH * WIDTH;
    printf("value of area : %d",area);
    printf("%c",NEWLINE);

    //使用const关键字定义常量
    const int length = 10;
    const int width = 5;
    const char newline = '\n';

    area = length * width;
    printf("value of area : %d",area);
    printf("%c",NEWLINE);
}