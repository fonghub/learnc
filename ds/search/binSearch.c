#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data; 
} NodeType;
typedef NodeType SeqList[MAXL];

int BinSearch(SeqList R,int n,KeyType k);
int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[] = {1,3,9,12,32,41,45,62,75,77},x=77;
    for ( i = 0; i < n; i++)
        R[i].key = a[i];

    result = BinSearch(R,10,x);

    if (result > 0)
        printf("序列中第%d个是%d\n",result,x);
    else
        printf("未找到！\n");

    return 0;
}
//折半查找
//前提条件是待查找的序列是有序的
int BinSearch(SeqList R,int n,KeyType k)
{
    int low=0,high=n-1,mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (R[mid].key == k)
            return mid+1;

        if(R[mid].key > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
}