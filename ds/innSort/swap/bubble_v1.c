#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
    KeyType key;
    InfoType data;
} RecType;

//冒泡排序v1
void BubbleSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    //n个元素，需要n-1次循环，每一次循环，至少确定一个元素的正确位置
    for ( i = 0; i < n-1; i++)
    {
        for ( j = n-1; j > i; j--)
        {
            //从最后一个元素开始，与前一个元素比较，把较小的放前面，大的放后面
           if(R[j].key < R[j-1].key)
           {
               tmp = R[j];
               R[j] = R[j-1];
               R[j-1] = tmp;
           }
        }
        printf("第%d次遍历：",i+1);
        for (int k = 0; k < n; k++)
        {
            printf("%d",R[k].key);
        }
        printf("\n");
    }
}

int main()
{
    int i,n;
    n = 10;
    RecType R[MaxSize];
    // KeyType a[] = {9,8,7,6,5,4,3,2,1,0};
    KeyType a[] = {1,8,8,1,4,7,9,9,8,6};
    for ( i = 0; i < n; i++)
        R[i].key = a[i];

    printf("排序前：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i].key);
    printf("\n");

    BubbleSort(R,n);

    printf("排序后：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i].key);
    printf("\n");
    return 0;
}


