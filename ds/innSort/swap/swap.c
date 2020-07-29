#include <stdio.h>

typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

void DisRecType(RecType R[],int n);
void BubbleSort(RecType R[],int n);
void BubbleSort_v2(RecType R[],int n);
void QuickSort(RecType R[],int left,int right);

//  交换排序
int main()
{
    int n = 10;
    KeyType a[] = {1,4,6,8,0,2,5,7,9,3};
    RecType R[10];
    for (int i = 0; i < n; i++)
        R[i].key = a[i];

    printf("排序前：");
    DisRecType(R,n);

    printf("冒泡排序 ... \n");
    BubbleSort(R,n);

    printf("冒泡排序 改进版 ... \n");
    BubbleSort_v2(R,n);

    printf("快速排序 ... \n");
    QuickSort(R,0,n-1);

    printf("排序后：");
    DisRecType(R,n);
}

// 输出序列
void DisRecType(RecType R[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",R[i].key);

    printf("\n");
}

//  冒泡排序
void BubbleSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    //  n个记录，外层循环需要遍历n-1次，最后一个记录自然有序
    for (i = 0; i < n-1; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if (R[j-1].key > R[j].key)
            {
                tmp = R[j-1];
                R[j-1] = R[j];
                R[j] = tmp;
            }
        }
        printf("%d \n",i);
    }
}

//  冒泡排序 改进版
void BubbleSort_v2(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    //  n个记录，外层循环需要遍历n-1次，最后一个记录自然有序
    for (i = 0; i < n-1; i++)
    {
        int flag = 1;
        for (j = n-1; j > i; j--)
        {
            if (R[j-1].key > R[j].key)
            {
                tmp = R[j-1];
                R[j-1] = R[j];
                R[j] = tmp;

                flag = 0;
            }
        }
        printf("%d \n",i);
        if (flag) break;
    }
}

//  快速排序 
void QuickSort(RecType R[],int left,int right)
{
    int i = left;
    int j = right;
    RecType tmp;

    //  至少两个元素参与排序
    if (left >= right) return; 
    
    //  第一个元素最为基准元素
    tmp = R[i];
    while (i < j)
    {
        while (i < j && R[j].key >= tmp.key)
            j--;
        R[i] = R[j];
        
        while (i < j && R[i].key <= tmp.key)
            i++;
        R[j] = R[i];
    }

    //  基准元素找到了正确位置
    R[i] = tmp;
    QuickSort(R,left,i-1);
    QuickSort(R,i+1,right);
}