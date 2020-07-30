#include <stdio.h>

typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

void DisRecType(RecType R[],int n);
void SelectSort(RecType R[],int n);
void SelectSort_v2(RecType R[],int n);


//  选择排序
int main()
{
    int n = 10;
    KeyType a[] = {1,4,6,8,0,2,5,7,9,3};
    RecType R[10];
    for (int i = 0; i < n; i++)
        R[i].key = a[i];

    printf("排序前：");
    DisRecType(R,n);

    printf("选择排序 ... \n");
    SelectSort(R,n);

    printf("选择排序 改进版... \n");
    SelectSort_v2(R,n);


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

//  选择排序
void SelectSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            //  R[i]的关键值与R[j]的关键值逐个比较，每次把较小的赋值给R[i]
            //  存在交换多次的问题
            if(R[i].key > R[j].key)
            {
                tmp = R[i];
                R[i] = R[j];
                R[j] = tmp;
            }
        }
    }
}

//  选择排序 改进版
void SelectSort_v2(RecType R[],int n)
{
    int i,j,k;
    RecType tmp;
    for(i=0;i<n-1;i++)
    {
        //  默认第一个元素是最小的
        k = i;      
        for(j=i+1;j<n;j++)
            if(R[k].key > R[j].key)
                k = j;
        
        //  最后做一次比较，不相等则互相交换
        if(i != k)
        {
            tmp = R[k];
            R[k] = R[i];
            R[i] = tmp;
        }
    }
}