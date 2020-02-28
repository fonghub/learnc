#include <stdio.h>
#define MaxSize 20
#define MaxNum 10
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

//计数排序
//把待排序序列的数量，保存到一个数据里面，按照元素的值作为数组的下面
//遍历数组，输出数组值大于0的下标
void CountSort(RecType R[], int n)
{
    int i, j, k = 0;
    //定义一个比较大的数组
    int c[MaxNum] = {0};

    //把待排序序列元素数量，保存到数组
    //元素值作为数组下标
    for (i = 0; i < n; i++)
        c[R[i].key]++;

    //遍历数组
    //把值大于0的数组下标输出
    for (j = 0; j < MaxNum; j++)
        for (i = 1; i <= c[j]; i++)
            R[k++].key = j;
}

int main()
{
    int i, n = 10;
    RecType R[MaxSize];
    // KeyType a[] = {9,8,7,6,5,4,3,2,1,0};
    KeyType a[] = {1, 8, 8, 1, 4, 7, 9, 9, 8, 6};
    for (i = 0; i < n; i++)
        R[i].key = a[i];

    printf("排序前：");
    for (i = 0; i < n; i++)
        printf("%d", R[i].key);
    printf("\n");

    CountSort(R, n);

    printf("排序后：");
    for (i = 0; i < n; i++)
        printf("%d", R[i].key);
    printf("\n");
    return 0;
}