#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef char ElemType;

typedef struct node
{
    ElemType data;                          //数据元素
    struct node *lchild;                    //指向左孩子
    struct node *rchild;                    //指向右孩子
} BTNode;

BTNode *CreateBTNode(char *str);            //由str串创建二叉树
BTNode *FindNode(BTNode *b, ElemType x);    //返回data域为x的节点指针
BTNode *LchildNode(BTNode *p);              //返回p节点的左孩子节点指针
BTNode *RchildNode(BTNode *p);              //返回p节点的右孩子节点指针
int BTNodeDepth(BTNode *b);                 //求二叉树b的深度
void DispBTNode(BTNode *b);                 //以括号表示法输出二叉树
void DestroyBTNode(BTNode *b);              //销毁二叉树

int main()
{
    BTNode *b, *p, *lp, *rp;
    printf("  (1)创建二叉树:");
    b = CreateBTNode("A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("\n");
    printf("  (2)输出二叉树:");
    DispBTNode(b);
    printf("\n");
    printf("  (3)查找H节点:");
    p = FindNode(b, 'H');
    if (p != NULL)
    {
        lp = LchildNode(p);
        if (lp != NULL)
            printf("左孩子为%c ", lp->data);
        else
            printf("无左孩子 ");
        rp = RchildNode(p);
        if (rp != NULL)
            printf("右孩子为%c", rp->data);
        else
            printf("无右孩子 ");
    }
    else
        printf(" 未找到！");
    printf("\n");
    printf("  (4)二叉树b的深度:%d\n", BTNodeDepth(b));
    printf("  (5)释放二叉树b\n");
    DestroyBTNode(b);
    return 0;
}

//销毁二叉树
void DestroyBTNode(BTNode *b)
{
    if (b != NULL)
    {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}

//二叉树深度
int BTNodeDepth(BTNode *b)
{
    int lchilddep, rchilddep;
    if (b == NULL)
        return 0;
    else
    {
        lchilddep = BTNodeDepth(b->lchild);
        rchilddep = BTNodeDepth(b->rchild);
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

//左子树
BTNode *LchildNode(BTNode *p)
{
    if (p == NULL)
        return NULL;
    return p->lchild;
}

//右子树
BTNode *RchildNode(BTNode *p)
{
    if (p == NULL)
        return NULL;
    return p->rchild;
}

//括号表示法创建二叉树
BTNode *CreateBTNode(char *str)
{
    BTNode *st[MaxSize], *p = NULL,*b = NULL;
    int top = -1, k, j = 0;
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
            //第一个元素为根节点，
            if (b == NULL)
                b = p;
            else
            {
                switch (k)
                {
                case 1:
                    st[top]->lchild = p;
                    break;
                case 2:
                    st[top]->rchild = p;
                    break;
                }
            }
            break;
        }
        ch = str[++j];
    }

    return b;
}

//括号表示法输出二叉树
void DispBTNode(BTNode *b)
{
    if (b != NULL)
    {
        printf("%c", b->data);
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

//查找节点
BTNode *FindNode(BTNode *b, ElemType x)
{
    BTNode *p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}