#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
    KeyType key;
    InfoType data;
} RecType;

//快速排序——找到那个多余的元素，替代它
void QuickSort(RecType R[],int s,int t)
{
    int i=s,j=t;
    RecType tmp;
    //至少对两个元素排序
    if (s < t)
    {
        tmp = R[s];
        while (i != j)
        {
            while(i < j && tmp.key <= R[j].key)
                j--;
            R[i] = R[j];

            //while退出循环，是因为i=j，或者第i位元素大于基准值
            //如果是第一种情况，那么 R[j] = R[i]; 是无效的赋值
            //如果是第二种情况，R[i]赋值给R[j]后，R[i]是个多余的元素
            while(i < j && tmp.key >= R[i].key)
                i++;
            R[j] = R[i];
        }

        R[i] = tmp;
        QuickSort(R,s,i-1);
        QuickSort(R,i+1,t);
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

    QuickSort(R,0,n-1);

    printf("排序后：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i].key);
    printf("\n");
    return 0;
}


