#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} RDnode;


void displayPNode(RDnode *p);
RDnode* generalPNode(int* nums, int numsSize);
int longestConsecutive(int* nums, int numsSize);
int getBaseNum(int num,int numSt);
int getMaxNum(int* nums, int numsSize);
RDnode* radixSort(RDnode* p,int loop);

int main()
{
    //  数组元素均为正整数
    int arr[] = {0,11,3,44,5,27,90,11,2,13};
    int n = 10;
    int res = longestConsecutive(&arr[0],n);
    printf("最长连续序列的长度=%d\n",res);
    return 0;
}

void displayPNode(RDnode *p)
{
    while (p !=NULL)
    {
        printf("data=%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

RDnode* generalPNode(int* nums, int numsSize)
{
    int i;
    RDnode *p = NULL,*q = NULL,*tmp;
    for(i=0;i<numsSize;i++)
    {
        tmp = (RDnode *)malloc(sizeof(RDnode));
        tmp->data = nums[i];
        tmp->next = NULL;
        if(q == NULL)
        {
            q = tmp;
            p = q;
        }
        else
        {
            q->next = tmp;
            q = tmp;
        }
    }
    return p;
}

//  基数排序
RDnode* radixSort(RDnode* p,int loop)
{   
    RDnode *qSort;
    RDnode *head[10],*tail[10],*tmp;
    int i,j,k;
    *qSort = *p;
    // for(i=0;i<loop;i++)
    // {
    //     for(j=0;j<10;j++)
    //     {
    //         head[j] = tail[j] = NULL;
    //     }

    //     while (qSort != NULL)
    //     {
    //         k = getBaseNum(qSort->data,i+1);
    //         if(head[k] == NULL)
    //         {
    //             head[k] = qSort;
    //             tail[k] = qSort;
    //         }
    //         else
    //         {
    //             tail[k]->next = qSort;
    //             tail[k] = qSort;
    //         }
    //         qSort = qSort->next;
    //     }

    //     qSort = NULL;
    //     for ( j = 0; j < 10; j++)
    //     {
    //         if(head[j] != NULL)
    //         {
    //             if(qSort == NULL)
    //             {
    //                 qSort = head[j];
    //                 tmp = tail[j];
    //             }
    //             else
    //             {
    //                 tmp->next = head[j];
    //                 tmp = tail[j];
    //             } 
    //         }
    //     }
    //     tmp->next = NULL;
    // }
    return qSort;
}
//  求整数某一位数字
int getBaseNum(int num,int numSt)
{
    int numTimes = 1;
    int i,baseNum;
    for(i=1;i<numSt;i++)
    {
        numTimes *= 10;
    }
    baseNum = num/numTimes%10;
    return baseNum;
}
//  最数组最大值
int getMaxNum(int* nums, int numsSize)
{
    int i;
    int max = 0;
    for(i=0;i<numsSize;i++)
    {
        if(max < nums[i]) max = nums[i];
    }
    return max;
}
//  求整数的位数
int	GetMaxLoop(int num)
{
	int bits = 1;
	num /= 10;
	while (num != 0)
	{
		++bits;
		num /= 10;
	}
	return bits;
}
int longestConsecutive(int* nums, int numsSize)
{
    RDnode *p = generalPNode(&nums[0],numsSize);
    displayPNode(p);
    int max = getMaxNum(&nums[0],numsSize);
    int	loop = GetMaxLoop(max);
    printf("loop = %d\t",loop);
    // RDnode *qSort  = radixSort(p,loop);
    // displayPNode(qSort);
    int longest = 1, tmp_longest = 1;
    // for (int i = 1; i < numsSize; i++)
    // {
    //     if(nums[i-1]+1 == nums[i])
    //         tmp_longest++;
    //     else
    //     {
    //         longest = tmp_longest>longest?tmp_longest:longest;
    //         tmp_longest = 1;
    //     }
    // }
    return longest;
}