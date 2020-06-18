#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;


typedef struct node
{
    char data;
    struct node *next;
} strLink;

strLink * StrAssign(char *s);
bool isPalindrome(char * s);
void DispStr(strLink * s);
bool isPalindrome(char * s);
char GetChar(char c);
void StrCopy(strLink *str,int length,char *s);
void DispArr(char *arr,int length);

int main()
{
    char s[] = "";
    if(isPalindrome(&s[0]))
    {
        printf("true\t");
    }else
    {
        printf("false\t");
    }
    
    return 0;
}

char GetChar(char c)
{
    char res='\0';
    if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') )
        res = c;
    
    if(c >= 'A' && c <= 'Z')
        res = c + 32;

    return res;
}

int StrLength(strLink *s)
{
    strLink * tmp = s->next;
    int i = 0;
    while(tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

strLink * StrAssign(char *s)
{
    strLink *tmp,*r,*p;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;
    r = tmp;
    int i = 0;
    while(s[i] != '\0')
    {
        char res;
        if((res = GetChar(s[i])) == '\0')
        {
            i++;
            continue;
        }

        p = (strLink *)malloc(sizeof(strLink));
        p->data = res;
        r->next = p;
        r = p;
        i++;
    }
    r->next = NULL;
    return tmp;
}

void DispStr(strLink *s)
{
    strLink *tmp = s->next;
    while(tmp != NULL)
    {
        printf("%c",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void DispArr(char *arr,int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%c\t",*(arr+i));
    }
    printf("\n");
}

void StrCopy(strLink *str,int length,char *s)
{
    int i = 0;
    strLink * tmp = str->next;
    while(tmp != NULL)
    {
        *(s+i) = tmp->data;
        i++;
        tmp = tmp->next;
    }
}

bool isPalindrome(char * s)
{
    //  求出长度
    strLink *str;
    str = StrAssign(s);
    // DispStr(str);
    int length = StrLength(str);
    if(length <= 1) return true;
    char strArr[length];

    //  构造字符数组
    StrCopy(str,length,&strArr[0]);
    // DispArr(&strArr[0],length);

    //  验证
    int i=0,j=length-1;
    while(i < j)
    {
        if(strArr[i] != strArr[j])
            return false;
        i++;
        j--;
    }
    return true;
}