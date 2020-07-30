#include <stdio.h>

typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

void DisRecType(RecType R[],int n);
void HeapSort(RecType R[],int n);
void Heapify(RecType R[],int p,int n);


//  选择排序
int main()
{
    int n = 10;
    KeyType a[] = {1,4,6,8,0,2,5,7,9,3};
    RecType R[10];
    for (int i = 0; i < n; i++)
        R[i+1].key = a[i];

    printf("排序前：");
    DisRecType(R,n);

    printf("堆排序... \n");
    HeapSort(R,n);

    printf("排序后：");
    DisRecType(R,n);
}

// 输出序列
void DisRecType(RecType R[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",R[i+1].key);

    printf("\n");
}

//  堆排序
void HeapSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    for(i=n/2;i>0;i--)
        Heapify(R,i,n);
    
    for(j=n;j>0;j--)
    {
        tmp = R[j];
        R[j] = R[1];
        R[1] = tmp;
        Heapify(R,1,j-1);
    }
}

//  堆化
void Heapify(RecType R[],int p,int n)
{
    int i,j;
    RecType tmp;
    tmp = R[p];
    i = p;
    j = 2 * p;

    // 有至少一个子节点
    while (j <= n)
    {
        //  有两个子节点则找到较大的那个
        if(j < n && R[j].key < R[j+1].key) j++;

        //  父节点比子节点小，则子节点“上浮”到父节点，并且继续堆化
        if(tmp.key < R[j].key)
        {
            R[i] = R[j];
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    R[i] = tmp;
}
