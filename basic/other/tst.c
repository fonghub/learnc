#include <stdio.h>

#define True 1
#define False 0
typedef int bool;

int kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    int i;
    int maximum = 0;
    int output[candiesSize];
    for(i=0;i<candiesSize;i++)
    {
        if(*(candies+i) > maximum) maximum = *(candies+i);
    }
    for(i=0;i<candiesSize;i++)
    {
        if (*(candies+i) + extraCandies >= maximum)
        {
            output[i] = 1;
        }else
        {
            output[i] = 0;
        }
    }
    // printf("[");
    // for(i=0;i<candiesSize;i++)
    // {
    //     if (output[i] == 1)
    //     {
    //         printf("true");
    //         *returnSize++;
    //     }else
    //     {
    //         printf("false");
    //     }
        
    // }
    // printf("]");
    // if (*returnSize > 1)
    // {
    //    return True;
    // }else
    // {
    //     return False;
    // }
    
    
}

int main()
{
    
    int candies[] = {1,2,3,4,5,6,7,8};
    int candiesSize = 8;
    int extraCandies = 2;
    int *returnSize;
    int result;
    result = kidsWithCandies(&candies[0],candiesSize,extraCandies,returnSize);
}