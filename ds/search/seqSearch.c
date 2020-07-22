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

int SeqSearch(SeqList R,int n,KeyType k);

//顺序查找
int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[] = {2,3,1,8,5,4,9,0,7,6},x=9;
    for ( i = 0; i < n; i++)
        R[i].key = a[i];

    result = SeqSearch(R,10,x);

    if (result > 0)
        printf("序列中第%d个是%d\n",result,x);
    else
        printf("未找到！\n");

    return 0;
}
//顺序查找
//逐个匹配，找到返回逻辑下标，未找到返回0
int SeqSearch(SeqList R,int n,KeyType k)
{
    int i;
    while (i < n && R[i].key != k)
        i++;

    if (i >= n)
        return 0;
    else
        return i+1;
}