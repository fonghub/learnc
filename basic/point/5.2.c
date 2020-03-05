#include <stdio.h>
#include <stdlib.h>


void makepoint(int *num)
{
    int a = 100;
    *num = a;
    printf("num = %d\n",*num);
}

int main()
{
    int a=10;
    int *num;
    num = &a;
    makepoint(num);
    printf("num = %d\n",*num);
}