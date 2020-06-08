#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int ElemType;
typedef int Bool;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} tabSeq;


//  初始化一个空的链表
// tabSeq * InitList();
// 创建链表
void CreateList(tabSeq *L, ElemType a[], int n);
// 判断链表是否为空
Bool ListEmpty(tabSeq *L);
// 返回链表的长度
int ListLength(tabSeq *L);
// 输出链表元素
void DispList(tabSeq *L);
//  在指定序号位置插入元素
Bool ListInsert(tabSeq *L,int i,ElemType e);
//  在指定序号位置删除元素
Bool ListDelete(tabSeq *L,int i,ElemType *e);

int main()
{
    tabSeq *T;
    T = InitList();
    ElemType x[6] = {1,2,3,4,5,6};
    if (ListEmpty(T)) printf("null\n");
    else printf("not null\n");
    CreateList(T,x,6);
    printf("CreateList\n");
    if (ListEmpty(T)) printf("null\n");
    else printf("not null\n");
    printf("length of list=%d\n",ListLength(T));
    DispList(T);
    int num;
    if(GetElem(T,3,&num)) printf("num = %d\n",num);
    else printf("false\n");
    printf("index of 6  = %d\n",LocateElem(T,6));
    ListInsert(T,1,0);
    DispList(T);
    if(ListDelete(T,1,&num)) printf("num = %d\n",num);
    else printf("false\n");
    DispList(T);
    return 0;
}

Bool ListDelete(tabSeq *L,int i,ElemType *e)
{
    i--;
    if (i<0 || i>L->length-1) return false;
    *e = L->data[i];
    for(int j=i;j<L->length;j++)
        L->data[j] = L->data[j+1];

    L->length--;
    return true;
}

Bool ListInsert(tabSeq *L,int i,ElemType e)
{
    i--;
    if (i<0 || i>L->length) return false;
    for(int j=L->length;j>i;j--)
        L->data[j] = L->data[j-1];

    L->data[i] = e;
    L->length++;
    return true;
}



void DispList(tabSeq *L)
{
    printf("output elem: ");
    while(L != NULL)
    {
        printf("%d\t",L->data);
        L = L->next;
    }
    printf("\n");
}

int ListLength(tabSeq *L)
{
    if(ListEmpty(L)) return 0;
    int i = 0;
    while(L != NULL)
    {
        i++;
        L = L->next;
    }
    return i;
}

Bool ListEmpty(tabSeq *L)
{
    return L==NULL?true:false;
}

void CreateList(tabSeq *L, ElemType a[], int n)
{
    for(int i=0;i<n;i++)
        L->data[i] = a[i];
    
    L->length = n;
}

// tabSeq* InitList()
// {
//     tabSeq *tmp = (tabSeq *)malloc(sizeof(tabSeq));
//     tmp->length = 0;
//     return tmp;
// }