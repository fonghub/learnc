#include <stdio.h>
void main()
{
    int num;
    int *p;
    p = &num;
    num = 100;
    printf("num=%d\n",num);
    printf("num=%d\n",*p);
}