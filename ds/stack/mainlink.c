#include <stdio.h>
#include <malloc.h>

#define True 1
#define False 0

typedef char ElemType;
typedef int Bool;

typedef struct linknode
{
    ElemType data;              //数据域
    struct linknode *next;      //指针域
} LiStack;                      //链栈类型定义

void InitStack(LiStack **s);  //初始化栈
void DestroyStack(LiStack **s);  //销毁栈
int StackLength(LiStack *s);  //返回栈长度
Bool StackEmpty(LiStack *s);  //判断栈是否为空
void Push(LiStack **s,ElemType e);  //入栈
Bool Pop(LiStack **s,ElemType *e);  //出栈
Bool GetTop(LiStack *s,ElemType *e);  //取栈顶元素
void DispStack(LiStack *s);  //输出栈中元素


int main()
{
    ElemType e;
    LiStack *s;
    printf("(1)初始化链栈s\n");
    InitStack(&s);
    printf("(2)链栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(3)依次进链栈元素a,b,c,d,e\n");
    Push(&s,'a');
    Push(&s,'b');
    Push(&s,'c');
    Push(&s,'d');
    Push(&s,'e');
    printf("(4)链栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(5)链栈长度:%d\n",StackLength(s));
    printf("(6)从链栈顶到链栈底元素:");DispStack(s);
    printf("(7)出链栈序列:");
    while (StackEmpty(s))
    {   Pop(&s,&e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(8)链栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(9)释放链栈\n");
    DestroyStack(&s);
    return 0;
}

void InitStack(LiStack **s)
{
    *s = (LiStack *)malloc(sizeof(LiStack));
    (*s)->next = NULL;
}

Bool StackEmpty(LiStack *s)
{
    if(s->next == NULL)
        return True;
    else
        return False; 
}

void Push(LiStack **s,ElemType e)
{
    LiStack *tmp = (LiStack *)malloc(sizeof(LiStack));
    tmp->data = e;
    tmp->next = (*s)->next;
    (*s)->next = tmp;
}

void DispStack(LiStack *s)
{
    LiStack *tmp;
    tmp = s->next;
    while(tmp != NULL){
        printf("%c\t",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int StackLength(LiStack *s)
{
    int n = 0;
    LiStack *tmp;
    tmp = s->next;
    while(tmp != NULL){
        n++;
        tmp = tmp->next;
    } 
    return n;
}

Bool Pop(LiStack **s,ElemType *e)
{
    LiStack *p,*q;  //p在前，q在后
    p = *s;
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    *e = p->data;
    q->next = NULL;
}

void DestroyStack(LiStack **s)
{
    free(*s);
}
