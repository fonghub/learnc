#include <stdio.h>

typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

void InsertSort(RecType R[],int n);
void BinInsertSort(RecType R[],int n);
void ShellSort(RecType R[],int n);
void DisRecType(RecType R[],int n);

int main()
{
    int n = 10;
    KeyType a[] = {1,4,6,8,0,2,5,7,9,3};
    RecType R[10];
    for (int i = 0; i < n; i++)
        R[i].key = a[i];
    
    printf("排序前：");
    DisRecType(R,n);

    printf("直接插入排序 ... \n");
    InsertSort(R,n);

    printf("折半插入排序 ... \n");
    BinInsertSort(R,n);

    printf("shell插入排序 ... \n");
    ShellSort(R,n);

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

// 直接插入排序
void InsertSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    for ( i = 1; i < n; i++)
    {
        tmp = R[i];
        j = i - 1;
        while (j >= 0 && tmp.key < R[j].key)
        {
            R[j+1] = R[j];
            j--;
        }    
        R[j+1] = tmp;
    }
}

// 折半插入排序
void BinInsertSort(RecType R[],int n)
{
    int i,j;
    int left,mid,right;
    RecType tmp;
    for ( i = 1; i < n; i++)
    {
        tmp = R[i];
        left = 0;
        right = i-1;
        while (left <= right)
        {
            mid = (left + right)/2;
            if(tmp.key < R[mid].key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        for(j=i-1;j>=right+1;j--)
            R[j+1] = R[j];
        
        R[right+1] = tmp;
    }
}

// shell插入排序
void ShellSort(RecType R[],int n)
{
    int i,j,gap;
    gap = n/2;
    RecType tmp;
    while (gap > 0)
    {
        for(i=gap;i<n;i++)
        {
            tmp = R[i];
            j = i - gap;
            while (j >= 0 && tmp.key < R[j].key)
            {
                R[j+gap] = R[j];
                j -= gap;
            }
            R[j+gap] = tmp;
        }
        gap /=2;
    }
}

