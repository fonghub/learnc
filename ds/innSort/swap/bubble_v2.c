#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
    KeyType key;
    InfoType data;
} RecType;

//冒泡排序v2
//引入标志标量enchange，当元素序列已经是有序了的时候，退出循环
//引入标志标量可以减少不必要的计算
void BubbleSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    int enchange;   //标志变量
    for ( i = 0; i < n-1; i++)
    {
        enchange = 1;   //默认值
        for ( j = n-1; j > i; j--)
        {
            //从最后一个元素开始，与前一个元素比较，把较小的放前面，大的放后面
           if(R[j].key < R[j-1].key)
           {
               tmp = R[j];
               R[j] = R[j-1];
               R[j-1] = tmp;
               enchange = 0;    //当发生位置交换是，修改标志变量的值
           }
        }
        printf("第%d次遍历：",i+1);
        for (int k = 0; k < n; k++)
        {
            printf("%d",R[k].key);
        }
        printf("\n");
        if (enchange == 1) return;  //当标志变量等于默认值时，证明元素位置没有发生交换，表明元素序列是有序的
    }
}

int main()
{
    int i,n;
    n = 10;
    RecType R[MaxSize];
    KeyType a[] = {9,8,7,6,5,4,3,2,1,0};
    // KeyType a[] = {1,8,8,1,4,7,9,9,8,6};
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


