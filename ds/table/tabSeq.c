#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define true 1
#define false 0

typedef int ElemType;
typedef int Bool;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} tabSeq;


//  初始化一个空的线性表
tabSeq * InitList();
// 创建线性表
void CreateList(tabSeq *L, ElemType a[], int n);
// 判断线性表是否为空
Bool ListEmpty(tabSeq *L);
// 返回线性表的长度
int ListLength(tabSeq *L);
// 输出线性表元素
void DispList(tabSeq *L);
//  返回指定序号的元素
Bool GetElem(tabSeq *L,int i,ElemType *e);
//  返回指定元素的序号
int LocateElem(tabSeq *L, ElemType e);
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

int LocateElem(tabSeq *L, ElemType e)
{
    if (ListEmpty(L)) return -1;
    for(int i=0;i<L->length;i++)
        if(L->data[i] == e) return i+1;

    return -1;
}

Bool GetElem(tabSeq *L,int i,ElemType *e)
{
    i--;
    if (i<0 || i>L->length-1) return false;
    *e = L->data[i];
    return true;
}

void DispList(tabSeq *L)
{
    printf("output elem: ");
    for(int i=0;i<L->length;i++)
        printf("%d\t",L->data[i]);

    printf("\n");
}

int ListLength(tabSeq *L)
{
    return L->length;
}

Bool ListEmpty(tabSeq *L)
{
    return L->length>0?false:true;
}

void CreateList(tabSeq *L, ElemType a[], int n)
{
    for(int i=0;i<n;i++)
        L->data[i] = a[i];
    
    L->length = n;
}

tabSeq* InitList()
{
    tabSeq *tmp = (tabSeq *)malloc(sizeof(tabSeq));
    tmp->length = 0;
    return tmp;
}