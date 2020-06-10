#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define true 1
#define false 0

typedef int Bool;
typedef char ElemType;
typedef struct Node
{
    ElemType data[MaxSize];
    int top;                
} stackSeq;                          

//初始化栈
stackSeq * InitStack();    
//销毁栈
void DestroyStack(stackSeq *s);  
//栈是否为空
Bool StackEmpty(stackSeq *s);    
//栈是否为满
Bool StackFull(stackSeq *s);     
//返回栈中元素个数——栈长度
int StackLength(stackSeq *s);  
//入栈
Bool Push(stackSeq *s,ElemType e); 
//出栈
void Pop(stackSeq *s,ElemType *e); 
//取栈顶数据元素
Bool GetTop(stackSeq *s,ElemType *e); 
//输出栈
void DispStack(stackSeq *s);  



int main()
{
    ElemType e;
    stackSeq *s;
    printf("(1)初始化栈s\n");
    s = InitStack();
    printf("(2)栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(3)依次进栈元素a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
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
    DestroyStack(s);
    return 0;
}

stackSeq * InitStack()
{
    stackSeq *tmp = (stackSeq *)malloc(sizeof(stackSeq));
    tmp->top = -1;
    return tmp;
}

Bool StackEmpty(stackSeq *s)
{
    if (s->top == -1)
        return true;
    else
        return false;  
}

Bool StackFull(stackSeq *s)
{
    if (s->top == MaxSize-1)
        return true;
    else
        return false;  
}

Bool Push(stackSeq *s,ElemType e)
{
    //判断是否满栈
    if(StackFull(s)) return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

int StackLength(stackSeq *s)
{
    return s->top + 1;
}

void DispStack(stackSeq *s)
{
    int top = s->top;
    while (top > -1)
    {
        printf("%c\t",s->data[top]);
        top--;
    }
    printf("\n");
}

void Pop(stackSeq *s,ElemType *e)
{
    *e = s->data[s->top];
    s->top--;
}

void DestroyStack(stackSeq *s)
{
    free(s);
}