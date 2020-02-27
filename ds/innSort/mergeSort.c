#include <stdio.h>
#include <malloc.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

// 把两个有序的序列合并成一个有序的序列
// @par R   待排序序列
// @par low 待排序序列1首元素
// @par mid 待排序序列1末尾元素
// @par high    待排序序列2末尾元素
void Merge(RecType R[], int low, int mid, int high)
{
    RecType *R1;
    int i = low, j = mid + 1, k = 0;
    R1 = (RecType *)malloc((high - low + 1) * sizeof(RecType));
    while (i <= mid && j <= high)
        if (R[i].key <= R[j].key)
        {
            R1[k] = R[i];
            i++;
            k++;
        }
        else
        {
            R1[k] = R[j];
            j++;
            k++;
        }

    while (i <= mid)
    {
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++)
        R[i] = R1[k];
}

void MergePass(RecType R[], int length, int n)
{
    int i;
    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    if (i + length - 1 < n)
        Merge(R, i, i + length - 1, n - 1);
}

//归并排序
void MergeSort(RecType R[], int n)
{
    int length;
    //确定分组规模
    //第一次 1个/组
    //第二次 2个/组
    //第三次 4个/组
    //第四次 8个/组
    for (length = 1; length < n; length = 2 * length)
        MergePass(R, length, n);
}

int main()
{
    int i, n;
    n = 9;
    RecType R[MaxSize];
    KeyType a[] = {9,8,7,6,5,4,3,2,1};
    // KeyType a[] = {1, 8, 8, 1, 4, 7, 9, 9, 8, 6};
    for (i = 0; i < n; i++)
        R[i].key = a[i];

    printf("排序前：");
    for (i = 0; i < n; i++)
        printf("%d", R[i].key);
    printf("\n");

    MergeSort(R, n);

    printf("排序后：");
    for (i = 0; i < n; i++)
        printf("%d", R[i].key);
    printf("\n");
    return 0;
}