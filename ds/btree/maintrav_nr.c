#include <stdio.h>
#include <malloc.h>

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

//二叉树的非递归遍历
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
        BTNode *st[MaxSize],*p;
        int top = -1;
        top++;
        st[top] = b;                //先把跟节点放入栈中
        //循环从栈中取出元素
        //并访问元素的值（输出结果）
        //然后先放右子树，再放左子树
        //根据栈的特点，先取左子树，后取右子树
        while (top > -1)
        {
            p = st[top];
            top--;
            printf("%c ",p->data);
            if (p->rchild != NULL)
            {
                top++;
                st[top] = p->rchild;
            }
            if (p->lchild != NULL)
            {
                top++;
                st[top] = p->lchild;
            }
        }
    }
    else
    {
        printf("空树");
    }  
}

void InOrder(BTNode *b)
{
    if (b != NULL)
    {
        BTNode *st[MaxSize],*p;
        int top = -1;
        p = b;
        while (top > -1 || p != NULL)
        {
            //不断把左子树节点入栈，直到遇到叶子节点
            while(p != NULL)
            {
                top++;
                st[top] = p;
                p = p->lchild;
            }
            //开始出栈，并且返回右子树阶段
            //重新开始查找左子树
            if (top > -1)
            {
                p = st[top];
                top--;
                printf("%c ",p->data);
                p = p->rchild;
            }
        }
    }    
    else
    {
        printf("空树");
    } 
}

void PostOrder(BTNode *b)
{
    if (b != NULL)
    {
        BTNode *st[MaxSize],*p;
        int top = -1,flag;
        do
        {
            while (b != NULL)
            {
                top++;
                st[top] = b;
                b = b->lchild;
            }
            p = NULL;
            flag = 1;
            while (top != -1 && flag)
            {
                b = st[top];
                if(b->rchild == p)
                {
                    printf("%c ",b->data);
                    top--;
                    p = b;
                }
                else
                {
                    b = b->rchild;
                    flag = 0;
                } 
            }
        } while (top != -1);            
    }
    else
    {
        printf("空树");
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