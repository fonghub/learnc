#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MaxSize 5

typedef int Bool;
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;        //  队首和队尾指针
} queCyc;

//  初始化循环队列
queCyc * InitQueue();            
//  销毁循环队列
void DestroyQueue(queCyc *q);         
//  判断循环队列是否为空
Bool QueueEmpty(queCyc *q);            
//  返回队列中元素个数，也称队列长度
int QueueLength(queCyc *q);            
//  进队
Bool enQueue(queCyc *q, ElemType e);  
//  出队
Bool deQueue(queCyc *q, ElemType *e); 


int main()
{
    ElemType e;
    queCyc *q;
    printf("(1)初始化队列q\n");
    q = InitQueue();
    printf("(2)依次进队列元素a,b,c\n");
    if (enQueue(q, 'a') == 0)
        printf("队满,不能进队\n");
    if (enQueue(q, 'b') == 0)
        printf("队满,不能进队\n");
    if (enQueue(q, 'c') == 0)
        printf("队满,不能进队\n");
    printf("(3)队列为%s\n", (QueueEmpty(q) == 1? "空" : "非空"));
    if (deQueue(q, &e) == 0)
        printf("队空,不能出队\n");
    else
        printf("(4)出队一个元素%c\n", e);
    printf("(5)队列q的元素个数:%d\n", QueueLength(q));
    printf("(6)依次进队列元素d,e,f\n");
    if (enQueue(q, 'd') == 0)
        printf("队满,不能进队\n");
    if (enQueue(q, 'e') == 0)
        printf("队满,不能进队\n");
    if (enQueue(q, 'f') == 0)
        printf("队满,不能进队\n");
    printf("(7)队列q的元素个数:%d\n", QueueLength(q));
    printf("(8)出队列序列:");
    while (!QueueEmpty(q))
    {
        deQueue(q, &e);
        printf("%c ", e);
    }
    printf("\n");
    printf("(9)释放队列\n");
    DestroyQueue(q);
    return 0;
}

//  初始化循环队列
queCyc * InitQueue()
{
    queCyc *tmp = (queCyc *)malloc(sizeof(queCyc));
    tmp->front = tmp->rear = 0;
    return tmp;
}

//  销毁循环队列
void DestroyQueue(queCyc *q)
{
    free(q);
}

//是否队空
Bool QueueEmpty(queCyc *q)
{
    if(q->front == q->rear)
        return true;
    else
        return false;
}

//队长
int QueueLength(queCyc *q)
{
    if(q->rear >= q->front)
        return q->rear - q->front;
    else
        return q->rear + MaxSize - q->front;
}

//入队
Bool enQueue(queCyc *q, ElemType e)
{
    //是否队满
    if((q->rear+1)%MaxSize == q->front)
        return false;
    
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

//出队
Bool deQueue(queCyc *q, ElemType *e)
{
    //是否队空
    if(QueueEmpty(q))
        return false;
    
    q->front++;
    *e = q->data[q->front];
    return true;
}
