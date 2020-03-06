#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
#define True 1
#define False 0

typedef int Bool;
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;                //栈指针
} SqStack;                  //顺序栈类型定义

void InitStack(SqStack **s);    //初始化栈
void DestroyStack(SqStack **s);  //销毁栈
Bool StackEmpty(SqStack *s);     //栈是否为空
int StackLength(SqStack *s);  //返回栈中元素个数——栈长度
Bool Push(SqStack **s,ElemType e); //入栈
void Pop(SqStack *s,ElemType *e); //出栈
Bool GetTop(SqStack *s,ElemType *e); //取栈顶数据元素
void DispStack(SqStack *s);  //输出栈



int main()
{
    ElemType e;
    SqStack *s;
    printf("(1)初始化栈s\n");
    InitStack(&s);
    printf("(2)栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(3)依次进栈元素a,b,c,d,e\n");
    Push(&s,'a');
    Push(&s,'b');
    Push(&s,'c');
    Push(&s,'d');
    Push(&s,'e');
    printf("(4)栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(5)栈长度:%d\n",StackLength(s));
    printf("(6)从栈顶到栈底元素:");DispStack(s);
    printf("(7)出栈序列:");
    while (!StackEmpty(s))
    {
        Pop(s,&e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(8)栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(9)释放栈\n");
    DestroyStack(&s);
    return 0;
}

void InitStack(SqStack **s)
{
    *s = (SqStack *)malloc(sizeof(SqStack));
    (*s)->top = -1;
}

Bool StackEmpty(SqStack *s)
{
    if (s->top == -1)
        return True;
    else
        return False;  
}

Bool Push(SqStack **s,ElemType e)
{
    (*s)->top++;
    (*s)->data[(*s)->top] = e;
}

int StackLength(SqStack *s)
{
    return s->top + 1;
}

void DispStack(SqStack *s)
{
    int top = s->top;
    while (top > -1)
    {
        printf("%c\t",s->data[top]);
        top--;
    }
    printf("\n");
}

void Pop(SqStack *s,ElemType *e)
{
    *e = s->data[s->top];
    s->top--;
}

void DestroyStack(SqStack **s)
{
    free(*s);
}