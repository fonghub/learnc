#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100          
#define true 1
#define false 0

typedef int Bool;
typedef struct
{   char data[MaxSize];         
    int length;                 
} strSeq;

strSeq * InitStr();                                 //  初始化串
void StrAssign(strSeq *s,char cstr[]);              //  字符串常量cstr赋给串s
void DispStr(strSeq *s);                            //  输出串
strSeq * InsStr(strSeq *s,int i,strSeq *s1);        //  串插入
void StrCopy(strSeq *s,strSeq *t);                  //  串t复制给串s
Bool StrEqual(strSeq *s,strSeq *t);                 //  判串相等
int StrLength(strSeq *s);                           //  求串长
strSeq * Concat(strSeq *s,strSeq *t);               //  串连接
strSeq * SubStr(strSeq *s,int i,int j);             //  求子串
strSeq * DelStr(strSeq *s,int i,int j) ;            //  串删去
strSeq * RepStr(strSeq *s,int i,int j,strSeq *t);   //  串替换


int main()
{
    strSeq *s,*s1,*s2,*s3,*s4;
    printf("串的基本运算如下:\n");
    printf("  (0)初始化串s:\n");
    s = InitStr();
    char cstr[] = "abcdefghijklmn";
    printf("  (1)字符串 %s 赋值给s\n",cstr);
    StrAssign(s,cstr);
    printf("  (2)输出串s:");
    DispStr(s);
    printf("  (0)初始化串s1:\n");
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
    s2 = DelStr(s,2,5);
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
    printf("  (12)将串s1和串s2连接起来而产生串s4\n");
    s4 = Concat(s,s1);
    printf("  (13)输出串s4:");
    DispStr(s4);
    return 0;
}

strSeq * InitStr()
{
    strSeq *tmp = (strSeq *)malloc(sizeof(strSeq));
    tmp->length = 0;
    return tmp;
}

void StrAssign(strSeq *s,char cstr[])
{
    int i = 0;
    while (cstr[i] != '\0')
    {
        s->data[i] = cstr[i];
        i++;
    }
    s->length = i;
}

strSeq * InsStr(strSeq *s,int i,strSeq *s1)
{
    int j,k;
    strSeq *tmp  = (strSeq *)malloc(sizeof(strSeq));
    tmp->length = 0;
    i--;
    if(i < 0 || i > s->length)
        return tmp;
    if(s->length + s1->length > MaxSize)
        return tmp;

    for ( j = 0; j < i; j++)
        tmp->data[j] = s->data[j];
    for ( k = 0; k < s1->length; k++)
        tmp->data[j+k] = s1->data[k];    

    for ( j = i; j < s->length; j++)
        tmp->data[j+s1->length] = s->data[j];

    tmp->length = s->length + s1->length;
    return tmp;
}

void DispStr(strSeq *s)
{
    for (int i = 0; i < s->length; i++)
    {
        printf("%c ",s->data[i]);
    }
    printf("\n");
}


strSeq * Concat(strSeq *s,strSeq *t)
{
    int k,l;
    strSeq *tmp  = (strSeq *)malloc(sizeof(strSeq));
    tmp->length = 0;

    for(k=0;k<s->length;k++)
        tmp->data[k] = s->data[k];

    for(k=0;k<t->length;k++)
        tmp->data[s->length+k] = t->data[k];

    tmp->length = s->length + t->length;
    return tmp;
}


int StrLength(strSeq *s)
{
    return s->length;
}

strSeq * SubStr(strSeq *s,int i,int j)
{
    int k,l;
    strSeq *tmp = (strSeq *)malloc(sizeof(strSeq));
    tmp->length = 0;

    if(i+j-1 > s->length)
        return tmp;
    i--;
    for(k=i,l=0;l<j;l++,k++)
        tmp->data[l] = s->data[k];

    tmp->length = j;
    return tmp;
}

strSeq * RepStr(strSeq *s,int i,int j,strSeq *t)
{
    int k,l;
    strSeq *tmp = (strSeq *)malloc(sizeof(strSeq));
    tmp->length = 0;

    if(i+j-1 > s->length)
        return tmp;
    i--;
    for(k=0,l=0;k<i;k++,l++)
        tmp->data[l] = s->data[k];

    for(k=0;k<t->length;k++,l++)
        tmp->data[l] = t->data[k];

    for(k=i+j;k<s->length;k++,l++)
        tmp->data[l] = s->data[k];

    tmp->length = s->length-j+t->length;
    return tmp;
}

strSeq * DelStr(strSeq *s,int i,int j)
{
    int k,l;
    strSeq *tmp = (strSeq *)malloc(sizeof(strSeq));
    tmp->length = 0;
    //  元素数量不够，返回空
    if (i+j-1 > s->length)
        return tmp;
    i--;
    for ( k = 0,l = 0; k < i; k++,l++)
        tmp->data[l] = s->data[k];
    
    for ( k = i+j; k < s->length; k++,l++)
        tmp->data[l] = s->data[k];
    
    tmp->length = s->length-j;
    return tmp;
}