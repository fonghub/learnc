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
void PreOrder(BTNode *b);                 //先序遍历的递归算法
void InOrder(BTNode *b);                 //中序遍历的递归算法
void PostOrder(BTNode *b);               //后序遍历的递归算法
void DestroyBTNode(BTNode **b);          //销毁二叉树


int main()
{
    BTNode *b, *p;
    printf("  (1)创建二叉树:");
    CreateBTNode(&b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("\n");
    printf("  (2)输出二叉树:");
    DispBTNode(b);
    printf("\n");
    printf("  (3)先序遍历序列:");
    PreOrder(b);
    printf("\n");
    printf("  (4)中序遍历序列:");
    InOrder(b);
    printf("\n");
    printf("  (5)后序遍历序列:");
    PostOrder(b);
    printf("\n");
    printf("  (6)释放二叉树b\n");
    DestroyBTNode(&b);
    return 0;
}

void PreOrder(BTNode *b)
{
    if (b != NULL)
    {
        printf("%c ",b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
    
}

void InOrder(BTNode *b)
{
    if (b != NULL)
    {
        InOrder(b->lchild);
        printf("%c ",b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode *b)
{
    if (b != NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ",b->data);
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