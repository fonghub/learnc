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

int BinSearch_r(SeqList R,int low,int high,KeyType k);
int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[] = {1,3,9,12,32,41,45,62,75,77},x=62;
    for ( i = 0; i < n; i++)
        R[i].key = a[i];

    result = BinSearch_r(R,0,n-1,x);

    if (result > 0)
        printf("序列中第%d个是%d\n",result,x);
    else
        printf("未找到！\n");

    return 0;
}
//折半查找，递归方式
//前提条件是待查找的序列是有序的
int BinSearch_r(SeqList R,int low,int high,KeyType k)
{
    int mid;
    if (low <= high)
    {
        mid = (low+high)/2;
        if (R[mid].key == k)
            return mid+1;

        if(R[mid].key > k)
            return BinSearch_r(R,low,mid-1,k);
        else
            return BinSearch_r(R,mid+1,high,k);
    }else return 0;
    
}