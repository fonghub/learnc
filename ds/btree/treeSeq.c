#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef char ElemType;

typedef struct
{   char data[MaxSize];         
    int length;                 
} treeSeq;

treeSeq * InitTree();
void CreateTree(treeSeq *t,char *str);          //由str串创建二叉树
int FindNode(treeSeq *t,char c);                //返查找节点
char LchildNode(treeSeq *t,int index);          //返回指定编号节点的左孩子节点
char RchildNode(treeSeq *t,int index);          //返回指定编号节点的右孩子节点
int MaxIndex(treeSeq *t);                       //返回树节点的最大编号
int TreeDepth(int index);                       //根据节点的最大编号求二叉树的深度
void DispTree(treeSeq *t);                      //输出二叉树
void DestroyTree(treeSeq *t);                   //销毁二叉树

int main()
{
   
    char cstr[] = "ABCDEFG##H####I";
    treeSeq *t;
    printf("  (1)初始化，创建二叉树:");
    t = InitTree();
    CreateTree(t,cstr);
    printf("\n");
    printf("  (2)输出二叉树:");
    DispTree(t);
    printf("\n");
    printf("  (3)查找节点B:");
    int index = FindNode(t, 'B');
    if(index) 
    {
        printf("节点B的index=%d\n",index);
        printf("  (4)");
        char lp = LchildNode(t,index);
        if (lp != '\0')
            printf("左孩子为%c ", lp);
        else
            printf("无左孩子 ");

        char rp = RchildNode(t,index);
        if (rp != '\0')
            printf("右孩子为%c", rp);
        else
            printf("无右孩子 ");
    }
    else
        printf("节点B未找到！");
    
    printf("\n");
    int maxIndex = MaxIndex(t);
    int h = TreeDepth(maxIndex);
    printf("  (4)二叉树b的深度:%d\n", h);
    printf("  (5)释放二叉树t\n");
    DestroyTree(t);
    return 0;
}

//初始化空树
treeSeq * InitTree()
{
    treeSeq *tmp = (treeSeq *)malloc(sizeof(treeSeq));
    tmp->data[0] = '#';
    tmp->length = 0;
    return tmp;
}

//括号表示法创建二叉树
void CreateTree(treeSeq *t,char cstr[])
{
    int i = 0;
    while (cstr[i] != '\0')
    {
        t->data[i+1] = cstr[i];
        i++;
    }
    t->length = i;
}

//括输出二叉树
void DispTree(treeSeq *t)
{
    for(int i=1;i<t->length;i++)
    {
        printf("%c",t->data[i]);
    }
}


//查找节点
int FindNode(treeSeq *t, char c)
{
    for(int i=1;i<t->length;i++)
    {
        if(t->data[i] == c) return i;
    }
    return 0;
}

//左子树
char LchildNode(treeSeq *t,int index)
{
    if (2*index > t->length || t->data[2*index] == '#')
        return '\0';

    return t->data[2*index];
}

//右子树
char RchildNode(treeSeq *t,int index)
{
    if (2*index+1 > t->length || t->data[2*index] == '#')
        return '\0';

    return t->data[2*index+1];
}

//二叉树深度
int TreeDepth(int index)
{
    int h = 1;
    if(index < 1) return 0;
    while (index > 1)
    {
        h++;
        index = (int)floor(index/2);
    }
    return h;
}

//获取最大节点编号
int MaxIndex(treeSeq *t)
{
    for(int i=t->length;i>0;i++)
    {
        if(t->data[i] != '#') return i;
    }
}

//销毁二叉树
void DestroyTree(treeSeq *t)
{
    free(t);
}