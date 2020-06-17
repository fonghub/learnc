#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int Bool;
typedef struct node
{
    char data;
    struct node *next;
} strLink;

strLink * InitStr();                                    //初始化串
void StrAssign(strLink *s,char cstr[]);                 //字符串常量cstr赋给串s
void DispStr(strLink *s);                               //输出串
int StrLength(strLink *s);                              //求串长
strLink * InsStr(strLink *s,int i,strLink *t);          //串插入
strLink * DelStr(strLink *s,int i,int j);               //串删去
strLink * RepStr(strLink *s,int i,int j,strLink *t);    //串替换
strLink * SubStr(strLink *s,int i,int j);               //求子串
strLink * Concat(strLink *s,strLink *t);                //串连接
strLink * StrCopy(strLink *s);                          //复制串s，返回新串
Bool StrEqual(strLink *s,strLink *t);                   //判串相等

int main()
{
    strLink *s,*s1,*s2,*s3,*s4,*s5;
    printf("链串的基本运算如下:\n");
    printf("  (1)建立串s和串s1\n");
    s = InitStr();
    StrAssign(s,"abcdefghijklmn");
    printf("  (2)输出串s:");
    DispStr(s);
    s1 = InitStr();
    StrAssign(s1,"123");
    printf("  (2)输出串s1:");
    DispStr(s1);
    printf("  (3)串s的长度:%d\n",StrLength(s));
    printf("  (4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2 = InsStr(s,9,s1);
    printf("  (5)输出串s2:");
    DispStr(s2);
    printf("  (6)删除串s第2个字符开始的5个字符而产生串s2\n");
    s2=DelStr(s,2,5);
    printf("  (7)输出串s2:");
    DispStr(s2);
    printf("  (8)将串s第2个字符开始的5个字符替换成串s1而产生串s2\n");
    s2 = RepStr(s,2,5,s1);
    printf("  (9)输出串s2:");
    DispStr(s2);
    printf("  (10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3 = SubStr(s,2,10);
    printf("  (11)输出串s3:");
    DispStr(s3);
    printf("  (12)将串s和串s1连接起来而产生串s4\n");
    s4 = Concat(s,s1);
    printf("  (13)输出串s4:");
    DispStr(s4);

    printf("  (14)复制串s返回s5\n");
    s5 = StrCopy(s);
    printf("  (15)输出串s5:");
    DispStr(s5);

    printf("  (16)比较串s和s5\n");
    if(StrEqual(s,s5))
        printf("  (17)串s和s5相等");
    else
        printf("  (17)串s和s5不相等");
    return 0;
}

strLink * InitStr()
{
    strLink *tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;
    return tmp;
}

void StrAssign(strLink *s,char cstr[])
{
    int i = 0;
    strLink *tmp,*p;
    p = s;
    while(cstr[i] != '\0')
    {
        tmp = (strLink *)malloc(sizeof(strLink));
        tmp->data = cstr[i];
        p->next = tmp;
        p = tmp;
        i++;
    }
    p->next = NULL;
}

void DispStr(strLink *s)
{
    strLink *tmp = s->next;
    while (tmp != NULL)
    {
        printf("%c ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int StrLength(strLink *s)
{
    strLink *tmp = s->next;
    int i = 0;
    while (tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

strLink * InsStr(strLink *s,int i,strLink *t)
{
    strLink *tmp,*p1=s->next,*p2=t->next,*q,*r;
    int j;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;
    i--;    //  逻辑顺序转物理顺序
    if(i < 0 || i > StrLength(s))
        return tmp;

    r = tmp;
    for ( j = 0; j < i; j++)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    while(p2 != NULL)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p2->data;
        r->next = q;
        r = q;
        p2 = p2->next;
    }
    for ( j = i; j < StrLength(s); j++)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    r->next = NULL;
    
    return tmp;  
}

strLink *DelStr(strLink *s,int i,int j)
{
    strLink *tmp,*r,*q,*p = s->next;
    int k=0;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;

    if(i+j-1 > StrLength(s))
        return tmp;
    r = tmp;
    i--;
    while (k < i)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
        k++;
    }

    while (k < i+j){
        p = p->next;
        k++;
    }
    
    while ( k < StrLength(s))
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;  
        k++;    
    }
    r->next = NULL;
    return tmp;
}


strLink *RepStr(strLink *s,int i,int j,strLink *t)
{
    strLink *tmp,*r,*q,*p1=s->next,*p2=t->next;
    int k = 0;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;

    if(i+j-1 > StrLength(s))
        return tmp;
    r = tmp;
    i--;
    while (k < i)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
        k++;
    }

    while (p2 != NULL)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p2->data;
        r->next = q;
        r = q;
        p2 = p2->next;
    }

    while (k < i+j)
    {
        p1 = p1->next;
        k++;
    }

    while ( k < StrLength(s))
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;  
        k++;    
    }
    r->next = NULL;

    return tmp;   
}

strLink * SubStr(strLink *s,int i,int j)
{
    int k = 0;
    strLink *tmp,*p = s->next,*r,*q;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;

    if(i-1+j > StrLength(s))
        return tmp;
    r = tmp;
    i--;
    while (k < i)
    {
        p = p->next;
        k++;
    }

    while (k < i+j)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
        k++;
    }
    r->next = NULL;
    return tmp; 
}

strLink * Concat(strLink *s,strLink *t)
{
    strLink *tmp,*r,*q,*p1 =s->next,*p2=t->next;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;

    r = tmp;
    while (p1 != NULL)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p2->data;
        r->next = q;
        r = q;
        p2 = p2->next;
    }
    r->next = NULL;
    return tmp;
}

//   复制串s，返回新串
strLink * StrCopy(strLink *s)
{
    strLink *tmp,*r,*q,*p1=s->next;
    tmp = (strLink *)malloc(sizeof(strLink));
    tmp->next = NULL;

    r = tmp;
    while (p1 != NULL)
    {
        q = (strLink *)malloc(sizeof(strLink));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    
    return tmp;
}

//  串相等
Bool StrEqual(strLink *s,strLink *t)
{
    strLink *p1=s->next,*p2=t->next;
    if(StrLength(s) != StrLength(t))
        return false;

    while (p1 != NULL)
    {
        if(p1->data != p2->data)
            return false;

        p1=p1->next;
        p2=p2->next;
    }
    return true;
}