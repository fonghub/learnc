#include <stdio.h>

int getBaseNum(int num,int baseNum);
int main()
{
    int num = 100;
    int sortNum = getBaseNum(num,5);
    printf("sortNum=%d\t",sortNum);
    return 0;
}

int getBaseNum(int num,int numSt)
{
    int numTimes = 1;
    int i,baseNum;
    for(i=1;i<numSt;i++)
    {
        numTimes *= 10;
    }
    baseNum = num/numTimes%10;
    return baseNum;
}