#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

void DisRecType(RecType R[],int n);
void MergeSort(RecType R[],int n);
void MergeSortWithLength(RecType R[],int length,int n);
void Merge(RecType R[],int left,int mid,int right);

//  归并排序
int main()
{
    int n = 10;
    KeyType a[] = {1,4,6,8,0,2,5,7,9,3};
    RecType R[10];
    for (int i = 0; i < n; i++)
        R[i].key = a[i];

    printf("排序前：");
    DisRecType(R,n);

    printf("归并排序 ... \n");
    MergeSort(R,n);

    printf("排序后：");
    DisRecType(R,n);
    return 0;
}

// 输出序列
void DisRecType(RecType R[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",R[i].key);

    printf("\n");
}

void MergeSort(RecType R[],int n)
{
    int length=1;
    while (length < n)
    {
        MergeSortWithLength(R,length,n);
        length *= 2;
    }
}

void MergeSortWithLength(RecType R[],int length,int n)
{
    int i = 0;                  //  第一个有序数组开始下标   
    int k = i + length - 1;     //  第一个有序数组结束下标           
    int j = i + 2*length - 1;   //  第二个有序数据结束下标
    while (j < n)
    {
        Merge(R,i,k,j);
        i = j + 1;
        k = i + length - 1;
        j = i + 2*length - 1;
    }

    //  剩下至少有 length 个记录，才需要整理排序
    if(k < n)
    {
        Merge(R,i,k,n-1);
    }
}

//  合并两个有序数组成一个有序数组
void Merge(RecType R[],int left,int mid,int right)
{
    int i = left,j = mid + 1,k=0;
    RecType *tmp = (RecType *)malloc(sizeof(RecType) * (right-left+1));
    
    while (i <= mid && j <= right)
        if(R[i].key < R[j].key)
            tmp[k++] = R[i++];
        else
            tmp[k++] = R[j++];
    
    while (i <= mid)
        tmp[k++] = R[i++];

    while (j <= right)
        tmp[k++] = R[j++];

    for (int k = 0,i = left; i<=right; i++,k++)
        R[i] = tmp[k]; 
}

