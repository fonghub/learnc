#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0
#define MaxSize 5

typedef int Bool;
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear; /*队首和队尾指针*/
} SqQueue;

void InitQueue(SqQueue **q);            //初始化顺序队列
void DestroyQueue(SqQueue **q);         //销毁顺序队列
Bool QueueEmpty(SqQueue *q);            //判断顺序队列是否为空
int QueueLength(SqQueue *q);            //返回队列中元素个数，也称队列长度
Bool enQueue(SqQueue **q, ElemType e);  //进队
Bool deQueue(SqQueue **q, ElemType *e); //出队

int main()
{
    ElemType e;
    SqQueue *q;
    printf("(1)初始化队列q\n");
    InitQueue(&q);
    printf("(2)依次进队列元素a,b,c\n");
    if (enQueue(&q, 'a') == 0)
        printf("队满,不能进队\n");
    if (enQueue(&q, 'b') == 0)
        printf("队满,不能进队\n");
    if (enQueue(&q, 'c') == 0)
        printf("队满,不能进队\n");
    printf("(3)队列为%s\n", (QueueEmpty(q) == 1? "空" : "非空"));
    if (deQueue(&q, &e) == 0)
        printf("队空,不能出队\n");
    else
        printf("(4)出队一个元素%c\n", e);
    printf("(5)队列q的元素个数:%d\n", QueueLength(q));
    printf("(6)依次进队列元素d,e,f\n");
    if (enQueue(&q, 'd') == 0)
        printf("队满,不能进队\n");
    if (enQueue(&q, 'e') == 0)
        printf("队满,不能进队\n");
    if (enQueue(&q, 'f') == 0)
        printf("队满,不能进队\n");
    printf("(7)队列q的元素个数:%d\n", QueueLength(q));
    printf("(8)出队列序列:");
    while (!QueueEmpty(q))
    {
        deQueue(&q, &e);
        printf("%c ", e);
    }
    printf("\n");
    printf("(9)释放队列\n");
    DestroyQueue(&q);
    return 0;
}

//初始化队列
void InitQueue(SqQueue **q)
{
    *q = (SqQueue *)malloc(sizeof(SqQueue));
    (*q)->front = (*q)->rear = -1;
}

//销毁队列
void DestroyQueue(SqQueue **q)
{
    free(*q);
}

//是否队空
Bool QueueEmpty(SqQueue *q)
{
    if(q->front == q->rear)
        return True;
    else
        return False;
}

//队长
int QueueLength(SqQueue *q)
{
    return q->rear - q->front;
}

//入队
Bool enQueue(SqQueue **q, ElemType e)
{
    //是否队满
    if((*q)->rear == MaxSize - 1)
        return False;
    
    (*q)->rear++;
    (*q)->data[(*q)->rear] = e;
    return True;
}

//出队
Bool deQueue(SqQueue **q, ElemType *e)
{
    //是否队空
    if(QueueEmpty(*q))
        return False;
    
    (*q)->front++;
    *e = (*q)->data[(*q)->front];
    return True;
}
