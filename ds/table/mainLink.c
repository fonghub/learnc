#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;

void CreateListF(LinkList **L,ElemType a[],int n);
void CreateListR(LinkList *L,ElemType a[],int n);
void DestroyList(LinkList *L);
void DispList(LinkList L);

int main()
{
    LinkList L1;
    int a[8] = {1,3,5,7,9,2,4,6,8};
    CreateListF(&L1,a,8);
    // DispList(L1);
    return 0;
}

void CreateListF(LinkList **L,ElemType a[],int n)
{
    int i;
    LinkList *s;
    *L = (LinkList *)malloc(sizeof(LinkList));
    *L->next = NULL;
    for ( i = 0; i < n; i++)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
} 

void DispList(LinkList L)
{
    while (L.next)
    {
        printf("%d\t",L.data);
    }
    printf("\n");
}