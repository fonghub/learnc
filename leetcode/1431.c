#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    int i;
    int maximum = 0;
    bool *output = (bool *)malloc(sizeof(bool) * candiesSize);

    // 遍历每个小孩子的糖果数量，找到糖果数量最大值 maximum
    for(i=0;i<candiesSize;i++)
    {
        if(candies[i] > maximum) maximum = candies[i];
    }

    //  把额外的糖果数量 extraCandies 只分给一个小孩，
    //  找到此时糖果总数量 大于等于 糖果数量最大值 的小孩，标记true，其余标记false
    for(i=0;i<candiesSize;i++)
    {
        if (candies[i] + extraCandies >= maximum)
            output[i] = true;
        else
            output[i] = false;
    }

    *returnSize = candiesSize;
    return output;    
}



int main()
{
    int candies[] = {1,2,3,4,5,6,7,8};
    int candiesSize = 8;
    int extraCandies = 2;
    int *returnSize;
    bool *result;
    result = kidsWithCandies(&candies[0],candiesSize,extraCandies,returnSize);
    printf("[");
    for(int i=0;i<*returnSize;i++)
    {
        if(result[i] == 1)
            printf("true");
        else
            printf("false");
        
        if(i < (*returnSize-1)) printf(",");
    }
    printf("]");
    free(result);
}