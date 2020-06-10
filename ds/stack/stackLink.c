#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef char ElemType;
typedef int Bool;

typedef struct Node
{
    ElemType data;              
    struct Node *next;      
} stackLink;                      

//  初始化栈
stackLink * InitStack();    
//  销毁栈
void DestroyStack(stackLink *s);  
//  栈是否为空
Bool StackEmpty(stackLink *s);    
//  链栈没有栈满的概念
Bool StackFull(stackLink *s);     
//  返回栈中元素个数——栈长度
int StackLength(stackLink *s);  
//  入栈
Bool Push(stackLink *s,ElemType e); 
//  出栈
void Pop(stackLink *s,ElemType *e); 
//  取栈顶数据元素
Bool GetTop(stackLink *s,ElemType *e); 
//  输出栈
void DispStack(stackLink *s);  


int main()
{
    ElemType e;
    stackLink *s;
    printf("(1)初始化链栈s\n");
    s = InitStack();
    printf("(2)链栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(3)依次进链栈元素a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("(4)链栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(5)链栈长度:%d\n",StackLength(s));
    printf("(6)从链栈顶到链栈底元素:");DispStack(s);
    printf("(7)出链栈序列:");
    while (!StackEmpty(s))
    {   Pop(s,&e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(8)链栈为%s\n",(StackEmpty(s) == 1?"空":"非空"));
    printf("(9)释放链栈\n");
    DestroyStack(s);
    return 0;
}

//初始化栈
stackLink * InitStack()
{
    //栈头节点
    stackLink *tmp = (stackLink *)malloc(sizeof(stackLink));
    tmp->next = NULL;
    return tmp;
}

Bool StackEmpty(stackLink *s)
{
    if(s->next == NULL)
        return true;
    else
        return false; 
}

//  入栈
Bool Push(stackLink *s,ElemType e)
{
    stackLink *tmp = (stackLink *)malloc(sizeof(stackLink));
    tmp->data = e;
    tmp->next = s->next;
    s->next = tmp;
}

void DispStack(stackLink *s)
{
    stackLink *tmp;
    tmp = s->next;
    while(tmp != NULL){
        printf("%c\t",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int StackLength(stackLink *s)
{
    int n = 0;
    stackLink *tmp;
    tmp = s->next;
    while(tmp != NULL){
        n++;
        tmp = tmp->next;
    } 
    return n;
}

//  出栈
void Pop(stackLink *s,ElemType *e)
{
    stackLink *tmp = s->next;
    *e = tmp->data;
    s->next = tmp->next;
    free(tmp);
}

//  销毁栈
void DestroyStack(stackLink *s)
{
    if(s != NULL) 
    {
        stackLink *tmp = s->next,*q;
        while (tmp != NULL)
        {
            q = tmp;
            tmp = tmp->next;
            free(q);
        }
        free(s);
    }
}
