#include <stdio.h>
#include <stdlib.h>

void bubble(int* arr, int arrSize);
int findBestValue(int* arr, int arrSize, int target);

int main()
{
    int arr[] = {4,9,3};
    int n = 3,target = 10;
    int value = findBestValue(&arr[0],n,target);
    printf("value=%d",value);
    return 0;
}
//  排序
void bubble(int* arr, int arrSize)
{
    for(int i=0;i<arrSize-1;i++)
    {
        int flag = 1;
        for(int j=arrSize-1;j>i;j--)
        {
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                flag = 0;
            }
        }
        if(flag == 1) break;
    }
}

int findBestValue(int* arr, int arrSize, int target)
{
    bubble(&arr[0],arrSize);
    int i,sum=0;

    for(i=0;i<arrSize;i++)
    {
        if(sum + arr[i]*(arrSize-i) > target) break;
        sum += arr[i];
    }

    if(i == arrSize) return arr[arrSize-1];

    int value = (target-sum)/(arrSize-i);
    double value_1 = (double)(target-sum)/(arrSize-i);
    if(value_1 - value > 0.5)
        return value+1;
    else
        return value;
}
