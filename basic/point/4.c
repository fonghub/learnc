#include <stdio.h>
#include <stdlib.h>

void generateArr(int *arr,int nums[],int num)
{
    arr = (int *)malloc(sizeof(int)*num);
    int i;
    for ( i = 0; i < num; i++)
    {
        *(arr+i) = nums[i];
    }
}
void main()
{
    int *arr;
    int nums[] = {1,2,3,4};
    int num = 4;
    // arr = &num;
    generateArr(arr,nums,num);
    for ( int i = 0; i < num; i++)
    {
        printf("%d\t",*(arr+i));
    }
    
}