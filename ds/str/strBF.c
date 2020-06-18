#include <stdio.h>

int bf(char *s,char *t);

int main()
{
    char s[] = "[Done] exited with code=0 in 0.454 seconds";
    char t[] = "Done";
    int index = bf(&s[0],&t[0]);
    printf("index=%d\n",index);
    return 0;
}

int StrLength(char *s)
{
    int i = 0;
    while(*(s+i) != '\0')
        i++;
    
    return i;
}

//  Brute-Force算法 
int bf(char *s,char *t)
{
    int sLength = StrLength(s);
    int tLength = StrLength(t);
    if(sLength < tLength) return -1;
    int si = 0,ti = 0;
    while (si+tLength <= sLength)
    {
        int flag = 1;
        for(ti=0;ti<tLength;ti++)
            if(*(s+si+ti) != *(t+ti))
            {
                flag = 0;
                break;
            }

        if(flag)
            return si+1;
        else
        {
            ti = 0;
            si++;
        }
    }

    return -1;
}