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
int BinSearch(SeqList R,int n,KeyType k);

// 折半查找 包含递归和非递归方式
int main()
{
    int i,n=11;
    int result;
    SeqList R;
    KeyType a[] = {2,3,10,15,20,25,28,29,30,35,40},x=20;
    for ( i = 0; i < n; i++)
        R[i].key = a[i];

    // result = BinSearch_r(R,0,n-1,x);
    result = BinSearch(R,n,x);

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