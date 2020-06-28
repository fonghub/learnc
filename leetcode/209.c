#include <stdio.h>

int minSubArrayLen(int s, int* nums, int numsSize);

int main()
{
    //  s大于0，numsSize大于等于0
    int s = 3,numsSize = 2;
    //  数组元素大于0
    int nums[2] = {1,1};
    int length = minSubArrayLen( s, &nums[0],  numsSize);
    printf("长度最小的子数组长度length=%d",length);
    return 0;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
    int length = numsSize;  //  定义子数组的最小长度为数组的长度
    
    //  定义两个数组下标：i，j；
    //  i表示子数组的开始下标，j表示子数组的结束下标
    for(int i=0;i<numsSize;i++)
    {   
        //  定义子数组的和sum为0，临时最小长度tmpLength为0
        int sum = 0,tmpLength = 0,j;
        // 从位置i开始累加到位置j，直到累加和大于等于s 或者 j大于等于元素个数numsSize 时停止
        for(j=i;j<numsSize && sum<s;j++)
        {
            sum += nums[j];
            tmpLength++;
        }
        //  表示因为j大于等于元素个数numsSize导致累加停止
        if(sum < s)
        {
            if(i == 0) return 0;   //  当i=0，表示整个数组累加和小于s时，返回0
            else break; //  否则，表示从位置i开始，后面的元素累加和都小于s，不存在符合条件的子数组，直接跳出循环
        }
        //  表示因为累加和大于等于s导致累加停止
        //  对比最小子数组长度，保留小的
        if(tmpLength < length) length = tmpLength;
        printf("i=%d,j=%d,tmpLength=%d,sum=%d\n",i,j,tmpLength,sum);
    }

    return length;
}

