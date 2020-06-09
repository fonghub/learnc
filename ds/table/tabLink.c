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
} tabLink;


//  初始化一个空的链表
tabLink * InitList();
//  创建链表-头插法
void CreateListL(tabLink *L, ElemType a[], int n);
//  创建链表-尾插法
void CreateListR(tabLink *L, ElemType a[], int n);
// 判断链表是否为空
Bool ListEmpty(tabLink *L);
// 返回链表的长度
int ListLength(tabLink *L);
// 输出链表元素
void DispList(tabLink *L);
//  返回指定序号的元素
Bool GetElem(tabLink *L,int i,ElemType *e);
//  返回指定元素的序号
int LocateElem(tabLink *L, ElemType e);
//  在指定序号位置插入元素
Bool ListInsert(tabLink *L,int i,ElemType e);
//  在指定序号位置删除元素
Bool ListDelete(tabLink *L,int i,ElemType *e);
//  销毁线性表
void DestroyList(tabLink *L);

int main()
{
    tabLink *T;
    T = InitList();
    ElemType x[6] = {1,2,3,4,5,6};
    if (ListEmpty(T)) printf("null\n");
    else printf("not null\n");
    CreateListR(T,x,6);
    printf("CreateListR\n");
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
    DestroyList(T);
    return 0;
}

Bool ListDelete(tabLink *L,int i,ElemType *e)
{
    int length = ListLength(L);
    if (i<1 || i>length) return false;
    int j = 0;
    while(j < i-1)
    {
        L = L->next;
        j++;
    }
    tabLink *tmp = L->next;
    L->next = tmp->next;
    *e = tmp->data;
    free(tmp);
    return true;
}

//  在第i个位置，插入节点e
//  关键在于找到第i-1个位置
Bool ListInsert(tabLink *L,int i,ElemType e)
{
    int length = ListLength(L);
    if (i<1 || i>length+1) return false;
    int j = 0;
    while (j < i-1)
    {
        L = L->next;
        j++;
    }
    
    tabLink *tmp = (tabLink *)malloc(sizeof(tabLink));
    tmp->data = e;
    tmp->next = L->next;
    L->next = tmp;
    return true;
}

int LocateElem(tabLink *L, ElemType e)
{
    if (ListEmpty(L)) return -1;
    tabLink *P = L->next;
    int i = 1;
    while(P != NULL)
    {
        if(P->data == e) return i;
        P = P->next;
        i++;
    }
    return -1;
}

Bool GetElem(tabLink *L,int i,ElemType *e)
{
    int length = ListLength(L);
    if (i<1 || i>length) return false;
    int j=0;
    while(j < i)
    {
        L = L->next;
        j++;
    }
    *e = L->data;
    return true;
}

void DispList(tabLink *L)
{
    printf("output elem: ");
    tabLink *P;
    P = L->next;
    while(P != NULL)
    {
        printf("%d\t",P->data);
        P = P->next;
    }
    printf("\n");
}

int ListLength(tabLink *L)
{
    if(ListEmpty(L)) return 0;
    int i = 0;
    while(L->next != NULL)
    {
        i++;
        L = L->next;
    }
    return i;
}

Bool ListEmpty(tabLink *L)
{
    return L->next==NULL?true:false;
}

//  头插法
//  左为头，右为尾
void CreateListL(tabLink *L, ElemType a[], int n)
{
    tabLink *tmp;
    for(int i=0;i<n;i++)
    {
        tmp = (tabLink *)malloc(sizeof(tabLink));
        tmp->data = a[i];
        tmp->next = L->next;
        L->next = tmp;
    }
}

//  尾插法
//  左为头，右为尾
void CreateListR(tabLink *L, ElemType a[], int n)
{
    tabLink *tmp,*p;
    p = L;
    //  p指向链表的尾指针
    while(p->next != NULL) p = p->next;
    for(int i=0;i<n;i++)
    {
        tmp = (tabLink *)malloc(sizeof(tabLink));
        tmp->data = a[i];
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
    }
}

//  初始化链表
//  头节点不存储数据元素，指针域指向第一个节点
tabLink* InitList()
{
    tabLink *tmp = (tabLink *)malloc(sizeof(tabLink));
    tmp->next = NULL;
    return tmp;
}

void DestroyList(tabLink *L)
{
    tabLink *P;
    while(L->next != NULL)
    {
        P = L;
        L = L->next;
        free(P);
    }
    free(L);
}