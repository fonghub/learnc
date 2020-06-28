#include <stdio.h>

int minSubArrayLen(int s, int* nums, int numsSize);

int main()
{
    int s = 3,numsSize = 2;
    int nums[2] = {1,1};
    int length = minSubArrayLen( s, &nums[0],  numsSize);
    printf("长度最小的子数组长度length=%d",length);
    return 0;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
    int length = numsSize;
    
    for(int i=0;i<numsSize;i++)
    {   
        int sum = 0,tmpLength = 0,j;
        for(j=i;j<numsSize && sum<s;j++)
        {
            sum += nums[j];
            tmpLength++;
        }
        if(sum < s)
        {
            if(i == 0 && j == numsSize) return 0;
            else break;
        }
        
        break;
        if(tmpLength < length) length = tmpLength;
        printf("i=%d,j=%d,tmpLength=%d,sum=%d\n",i,j,tmpLength,sum);
    }

    return length;
}

