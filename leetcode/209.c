#include <stdio.h>

int minSubArrayLen(int s, int* nums, int numsSize);
int sumArray(int* nums, int numsSize);

int main()
{
    int s = 14,numsSize = 6;
    int nums[6] = {2,3,1,2,4,3};
    int length = minSubArrayLen( s, &nums[0],  numsSize);
    printf("长度最小的子数组长度length=%d",length);
    return 0;
}

int sumArray(int* nums, int numsSize)
{
    int sum = 0;;
    for(int i=0;i<numsSize;i++)
        sum += nums[i];
    
    return sum;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
    if(sumArray(&nums[0],  numsSize) < s) return 0;

    int length = numsSize;
    
    for(int i=0;i<numsSize;i++)
    {
        int sum = nums[i];
        int j = i;
        int tmpLength = 1;
        while(sum < s)
        {
            j++;
            tmpLength++;
            sum += nums[j];
        }
        if(tmpLength < length) length = tmpLength;
        //if(j = numsSize-1) break;
    }

    return length;
}

