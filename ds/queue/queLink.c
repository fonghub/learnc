#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int Bool;
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} queNode;              //链队数据结点类型定义

typedef struct
{
    queNode *front;
    queNode *rear;
} queLink;                              //链队类型定义


queLink * InitQueue();            //初始化链队
void DestroyQueue(queLink *q);         //销毁链队
Bool QueueEmpty(queLink *q);            //判断链队是否为空
int QueueLength(queLink *q);            //返回队列中数据元素个数
void enQueue(queLink *q, ElemType e);  //入队
Bool deQueue(queLink *q, ElemType *e); //出队

int main()
{
    ElemType e;
    queLink *q;
    printf("(1)初始化链队q\n");
    q = InitQueue();
    printf("(2)依次进链队元素a,b,c\n");
    enQueue(q, 'a');
    enQueue(q, 'b');
    enQueue(q, 'c');
    printf("(3)链队为%s\n", (QueueEmpty(q) == 1 ? "空" : "非空"));
    if (deQueue(q, &e) == 0)
        printf("队空,不能出队\n");
    else
        printf("(4)出队一个元素%c\n", e);
    printf("(5)链队q的元素个数:%d\n", QueueLength(q));
    printf("(6)依次进链队元素d,e,f\n");
    enQueue(q, 'd');
    enQueue(q, 'e');
    enQueue(q, 'f');
    printf("(7)链队q的元素个数:%d\n", QueueLength(q));
    printf("(8)出链队序列:");
    while (!QueueEmpty(q))
    {
        deQueue(q, &e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(9)释放链队\n");
    DestroyQueue(q);
    return 0;
}

//初始化
queLink * InitQueue()
{
    queLink *tmp = (queLink *)malloc(sizeof(queLink));
    //默认头尾指针同时为NULL
    tmp->front = tmp->rear = NULL;
    return tmp;
}

//销毁
void DestroyQueue(queLink *q)
{
    queNode *node = q->front,*tmp;
    while(node != NULL)
    {   
        tmp = node;
        //node节点继续向后移动
        node = node->next;
        free(tmp);
    }
    free(node);
    free(q);
}

//队列是否为空
Bool QueueEmpty(queLink *q)
{
    if(q->rear == NULL)
        return true;
    else 
        return false;
}

//队列长度
int QueueLength(queLink *q)
{
    queNode *node = q->front;
    int n = 0;
    while(node != NULL)
    {
        n++;
        node = node->next;
    }
    return n;
}

// 入队
void enQueue(queLink *q, ElemType e)
{
    queNode *node = (queNode *)malloc(sizeof(queNode));
    node->data = e;
    node->next = NULL;
    //空队列时，把新节点赋值给头尾指针
    //当不为空队列时，把新节点赋值给尾指针的next指针，并把尾指针向后移动
    if(QueueEmpty(q))
        q->front = q->rear = node;
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}

//出队
Bool deQueue(queLink *q, ElemType *e)
{
    queNode *node;
    //空队列时，直接return
    if(QueueEmpty(q))
        return false;
    
    node = q->front;
    //只剩下一个节点时，把头尾指针重新赋值为NULL
    //剩余多个节点时，把头节点响后移动
    if (node->next == NULL)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    
    //节点取值，通过指针传值
    *e = node->data;
    free(node);
    return true;
}
