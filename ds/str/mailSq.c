#include <stdio.h>
#include <malloc.h>

#define MaxSize 100             //最多的字符个数
#define True 1
#define False 0

typedef int Bool;
typedef struct
{   char data[MaxSize];         //定义可容纳MaxSize个字符的空间
    int length;                 //标记当前实际串长
} SqString;

void StrAssign(SqString **s,char cstr[]);    //字符串常量cstr赋给串s
void StrCopy(SqString **s,SqString t);   //串t复制给串s
Bool StrEqual(SqString s,SqString t); //判串相等
int StrLength(SqString *s);  //求串长
SqString Concat(SqString s,SqString t);  //串连接
SqString SubStr(SqString s,int i,int j); //求子串
SqString InsStr(SqString s1,int i,SqString s2); //串插入
SqString DelStr(SqString s,int i,int j) ;   //串删去
SqString RepStr(SqString s,int i,int j,SqString t);     //串替换
void DispStr(SqString s);   //输出串

SqString Concat(SqString s,SqString t)
{
    int k,l;
    SqString tmp;
    tmp.length = 0;
    for(k=0;k<s.length;k++)
        tmp.data[k] = s.data[k];

    for(k=0;k<t.length;k++)
        tmp.data[s.length+k] = t.data[k];

    tmp.length = s.length + t.length;
    return tmp;
}

SqString SubStr(SqString s,int i,int j)
{
    int k,l;
    SqString tmp;
    tmp.length = 0;
    if(i+j-2 > s.length)
        return tmp;
    for(k=i-1,l=0;l<j;l++,k++)
        tmp.data[l] = s.data[k];

    tmp.length = j;
    return tmp;
}

SqString RepStr(SqString s,int i,int j,SqString t)
{
    int k,l;
    SqString tmp;
    tmp.length = 0;

    if(i+j-1 > s.length)
        return tmp;

    for(k=0,l=0;k<i-1;k++,l++)
        tmp.data[l] = s.data[k];

    for(k=0;k<t.length;k++,l++)
        tmp.data[l] = t.data[k];

    for(k=i+j-1;k<s.length;k++,l++)
        tmp.data[l] = s.data[k];

    tmp.length = s.length-j+t.length;
    return tmp;
}

int main()
{
    SqString *s,*s1,s2,s3,s4,s5;
    printf("串的基本运算如下:\n");
    printf("  (1)建立串s和串s1\n");
    StrAssign(&s,"abcdefghijklmn");
    printf("  (2)输出串s:");
    DispStr(*s);
    StrAssign(&s1,"123");
    printf("  (2)输出串s1:");
    DispStr(*s1);
    printf("  (3)串s的长度:%d\n",StrLength(s));
    printf("  (4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2=InsStr(*s,9,*s1);
    printf("  (5)输出串s2:");
    DispStr(s2);
    printf("  (6)删除串s第2个字符开始的5个字符而产生串s2\n");
    s2=DelStr(*s,2,5);
    printf("  (7)输出串s2:");
    DispStr(s2);
    printf("  (8)将串s第2个字符开始的5个字符替换成串s1而产生串s2\n");
    s2=RepStr(*s,2,5,*s1);
    printf("  (9)输出串s2:");
    DispStr(s2);
    printf("  (10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3=SubStr(*s,2,10);
    printf("  (11)输出串s3:");
    DispStr(s3);
    DispStr(*s1);
    DispStr(s2);
    printf("  (12)将串s1和串s2连接起来而产生串s4\n");
    s4=Concat(*s1,s2);
    printf("  (13)输出串s4:");
    DispStr(s4);
    return 0;
}

void StrAssign(SqString **s,char cstr[])
{
    *s = (SqString *)malloc(sizeof(SqString));
    int i = 0;
    while (cstr[i] != '\0')
    {
        (*s)->data[i] = cstr[i];
        i++;
    }
    (*s)->length = i;
}

void DispStr(SqString s)
{
    for (int i = 0; i < s.length; i++)
    {
        printf("%c ",s.data[i]);
    }
    printf("\n");
}

int StrLength(SqString *s)
{
    return s->length;
}

SqString InsStr(SqString s1,int i,SqString s2)
{
    int j,k;
    SqString tmp ;
    tmp.length = 0;

    if(i <= 0 || i >= s1.length)
        return tmp;
    if(s1.length + s2.length > MaxSize )
        return tmp;

    for ( j = 0; j < i; j++)
        tmp.data[j] = s1.data[j];
    for ( k = 0; k < s2.length; k++)
        tmp.data[j+k] = s2.data[k];    

    for ( j = i; j < s1.length; j++)
        tmp.data[j+s2.length] = s1.data[j];

    tmp.length = s1.length + s2.length;
    return tmp;
}


SqString DelStr(SqString s,int i,int j)
{
    int k,l;
    SqString tmp;
    tmp.length = 0;

    if (i+j-1 > s.length)
        return tmp;
    
    for ( k = 0,l = 0; k < i-1; k++,l++)
        tmp.data[l] = s.data[k];
    
    for ( k = i+j-1; k < s.length; k++,l++)
        tmp.data[l] = s.data[k];
    
    tmp.length = s.length-j;
    return tmp;
}