#include <stdio.h>
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

// 插入排序，升序
void InsertSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    //第0个元素为已排序数组，第1～n-1元素为待排序数据
    //从第一个元素开始，逐个取出来放入已排序数据里
    for ( i = 1; i < n; i++)
    {
        //首先把第i个元素保存到临时变量，把第i个位置腾出来，留给当前循环的最大值
        tmp = R[i];
        //第i个元素 逐个 与已排序数组里的元素比较大小，大的元素放到 j+1 这个位置
        //直到第i个元素比第j个元素大时，对比结束
        j = i - 1;
        while (j >= 0 && tmp.key < R[j].key)
        {
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = tmp;
    }
}

//折半排序，升序
void InsertSort1(RecType R[],int n)
{
    int i,j,low,high,mid;
    RecType tmp;
    for ( i = 1; i < n; i++)
    {
        tmp = R[i];
        //low表示已排序数组最低位
        low = 0;
        //high表示已排序数组最高位
        high = i - 1;

        while (low <= high)
        {
            //找出已排序数组的中间位置
            mid = (low+high)/2;

            if (tmp.key < R[mid].key)
                high = mid - 1; //第i位元素比中间位置小，证明第i位元素的位置在中间位置的左边，即low不变，high = mid - 1
            else
                low = mid + 1;  //第i位元素比中间位置大，证明第i位元素的位置在中间位置的右边，即high不变，low = mid + 1      
        }
        //todo
        for ( j=i-1; i>=high+1; j--)
            R[j+1] = R[j];

        R[high+1] = tmp;
    } 
}



int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[] = {9,8,7,6,5,4,3,2,1,0};
    //赋值
    for ( i = 0; i < n; i++){
        R[i].key = a[i];
    }
    //排序前输出
    printf("排序前：");
    for ( i = 0; i < n; i++){
        printf("%d",R[i].key);
    }
    printf("\n");
    //排序
    InsertSort(R,n);
    // InsertSort1(R,n);
    //排序后输出
    printf("排序后：");
    for ( i = 0; i < n; i++){
        printf("%d",R[i].key);
    }
    printf("\n");

    return 0; 
}
