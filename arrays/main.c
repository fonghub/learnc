#include <stdio.h>
#include <string.h>

void optiArr(int num[],int n)
{
    for (int i = 0; i < n; i++)
    {
        num[i] = num[i] + 1;
    }
    
}

void main()
{
    char name[20];
    strcpy(name,"Li Mei");
    printf("name=%s\n",name);

    int num[] = {1,2,3,4,5,6,7,8};
    printf("修改前：");
    for (int i = 0; i < 8; i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");
    optiArr(num,8);
    printf("修改后：");
    for (int i = 0; i < 8; i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");
}