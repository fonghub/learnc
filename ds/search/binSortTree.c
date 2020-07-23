#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef char InfoType[10];

typedef struct node                 //记录类型
{
    KeyType key;                    //关键字项
    InfoType data;                  //其他数据域
    struct node *lchild,*rchild;    //左右孩子指针
} BSTNode;

BSTNode *CreateBST(KeyType A[],int n);
int InsertBST(BSTNode *p,KeyType k);
void DispBST(BSTNode *bt);
BSTNode *SearchBST(BSTNode *bt,KeyType k);
BSTNode *SearchBST_unr(BSTNode *bt,KeyType k);
int DeleteBST(BSTNode *bt, KeyType k);
BSTNode *GenerateNode(KeyType k);

//  二叉查找树
int main()
{
    BSTNode *bt;
    int del_num;
    int n=12,x=46;
    KeyType a[]= {25,18,46,2,53,39,32,4,74,67,60,11};
    bt=CreateBST(a,n);
    printf("BST:");
    DispBST(bt);
    printf("\n");
    printf("删除%d结点\n",x);
    if (SearchBST(bt,x) != NULL)
    {   //  结果 ！= NULL 表示找到值域为x的节点
        del_num = DeleteBST(bt,x);
        if(del_num)
            printf("成功删除结点 %d\n",x);
        printf("BST:");
        DispBST(bt);
        printf("\n");
    }
    return 0;

}


//由有n个元素的数组A，创建一个二叉排序树
BSTNode *CreateBST(KeyType A[],int n)  
{
    BSTNode *bt=NULL;                  
    for(int i=0;i<n;i++)
    {
        if(bt == NULL)
            bt = GenerateNode(A[i]);
        else 
            InsertBST(bt,A[i]);
    }
    return bt;                
}

BSTNode *GenerateNode(KeyType k)
{
    BSTNode *tmp=(BSTNode *)malloc(sizeof(BSTNode));
    tmp->key=k;
    tmp->lchild=tmp->rchild=NULL;
    return tmp;
}

//在p所指向的二叉排序树中，插入值为k的节点
int InsertBST(BSTNode *p,KeyType k)
{
    if (k == p->key)                 //树中存在相同关键字的结点,返回0
        return 0;
    else if (k < p->key)            //插入到p的左子树中
    {
        if(p->lchild != NULL)
            return InsertBST(p->lchild,k);  
        else
        {
            p->lchild = GenerateNode(k);
            return 1;
        }
    }
    else                                //插入到p的右子树中
    {
        if(p->rchild != NULL)
            return InsertBST(p->rchild,k); 
        else
        {
            p->rchild = GenerateNode(k);
            return 1;
        }
    }
}

//括号表示法输出一棵排序二叉树
void DispBST(BSTNode *bt)
{ 
    if (bt != NULL)
    {
        printf("%d",bt->key);
        if (bt->lchild != NULL || bt->rchild != NULL)
        {
            printf("(");                        //有孩子结点时才输出(
            DispBST(bt->lchild);                //递归处理左子树
            if (bt->rchild != NULL) printf(",");  //有右孩子结点时才输出,
            DispBST(bt->rchild);                //递归处理右子树
            printf(")");                        //有孩子结点时才输出)
        }
    }
}

//在bt指向的节点为根的排序二叉树中，查找值为k的节点。找不到返回NULL
BSTNode *SearchBST(BSTNode *bt,KeyType k)
{
    if (bt == NULL || bt->key==k)         //递归终结条件
        return bt;
    if (k < bt->key)
        return SearchBST(bt->lchild,k);  //在左子树中递归查找
    else
        return SearchBST(bt->rchild,k);  //在右子树中递归查找
}

//二叉排序树中查找的非递归算法
BSTNode *SearchBST_unr(BSTNode *bt,KeyType k)
{
    while (bt != NULL)
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

//删除二叉搜索树中的一个节点
int DeleteBST(BSTNode *bt, KeyType k)  //在bt中删除关键字为k的结点
{   
    BSTNode *tmpchild,*p;
    if(bt == NULL)
        return 0;
    else
    {
        while (bt->key != k)
        {
            p = bt;                             //  记录目标节点的父节点
            if(k < bt->key)                     //  往左找
                bt = bt->lchild;
            else if(k > bt->key)               //  往右找
                bt = bt->rchild;
        }
        
        if(bt->rchild == NULL)                  //  目标节点无右孩子节点，则目标节点可能有左节点（左节点可能为NULL）
        {
            if(k < p->key)                     //   目标节点在左子树
                p->lchild = bt->lchild;
            else if(k > p->key)               //    目标节点在右子树
                p->rchild = bt->lchild;
            free(bt);
        }
        else if(bt->lchild == NULL)             //  目标节点无左孩子节点，则目标节点可能有右节点（右节点可能为NULL）
        {
            if(k < p->key)                     //   目标节点在左子树
                p->lchild = bt->rchild;
            else if(k > p->key)               //    目标节点在右子树
                p->rchild = bt->rchild;
            free(bt);
        }
        else                                    //  目标节点有左右孩子节点，找到左子树的最大的右孩子节点
        {
            tmpchild = bt->lchild;              //  左子树节点
            if(tmpchild->rchild == NULL)        //  当左子树没有右孩子节点，则左子树节点就是 用来替换目标节点的 最大节点，
            {
                bt->key = tmpchild->key;
                bt->lchild = tmpchild->lchild;   //  删除左子树节点，此时左子树节点没有右孩子节点，可能有左孩子节点
                free(tmpchild);
            }
            else                                //  左子树节点有右孩子节点
            {
                while (tmpchild->rchild != NULL)    //  找到最大深度的右孩子节点，就是值最大的节点，并且记录它的父节点
                {   
                    p = tmpchild;
                    tmpchild = tmpchild->rchild;
                }
                bt->key = tmpchild->key;            //  替换目标节点的值
                p->rchild = tmpchild->lchild;       //  此时的 tmpchild 一定没有右子节点，但可能有左子节点
                free(tmpchild);
            }
        }
        return 1;
    }
    
}