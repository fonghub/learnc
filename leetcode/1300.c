#include <stdio.h>
#include <stdlib.h>

void bubble(int* arr, int arrSize);
int findBestValue1(int* arr, int arrSize, int target);
int findBestValue2(int* arr, int arrSize, int target);
void getMMS(int* arr,int arrSize,int* maxValue,int* sumValue);


int main()
{
    int arr[] = {4,3,9};
    int n = 3,target = 10;
    int value = findBestValue1(&arr[0],n,target);
    printf("value=%d",value);
    return 0;
}

void getMMS(int* arr,int arrSize,int* maxValue,int* sumValue)
{
    *maxValue = arr[0];
    *sumValue = arr[0];
    for(int i=1;i<arrSize;i++)
    {
        if(arr[i] > *maxValue) *maxValue = arr[i];
        *sumValue += arr[i];
    }
}

int findBestValue2(int* arr, int arrSize, int target)
{
    bubble(&arr[0],arrSize);
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        int x = (target - sum) / (arrSize - i);
        if (x < arr[i]) {
            double t = ((double)(target - sum))/(arrSize - i);
            if (t - x > 0.5) {
                return x + 1;
            } else {
                return x;
            }
        }
        sum += arr[i];
    }
    return arr[arrSize - 1];

}

//  冒泡排序
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

//  v1
int findBestValue1(int* arr, int arrSize, int target)
{
   int maxValue = 0,sumValue = 0,value = 0,offsetValue = 0;
    getMMS(&arr[0],arrSize,&maxValue,&sumValue);

    //  数组元素和小于target，返回最大数组元素
    if(sumValue <= target) return maxValue;

    //  数组元素和大于target
    int sumTempValue = 0,diffTempValue = 0,i;
 
    bubble(&arr[0],arrSize);

    for(i=0;i<arrSize;i++)
    {
        int temp = sumTempValue + arr[i]*(arrSize-i);
        if(temp > target) break;
        sumTempValue += arr[i];
    }
    diffTempValue = target - sumTempValue;
    value = diffTempValue/(arrSize-i);
    offsetValue = value + 1;
    int diffValue1,diffValue2;
    diffValue1 = (arrSize-i)*value-diffTempValue;
    diffValue2 = (arrSize-i)*offsetValue-diffTempValue;
    if(abs(diffValue1) == abs(diffValue2)) return value;
    return abs(diffValue1) > abs(diffValue2)?offsetValue:value;
}
