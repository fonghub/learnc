#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define TRUE 1
#define ERROR -1
#define FALSE 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

//初始化
Status initList(SqList *L)
{
    L->length = 0;
    return OK;
}

//长度
Status getListLength(SqList L)
{
    return L.length;
}

//是否为空
Status listEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;  
    return FALSE;
}

//清空表
Status clearList(SqList *L)
{
    L->length = 0;
    return OK;
}

//查找指定下标的元素值，赋值给e
Status getElem(SqList L,int i,ElemType *e)
{
    //下标是否非法
    if (i > L.length || i < 1)
    {
        printf("查找的位置不正确\n");
        return ERROR;
    }
    //是否空表
    if (listEmpty(L))
        return ERROR;

    *e = L.data[i-1];
    return OK;
}

//查找指定元素e的下标值
Status locateElem(SqList L,ElemType e)
{
    int i;
    for ( i = 0; i < L.length-1; i++)
        if (L.data[i] == e)
            return i;
    
    printf("没有查找到元素%d指定的下标\n",e);
    return ERROR;
}

//创建表
Status createList(SqList *L,ElemType a[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
        L->data[i] = a[i];

    L->length = n;
    return OK;
}

//在第i个位置插入新元素e
Status listInsert(SqList *L,int i,ElemType e)
{
    if (L->length >= MaxSize)
    {
        printf("表空间已满\n");
        return FALSE;
    }
    if (i < 1 || i > L->length)
    {
        printf("查找的位置不正确\n");
        return FALSE;
    }
    int j;
    for ( j = L->length-1; j >= i; j--)
        L->data[j] = L->data[j-1];
    
    L->data[i-1] = e;
    L->length++;
    return TRUE;
}

//在第i个位置删除元素，通过e返回
Status deleteList(SqList *L,int i,ElemType *e)
{
    if (listEmpty(*L))
        return ERROR;

    if (i < 1 || i > L->length)
    {
        printf("查找的位置不正确\n");
        return FALSE;
    }

    *e = L->data[i-1];
    for ( ; i < L->length; i++)
        L->data[i-1] = L->data[i];

    L->length--;
    return TRUE;
}

Status listTraverse(SqList L)
{
    int i;
    for ( i = 0; i < L.length; i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
    return OK;
}

int main()
{
    int a[] = {1,3,5,7,9,2,4,6,8,0};
    int n = 10;
    SqList L;
    createList(&L,a,n);
    listTraverse(L);
    int lenght = getListLength(L);
    printf("length=%d\n",lenght);
    int index = locateElem(L,13);
    printf("13的index=%d\n",index);
    int res = listInsert(&L,1,2);
    printf("2的res=%d\n",res);
    return 0;
}
