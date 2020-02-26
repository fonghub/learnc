#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
    KeyType key;
    InfoType data;
} RecType;

//  * 堆化过程
//  * @par R       待堆化序列
//  * @par low     分支节点编号
//  * @par high    元素数量
//  * @comment      对该分支节点以及它的子树堆化
void shift(RecType R[],int low,int high)
{
    int i=low,j=2*i;
    RecType tmp = R[i];
    while (j <= high)
    {
        //有右子节点 && 右子节点大于左子节点
        if(j < high && R[j].key < R[j+1].key)
            j++;
        
        //分支节点 小于 子节点
        if(tmp.key < R[j].key)
        {
            //子节点 赋值 分支节点
            R[i] = R[j];
            //继续堆化子树
            i = j;
            j = 2*i;
        }
        else break;     
        //从树的高层往低层堆化
        //当发现有个分支节点 大于 子节点
        //表明该分支节点以下的子树已经是堆了，无需继续，所以可以退出循环了
    }
    R[i] = tmp;
}

//堆排序
void HeapSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;

    for(i=n/2;i>=1;i--)
        shift(R,i,n);
    
    //每次取出堆顶元素，放到序列的最后面，把序列最后面的元素提到第一个元素，再堆化
    //如此循环，直到最后一个元素
    //此时，元素序列是一个顺序的状态
    for ( j = n; j > 1; j--)
    {
        tmp = R[j];
        R[j] = R[1];
        R[1] = tmp;
        shift(R,1,j-1);
    }
}

int main()
{
    int i,n;
    n = 10;
    RecType R[MaxSize];
    // KeyType a[] = {9,8,7,6,5,4,3,2,1,0};
    KeyType a[] = {1,8,8,1,4,7,9,9,8,6};
    //0号位空闲，树形结构为了方便计算编号，最好从1开始
    for ( i = 0; i < n; i++)
        R[i+1].key = a[i];

    printf("排序前：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i+1].key);
    printf("\n");

    HeapSort(R,n);

    printf("排序后：");
    for ( i = 0; i < n; i++)
        printf("%d",R[i+1].key);
    printf("\n");
    return 0;
}