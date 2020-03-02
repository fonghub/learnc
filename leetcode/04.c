#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double res;
    if (nums1Size == 0)
    {
        if (nums2Size%2 == 1)
        {
            res = (double)nums2[nums2Size/2];
        }else
        {
            res = (nums2[nums2Size/2] + nums2[nums2Size/2-1]) / 2.0;
        }
        
    }else if (nums2Size == 0)
    {
        if (nums1Size%2 == 1)
        {
            res = (double)nums1[nums1Size/2];
        }else
        {
            res = (nums1[nums1Size/2] + nums1[nums1Size/2-1]) / 2.0;
        }

    }else
    {
        
    }
    return res;
}

int main()
{

    return 0;
}