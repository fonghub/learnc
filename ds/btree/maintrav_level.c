#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;       //数据元素
    struct node *lchild; //指向左孩子
    struct node *rchild; //指向右孩子
} BTNode;

void CreateBTNode(BTNode **b, char *str); //由str串创建二叉链
void DispBTNode(BTNode *b);               //以括号表示法输出二叉树
void LevelOrder(BTNode *b);               //层次遍历
void DestroyBTNode(BTNode **b);          //销毁二叉树

//利用队列实现二叉树的层次遍历
int main()
{
    BTNode *b, *p;
    printf("  (1)创建二叉树:");
    CreateBTNode(&b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("\n");
    printf("  (2)输出二叉树:");
    DispBTNode(b);
    printf("\n");
    printf("  (3)层次遍历:");
    LevelOrder(b);
    printf("\n");
    printf("  (6)释放二叉树b\n");
    DestroyBTNode(&b);
    return 0;
}

//利用循环队列实现二叉树的层次遍历
void LevelOrder(BTNode *b)
{
    BTNode *qu[MaxSize],*p;
    int front = -1, rear = -1;
    rear++;
    qu[rear] = b;
    while (front != rear)
    {
        front = (front + 1)%MaxSize;
        p = qu[front];
        printf("%c ",p->data);
        if (p->lchild != NULL)
        {
            rear = (rear + 1)%MaxSize;
            qu[rear] = p->lchild;
        }
        if (p->rchild != NULL)
        {
            rear = (rear + 1)%MaxSize;
            qu[rear] = p->rchild;
        }
    }
    
}


void CreateBTNode(BTNode **b, char *str)
{
    BTNode *st[MaxSize],*p=NULL;
    int j = 0,top = -1,k;
    *b = NULL;
    char ch = str[j];
    while (ch != '\0')
    {
        
        switch (ch)
        {
        case '(':
            top++;
            st[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if(*b == NULL)
                *b = p;
            else
                switch (k)
                {
                case 1:
                    st[top]->lchild = p;
                    break;
                case 2:
                    st[top]->rchild = p;
                    break;
                }
            break;
        }
        ch = str[++j];
    } 
}

void DestroyBTNode(BTNode **b)
{
    if (*b != NULL)
    {
        DestroyBTNode(&(*b)->lchild);
        DestroyBTNode(&(*b)->rchild);
        free(*b);
    }
}

void DispBTNode(BTNode *b)
{
    if (b != NULL)
    {
        printf("%c",b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}