#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
    KeyType key;
    InfoType data;
} RecType;

//排序模板
void SortFunc(RecType R[],int n)
{

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

    SortFunc(R,n);

    printf("排序后：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i].key);
    printf("\n");
    return 0;
}


