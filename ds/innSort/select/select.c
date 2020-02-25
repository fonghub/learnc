#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
    KeyType key;
    InfoType data;
} RecType;

void SelectSort(RecType R[],int n)
{
    int i,j,k,l;
    RecType tmp;
    for(i=0;i<n-1;i++)
    {
        k = i;  //k用来保存当层循环最小值的下表，默认是第一个元素
        //j从第2个元素开始至最后一个元素
        //寻找比第k个元素还小的元素
        for(j=i+1;j<n;j++)
            if(R[j].key < R[k].key)
                k = j;
        if (k != i)
        {
            tmp = R[i];
            R[i] = R[k];
            R[k] = tmp;
        }
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

    SelectSort(R,n);

    printf("排序后：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i].key);
    printf("\n");
    return 0;
}


