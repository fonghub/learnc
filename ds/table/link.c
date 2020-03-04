#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;    
} Node;
typedef struct Node *LinkList;

Status getListLength(LinkList L)
{
    int i = 0;
    while (L->next)
    {
        L = L->next;
        i++;
    }
    return i;
}

Status getElem(LinkList L,int i,ElemType *e)
{
    int j = 1;
    LinkList p;
    p = L->next;
    while (p && p->next)
    {
        p = p->next;
        j++;
    }
    if (!p || i > j)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status createListHead(LinkList *L,int n)
{
    LinkList p;
    int i;
    // srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for ( i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return OK;
}

Status createListTail(LinkList *L,int n)
{
    LinkList p,q;
    int i;
    // srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    q = *L;
    for ( i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return OK;
}

Status listTraverse(LinkList L)
{
    if (L->next == NULL)
    {
        printf("链表为空");
    }else
    {
        LinkList p;
        p = L->next;
        while (p != NULL)
        {
           printf("%d ",p->data);
            p = p->next;
        }
        printf("\n"); 
    }
}

Status listInsert(LinkList *L, int i, ElemType e) 
{
    int j = 1;
    LinkList p, s;
    p = *L; 
    while(p && j < i){ //p不为null 
        p = p->next;
        j++;
    }
    if(!p || i < j){    //查找失败
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node)); //生成一个新的节点
    s->data = e;
    s->next = p->next;  //插入新节点 
    p->next = s; 
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j = 1;
    LinkList p, q; 
    p = *L;
    while(p && i > j){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return ERROR;   //查找失败 
    }
    q = p->next;
    *e = q->data;   //保存要删除的数据
    p->next = q->next;  //将q的后继赋值给p的后继
    free(q);    //释放空间 
    return OK; 
} 


//删除所有的节点
Status clearList(LinkList *L) 
{
    LinkList p, q;
    p = (*L)->next;
    while(p){       //循环删除每一个节点 
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;  //头结点 
    return OK;
}

int main(void)
{
    LinkList L;
    createListTail(&L, 10);
    printf("初始化10个元素,分别是: \n"); 
    listTraverse(L);
    ElemType e; 
    getElem(L, 4, &e);
    printf("链表中第4个元素是: %d \n",e); 
    printf("链表的长度是: %d \n",getListLength(L));
    listInsert(&L, 4, 12);
    printf("在链表第4个元素之前插入12 \n"); 
    listTraverse(L);
    ListDelete(&L, 5, &e);
    printf("在链表中删除第5个元素 \n"); 
    listTraverse(L);
    clearList(&L);
    printf("清除链表之后的元素: \n"); 
    listTraverse(L);
    return OK;
}