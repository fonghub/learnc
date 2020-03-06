#include <stdio.h>
#include <stdlib.h>

void generateArr(int **arr,int nums[],int num);

//数组赋值给指针，使用指针来遍历
//关于二级指针，详细看6.c
void main()
{
    int *arr;
    int nums[] = {1,2,3,4};
    int num = 4;
    generateArr(&arr,nums,num);
    for ( int i = 0; i < num; i++)
    {
        printf("%d\t",*(arr+i));
    } 
}

void generateArr(int **arr,int nums[],int num)
{
    *arr = (int *)malloc(sizeof(int)*num);
    for (int i = 0; i < num; i++)
        *(*arr+i) = nums[i];
}