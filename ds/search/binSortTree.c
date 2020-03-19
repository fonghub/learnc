#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char InfoType[10];
typedef struct node                 //记录类型
{
    KeyType key;                    //关键字项
    InfoType data;                  //其他数据域
    struct node *lchild,*rchild;    //左右孩子指针
} BSTNode;

//在p所指向的二叉排序树中，插入值为k的节点
int InsertBST(BSTNode **p,KeyType k)
{
    if (*p==NULL)                        //原树为空, 新插入的记录为根结点
    {
        *p=(BSTNode *)malloc(sizeof(BSTNode));
        (*p)->key=k;
        (*p)->lchild=(*p)->rchild=NULL;
        return 1;
    }
    else if (k==(*p)->key)                 //树中存在相同关键字的结点,返回0
        return 0;
    else if (k<(*p)->key)
        return InsertBST(&(*p)->lchild,k);  //插入到*p的左子树中
    else
        return InsertBST(&(*p)->rchild,k);  //插入到*p的右子树中
}

//由有n个元素的数组A，创建一个二叉排序树
BSTNode *CreateBST(KeyType A[],int n)   //返回BST树根结点指针
{
    BSTNode *bt=NULL;                   //初始时bt为空树
    int i=0;
    while (i<n)
    {
        InsertBST(&bt,A[i]);             //将关键字A[i]插入二叉排序树T中
        i++;
    }
    return bt;                          //返回建立的二叉排序树的根指针
}

//输出一棵排序二叉树
void DispBST(BSTNode *bt)
{
    if (bt!=NULL)
    {
        printf("%d",bt->key);
        if (bt->lchild!=NULL || bt->rchild!=NULL)
        {
            printf("(");                        //有孩子结点时才输出(
            DispBST(bt->lchild);                //递归处理左子树
            if (bt->rchild!=NULL) printf(",");  //有右孩子结点时才输出,
            DispBST(bt->rchild);                //递归处理右子树
            printf(")");                        //有孩子结点时才输出)
        }
    }
}

//在bt指向的节点为根的排序二叉树中，查找值为k的节点。找不到返回NULL
BSTNode *SearchBST(BSTNode *bt,KeyType k)
{
    if (bt==NULL || bt->key==k)         //递归终结条件
        return bt;
    if (k<bt->key)
        return SearchBST(bt->lchild,k);  //在左子树中递归查找
    else
        return SearchBST(bt->rchild,k);  //在右子树中递归查找
}

//二叉排序树中查找的非递归算法
BSTNode *SearchBST1(BSTNode *bt,KeyType k)
{
    while (bt!=NULL)
    {
        if (k==bt->key)
            return bt;
        else if (k<bt->key)
            bt=bt->lchild;
        else
            bt=bt->rchild;
    }
    return NULL;
}

//删除二叉搜索树中的一个节点  ——  未完成
BSTNode *DeleteBST(BSTNode *bt, KeyType k)  //在bt中删除关键字为k的结点
{   
    BSTNode *tmp,*q,*p,*p1;
    tmp = bt;
    while (bt != NULL)
    {
        // printf("%d ",bt->key);
        if(k<bt->key)
            bt = bt->lchild;
        else if(k>bt->key)
            bt = bt->rchild;
        else
        {
            // printf("%d ",bt->key);
            if (bt->rchild == NULL)
            {
                // q = bt;
                bt = bt->lchild;
                // free(q);
            }else if (bt->lchild == NULL)
            {
                // q = bt;
                bt = bt->rchild;
                // free(q);
            }else
            {
                p = bt->lchild;
                while (p->rchild != NULL)
                    p = p->rchild;
                
                p1 = bt;
                bt->key = p->key;
                p = p->lchild;
                free(p1);
            }
            break;
        }
        
    }
    return tmp;
}


int main()
{
    BSTNode *bt;
    int n=12,x=11;
    KeyType a[]= {25,18,46,2,53,39,32,4,74,67,60,11};
    bt=CreateBST(a,n);
    printf("BST:");
    DispBST(bt);
    printf("\n");
    printf("删除%d结点\n",x);
    if (SearchBST(bt,x)!=NULL)
    {  
        bt=DeleteBST(bt,x);
        printf("BST:");
        DispBST(bt);
        printf("\n");
    }
    return 0;

}
