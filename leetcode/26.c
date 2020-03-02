#include <stdio.h>

/*  
26. 删除排序数组中的重复项
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    
    int i,j=0;
    for ( i = 1; i < numsSize; i++)
        if (nums[i] != nums[j])
            nums[++j] = nums[i];

     return j+1;
}

int main()
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int length = 10;
    int resLength,i;
    resLength = removeDuplicates(nums,length);
    printf("resLength=%d\n",resLength);
    for ( i = 0; i < resLength; i++)
    {
        printf("%d\t",nums[i]);
    }
    return 0;
}