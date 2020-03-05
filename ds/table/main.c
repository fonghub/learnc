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
} SqList;

void CreateList(SqList *L, ElemType a[], int n);//用数组创建线性表
Bool ListEmpty(SqList L);//判定是否为空表ListEmpty(L)
int ListLength(SqList *L);//求线性表的长度ListLength(L)
void DispList(SqList L);//输出线性表DispList(L)
Bool GetElem(SqList L,int i,ElemType *e);//求某个数据元素值GetElem(L,i,e)
int LocateElem(SqList L, ElemType e);//按元素值查找LocateElem(L,e)
Bool ListInsert(SqList *L,int i,ElemType e);//插入数据元素ListInsert(L,i,e)
Bool ListDelete(SqList *L,int i,ElemType *e);//删除数据元素ListDelete(L,i,e)#endif // LIST_H_INCLUDED

int main()
{
    SqList L,*sq=&L;
    ElemType x[6] = {5, 8, 7, 2, 4, 9};
    CreateList(sq, x, 6);
    DispList(*sq);
    ElemType e;
    GetElem(*sq,2,&e);
    printf("第2个元素:%d\n",e);
    int ind = LocateElem(*sq,9);
    printf("第%d个元素是9\n",ind);
    ListInsert(sq,1,4);
    printf("在第1个位置插入4:\t");
    DispList(*sq);
    ElemType num;
    ListDelete(sq,3,&num);
    printf("删除第3个元素是:%d\n",num);
    return 0;
}

//判定是否为空表ListEmpty(L)
Bool ListEmpty(SqList L)
{
    if(L.length == 0)
        return true;
    return false;
}

//输出线性表DispList(L)
void DispList(SqList L)
{
    int i;
    if (ListEmpty(L))
        return ;
    for (i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

//用数组创建线性表
void CreateList(SqList *L, ElemType a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

//求线性表的长度ListLength(L)
int ListLength(SqList *L)
{
    return (L->length);
}

//求某个数据元素值GetElem(L,i,e)
Bool GetElem(SqList L, int i, ElemType *e)
{
    if (i < 1 || i > L.length)
        return false;
    *e = L.data[i - 1];
    return true;
}

//按元素值查找LocateElem(L,e)
int LocateElem(SqList L, ElemType e)
{
    int i = 0;
    while (i < L.length && L.data[i] != e)
        i++;
    if (i >= L.length)
        return 0;
    else
        return i + 1;
}

//插入数据元素ListInsert(L,i,e)
Bool ListInsert(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return false;               //参数错误时返回false
    i--;                            //将顺序表逻辑序号转化为物理序号
    for (j = L->length; j > i; j--) //将data[i..n]元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e; //插入元素e
    L->length++;    //顺序表长度增1
    return true;    //成功插入返回true
}

//删除数据元素ListDelete(L,i,e)
Bool ListDelete(SqList *L, int i, ElemType *e)
{
    int j;
    if (i < 1 || i > L->length) //参数错误时返回false
        return false;
    i--; //将顺序表逻辑序号转化为物理序号
    *e = L->data[i];
    for (j = i; j < L->length - 1; j++) //将data[i..n-1]元素前移
        L->data[j] = L->data[j + 1];
    L->length--; //顺序表长度减1
    return true; //成功删除返回true
}