#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int Bool;
typedef struct snode
{
    char data;
    struct snode *next;
} LiString;

void StrAssign(LiString **s,char cstr[]);   //字符串常量cstr赋给串s
void StrCopy(LiString **s,LiString *t); //串t复制给串s
Bool StrEqual(LiString *s,LiString *t); //判串相等
int StrLength(LiString s); //求串长
LiString *Concat(LiString s,LiString t);  //串连接
LiString *SubStr(LiString s,int i,int j);  //求子串
LiString *InsStr(LiString s,int i,LiString t);   //串插入
LiString *DelStr(LiString s,int i,int j);  //串删去
LiString *RepStr(LiString s,int i,int j,LiString t);  //串替换
void DispStr(LiString s);  //输出串

int main()
{
    LiString *s,*s1,*s2,*s3,*s4;
    printf("链串的基本运算如下:\n");
    printf("  (1)建立串s和串s1\n");
    StrAssign(&s,"abcdefghijklmn");
    printf("  (2)输出串s:");
    DispStr(*s);
    StrAssign(&s1,"123");
    printf("  (2)输出串s1:");
    DispStr(*s1);
    printf("  (3)串s的长度:%d\n",StrLength(*s));
    printf("  (4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2=InsStr(*s,9,*s1);
    printf("  (5)输出串s2:");
    DispStr(*s2);
    printf("  (6)删除串s第2个字符开始的5个字符而产生串s2\n");
    s2=DelStr(*s,2,3);
    printf("  (7)输出串s2:");
    DispStr(*s2);
    printf("  (8)将串s第2个字符开始的5个字符替换成串s1而产生串s2\n");
    s2=RepStr(*s,2,5,*s1);
    printf("  (9)输出串s2:");
    DispStr(*s2);
    printf("  (10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3=SubStr(*s,2,10);
    printf("  (11)输出串s3:");
    DispStr(*s3);
    printf("  (12)将串s1和串s2连接起来而产生串s4\n");
    s4=Concat(*s1,*s2);
    printf("  (13)输出串s4:");
    DispStr(*s4);
    return 0;
}


LiString *DelStr(LiString s,int i,int j)
{
    LiString *str,*r,*q,*p = s.next;
    int k=0;
    str = (LiString *)malloc(sizeof(LiString));
    str->next = NULL;

    if(i+j-1 > StrLength(s))
        return str;
    r = str;
    while (k < i-1)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
        k++;
    }

    while (k < i+j-1){
        p = p->next;
        k++;
    }
    
    while ( k < StrLength(s))
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;  
        k++;    
    }
    r->next = NULL;
    return str;
}

LiString *InsStr(LiString s,int i,LiString t)
{
    LiString *str,*p1=s.next,*p2=t.next,*q,*r;
    int j;
    str = (LiString *)malloc(sizeof(LiString));
    str->next = NULL;

    if(i <= 0 || i > StrLength(s))
        return str;

    r = str;
    for ( j = 0; j < i; j++)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    while(p2 != NULL)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p2->data;
        r->next = q;
        r = q;
        p2 = p2->next;
    }
    for ( j = i; j < StrLength(s); j++)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    r->next = NULL;
    
    return str;  
}

int StrLength(LiString s)
{
    LiString *tmp = s.next;
    int i = 0;
    while (tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

void DispStr(LiString s)
{
    LiString *tmp = s.next;
    while (tmp != NULL)
    {
        printf("%c ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void StrAssign(LiString **s,char cstr[])
{
    int i = 0;
    LiString *tmp,*p;
    *s = (LiString *)malloc(sizeof(LiString));
    p = (*s);
    while(cstr[i] != '\0')
    {
        tmp = (LiString *)malloc(sizeof(LiString));
        tmp->data = cstr[i];
        p->next = tmp;
        p = tmp;
        i++;
    }
    p->next = NULL;
}


LiString *Concat(LiString s,LiString t)
{
    LiString *str,*r,*q,*p1 =s.next,*p2=t.next;
    str = (LiString *)malloc(sizeof(LiString));
    r = str;
    while (p1 != NULL)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p2->data;
        r->next = q;
        r = q;
        p2 = p2->next;
    }
    r->next = NULL;
    return str;
}

LiString *SubStr(LiString s,int i,int j)
{
    int k = 0;
    LiString *str,*p = s.next,*r,*q;
    str = (LiString *)malloc(sizeof(LiString));
    r = str;
    while (k < i-1)
    {
        p = p->next;
        k++;
    }

    while (k < i+j-1)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
        k++;
    }
    r->next = NULL;
    return str; 
}

LiString *RepStr(LiString s,int i,int j,LiString t)
{
    LiString *str,*r,*q,*p1=s.next,*p2=t.next;
    int k = 0;
    str = (LiString *)malloc(sizeof(LiString));
    r = str;
    while (k < i-1)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
        k++;
    }
    while (p2 != NULL)
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p2->data;
        r->next = q;
        r = q;
        p2 = p2->next;
    }

    while (k < i+j-1)
    {
        p1 = p1->next;
        k++;
    }

    while ( k < StrLength(s))
    {
        q = (LiString *)malloc(sizeof(LiString));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;  
        k++;    
    }
    r->next = NULL;

    return str;   
}