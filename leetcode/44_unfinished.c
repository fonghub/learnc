#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

bool isMatch(char * s, char * p);

int main()
{
    char s[] = "aa";
    char p[] = "*a";
    bool res = isMatch( &s[0],  &p[0]);
    if(res)
        printf("匹配\n");
    else
        printf("不匹配\n");

    return 0;
}

bool isMatch(char * s, char * p)
{
    int i=0,j=0;
    while(s[i] != '\0' && p[j] != '\0')
    {
        switch(p[j])
        {
            case '?':
                i++;j++;
                break;

            case '*':
                j++;
                if(p[j] == '\0') return true;
                while(s[i] != '\0' && s[i] != p[j])
                    i++; 
                
                if(s[i] == '\0') return false;
                i++;j++;
                break;

            default:
                if(s[i] == p[j])
                {
                    i++;j++;
                }else
                {
                    return false;
                }
            break;
        }
    }

    if(s[i] == '\0' && p[j] == '\0') return true;

    return false;
}