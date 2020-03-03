#include <stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    int i=0,j=0;
    while (i < lettersSize)
    {
        if (*(letters+i) > target)
        {
            j = i;
            break;
        }
        i++;
    }
    return *(letters+j);
}

char nextGreatestLetter2(char* letters, int lettersSize, char target)
{
    int l = 0,r = lettersSize - 1,mid;
    while (l <= r)
    {
        mid = (l + r)/2;
        if (target < *(letters + mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return *(letters+(l%lettersSize));
}

void main()
{
    char letters[] = {'a','c','f','h','j'};
    char target = 'e',res;
    int lettersSize = 3;
    char *p;
    p = &letters[0];
    res = nextGreatestLetter2(p,lettersSize,target);
    printf("res=%c",res);
}