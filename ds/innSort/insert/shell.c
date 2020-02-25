#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
//排序序列记录类型，包括一个排序关键字，以及记录的其他数据（可选）
typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

//希尔插入排序
void ShellSort(RecType R[],int n)
{
    int gap,i,j;
    RecType tmp;
    //分组间隔初始值为元素数量的一般，即把元素序列分为gap组
    gap = n / 2;
    //每一次循环都把gap减半，知道gap值小于0
    while (gap > 0)
    {
        //以下为直接插入排序的代码
        for ( i = gap; i < n; i++)
        {
            tmp = R[i];
            j = i - gap;
            while (j >= 0 && tmp.key < R[j].key)
            {
                R[j+gap] = R[j];
                j = j - gap;
            }
            R[j+gap] = tmp;
        }
        gap = gap/2;
    }
}

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[] = {9,8,7,6,5,4,3,2,1,0};
    //赋值排序关键字
    for ( i = 0; i < n; i++){
        R[i].key = a[i];
    }
    //排序前输出
    printf("排序前：");
    for ( i = 0; i < n; i++){
        printf("%d",R[i].key);
    }
    printf("\n");
    //排序
    ShellSort(R,n);
    //排序后输出
    printf("排序后：");
    for ( i = 0; i < n; i++){
        printf("%d",R[i].key);
    }
    printf("\n");

    return 0; 
}